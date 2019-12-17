/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opcode_one.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 13:38:55 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/17 14:39:20 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

/*
** LIVE, STORE, ADD, SUBTRACT
*/

void		op_live(t_game *game, t_cursor *cursor)
{
	int arg;

	arg = byte_to_int(game->board, cursor->position + 1);
	cursor->last_live = game->cycle_counter;
	game->num_lives_reported += 1;
	if ((arg * -1) > 0 && (arg * -1) <= game->num_players && \
	game->players[arg * -1 - 1]->alive == true)
	{
		game->last_reported_live = arg * -1;
		game->players[arg * -1 - 1]->last_reported_live = game->cycle_counter;
	}
	cursor->jump = 5;
}

void		op_store(t_game *game, t_cursor *cursor)
{
	t_op_args		*op_args;
	unsigned char	*byte;

	op_args = get_op_args(cursor, game->board, 4);
	if (check_arg_types(op_args, ARG_REG, ARG_REG_OR_IND, ARG_NOTHING))
	{
		if (op_args->arg2_type == T_REG)
			cursor->registry[op_args->arg2_value - 1] = \
			get_arg_value(op_args->arg1_type, op_args->arg1_value, \
			cursor, game->board);
		else
		{
			byte = int_to_byte(cursor->registry[op_args->arg1_value - 1]);
			write_to_board(game->board, cursor->position,
			op_args->arg2_value % IDX_MOD, byte);
			if (game->vis)
				update_visual_field(game, cursor->position + \
				(op_args->arg2_value % IDX_MOD), cursor->id);
			free(byte);
		}
	}
	ft_memdel((void **)&op_args);
}

void		op_add(t_game *game, t_cursor *cursor)
{
	t_op_args	*args;
	int			value;

	args = get_op_args(cursor, game->board, 4);
	if (check_arg_types(args, ARG_REG, ARG_REG, ARG_REG))
	{
		value = cursor->registry[args->arg1_value - 1] + \
		cursor->registry[args->arg2_value - 1];
		cursor->registry[args->arg3_value - 1] = value;
		if (value == 0)
			cursor->carry = true;
		else
			cursor->carry = false;
	}
	ft_memdel((void **)&args);
}

void		op_subtract(t_game *game, t_cursor *cursor)
{
	t_op_args	*args;
	int			value;

	args = get_op_args(cursor, game->board, 4);
	if (check_arg_types(args, ARG_REG, ARG_REG, ARG_REG))
	{
		value = cursor->registry[args->arg1_value - 1] - \
		cursor->registry[args->arg2_value - 1];
		cursor->registry[args->arg3_value - 1] = value;
		if (value == 0)
			cursor->carry = true;
		else
			cursor->carry = false;
	}
	ft_memdel((void **)&args);
}
