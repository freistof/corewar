/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opcode_one.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 13:38:55 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/19 16:27:18 by lvan-vlo      ########   odam.nl         */
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
	// ft_printf("LIVE ARG: %d\tREGISTRY [0]: %d\n", arg, cursor->registry[0]);
	if ((arg * -1) > 0 && (arg * -1) <= game->num_players)
	{
		game->last_reported_live = arg * -1;
		// game->last_reported_live = cursor->registry[0];
		// ft_printf("A process shows that player %d (%s) is alive\n", arg * -1, \
		game->players[(arg * - 1) - 1]->name);
	}
	cursor->jump = 5;
}

void		op_store(t_game *game, t_cursor *cursor)
{
	t_op_args		*op_args;
	int				value;
	unsigned char	*byte;

	op_args = get_op_args(cursor, game->board, 2);
	if (check_arg_types(op_args, ARG_REG, ARG_REG_OR_IND, ARG_NOTHING))
	{
		value = get_arg_value(op_args->arg2_type, op_args->arg2_value, cursor, game->board);
		byte = int_to_byte(cursor->registry[op_args->arg1_value - 1]);
		write_to_board(game->board, cursor->position + (value % IDX_MOD), byte);
		free(byte);
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
		value = cursor->registry[args->arg1_value - 1] + cursor->registry[args->arg2_value - 1];
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
		value = cursor->registry[args->arg1_value - 1] - cursor->registry[args->arg2_value - 1];
		cursor->registry[args->arg3_value - 1] = value;
		if (value == 0)
			cursor->carry = true;
		else
			cursor->carry = false;
	}
	ft_memdel((void **)&args);
}
