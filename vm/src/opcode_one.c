/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opcode_one.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 13:38:55 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/18 16:00:37 by lvan-vlo      ########   odam.nl         */
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
	if (cursor->registry[0] == arg)
		game->last_reported_live = cursor->registry[0];
	game->num_lives_reported += 1;
	arg *= -1;
	if (arg > 0 && arg < game->num_players)
		ft_printf("A process shows that player %d (%s) is alive\n", arg, \
		game->players[arg - 1]->name);
}

void		op_store(t_game *game, t_cursor *cursor)
{
	t_op_args	*args;

	args = get_op_args(cursor, game->board);
	if (check_arg_types(args, ARG_REG, ARG_REG_OR_IND, ARG_NOTHING))
	{
		if (args->arg2_type == T_REG)
			cursor->registry[args->arg2_value - 1] = cursor->registry[args->arg1_value - 1];
		else
			game->board[cursor->position + (args->arg2_value % IDX_MOD) % MEM_SIZE] = cursor->registry[args->arg1_value - 1];
	}
	ft_memdel((void **)&args);
}

void		op_add(t_game *game, t_cursor *cursor)
{
	t_op_args	*args;
	int			value;

	args = get_op_args(cursor, game->board);
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

	args = get_op_args(cursor, game->board);
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
