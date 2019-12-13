/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opcode_four.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 12:23:05 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/12/12 13:35:13 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

void		op_load(t_game *game, t_cursor *cursor)
{
	t_op_args	*op_args;

	op_args = get_op_args(cursor, game->board, 4);
	if (check_arg_types(op_args, ARG_DIR_OR_IND, ARG_REG, ARG_NOTHING))
	{
		cursor->registry[op_args->arg2_value - 1] = \
		get_arg_value(op_args->arg1_type, op_args->arg1_value, \
		cursor, game->board);
		if (cursor->registry[op_args->arg2_value - 1] == 0)
			cursor->carry = true;
		else
			cursor->carry = false;
	}
	ft_memdel((void **)&op_args);
}

void		op_loadi(t_game *game, t_cursor *cursor)
{
	t_op_args	*op_args;
	int			address;

	op_args = get_op_args(cursor, game->board, 2);
	if (check_arg_types(op_args, ARG_ANY, ARG_REG_OR_DIR, ARG_REG))
	{
		address = get_arg_value(op_args->arg1_type, op_args->arg1_value, \
		cursor, game->board);
		address += get_arg_value(op_args->arg2_type, op_args->arg2_value, \
		cursor, game->board);
		address = get_arg_value(T_IND, address, cursor, game->board);
		cursor->registry[op_args->arg3_value - 1] = address;
	}
	ft_memdel((void **)&op_args);
}

void		op_lload(t_game *game, t_cursor *cursor)
{
	t_op_args	*op_args;

	op_args = get_op_args(cursor, game->board, 4);
	if (check_arg_types(op_args, ARG_DIR_OR_IND, ARG_REG, ARG_NOTHING))
	{
		if (op_args->arg1_type == T_IND)
			cursor->registry[op_args->arg2_value - 1] = \
			byte_to_int(game->board, cursor->position + \
			op_args->arg1_value);
		else
			cursor->registry[op_args->arg2_value - 1] = op_args->arg1_value;
		if (cursor->registry[op_args->arg2_value - 1] == 0)
			cursor->carry = true;
		else
			cursor->carry = false;
	}
	ft_memdel((void **)&op_args);
}

void		op_lloadi(t_game *game, t_cursor *cursor)
{
	t_op_args	*op_args;
	int			address;

	op_args = get_op_args(cursor, game->board, 2);
	if (check_arg_types(op_args, ARG_ANY, ARG_REG_OR_DIR, ARG_REG))
	{
		if (op_args->arg1_type == T_IND)
			address = byte_to_int(game->board, cursor->position + \
			op_args->arg1_value);
		else
			address = get_arg_value(op_args->arg1_type, \
			op_args->arg1_value, cursor, game->board);
		address += get_arg_value(op_args->arg2_type, op_args->arg2_value, \
		cursor, game->board);
		address = byte_to_int(game->board, cursor->position + address);
		cursor->registry[op_args->arg3_value - 1] = address;
		if (address == 0)
			cursor->carry = true;
		else
			cursor->carry = false;
	}
	ft_memdel((void **)&op_args);
}

void		op_storei(t_game *game, t_cursor *cursor)
{
	t_op_args		*op_args;
	int				value;
	unsigned char	*byte;

	op_args = get_op_args(cursor, game->board, 2);
	if (check_arg_types(op_args, ARG_REG, ARG_ANY, ARG_REG_OR_DIR))
	{
		value = get_arg_value(op_args->arg2_type, op_args->arg2_value, \
		cursor, game->board);
		value += get_arg_value(op_args->arg3_type, op_args->arg3_value, \
		cursor, game->board);
		byte = int_to_byte(cursor->registry[op_args->arg1_value - 1]);
		write_to_board(game->board, cursor->position + (value % IDX_MOD), byte);
		if (game->vis)
			update_visual_field(game, cursor->position + (value % IDX_MOD), \
			cursor->id);
		free(byte);
	}
	ft_memdel((void **)&op_args);
}
