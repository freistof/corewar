/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opcode_two.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 12:57:09 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/11/19 14:17:26 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

void        op_and(t_game *game, t_cursor *cursor)
{
    t_op_args   *op_args;
    int         value1;
    int         value2;

    op_args = get_op_args(cursor, game->board, 4);
    if (check_arg_types(op_args, ARG_ANY, ARG_ANY, ARG_REG))
    {
		value1 = get_arg_value(op_args->arg1_type, op_args->arg1_value, cursor, game->board);
		value2 = get_arg_value(op_args->arg2_type, op_args->arg2_value, cursor, game->board);
		cursor->registry[op_args->arg3_value - 1] = value1 & value2;
		if (cursor->registry[op_args->arg3_value - 1] == 0)
			cursor->carry = true;
		else
			cursor->carry = false;
	}
	ft_memdel((void **)&op_args);
}

void        op_or(t_game *game, t_cursor *cursor)
{
	t_op_args   *op_args;
	int         value1;
	int         value2;

	op_args = get_op_args(cursor, game->board, 4);
	if (check_arg_types(op_args, ARG_ANY, ARG_ANY, ARG_REG))
	{
		value1 = get_arg_value(op_args->arg1_type, op_args->arg1_value, cursor, game->board);
		value2 = get_arg_value(op_args->arg2_type, op_args->arg2_value, cursor, game->board);
		cursor->registry[op_args->arg3_value - 1] = value1 | value2;
		if (cursor->registry[op_args->arg3_value - 1] == 0)
			cursor->carry = true;
		else
			cursor->carry = false;
	}
	ft_memdel((void **)&op_args);
}

void        op_xor(t_game *game, t_cursor *cursor)
{
	t_op_args   *op_args;
	int         value1;
	int         value2;

	op_args = get_op_args(cursor, game->board, 4);
	if (check_arg_types(op_args, ARG_ANY, ARG_ANY, ARG_REG))
	{
		value1 = get_arg_value(op_args->arg1_type, op_args->arg1_value, cursor, game->board);
		value2 = get_arg_value(op_args->arg2_type, op_args->arg2_value, cursor, game->board);
		cursor->registry[op_args->arg3_value - 1] = value1 ^ value2;
		if (cursor->registry[op_args->arg3_value - 1] == 0)
			cursor->carry = true;
		else
			cursor->carry = false;
	}
	ft_memdel((void **)&op_args);
}
