/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opcode_one.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 13:38:55 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/16 14:22:24 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		live(t_game *game, t_cursor *cursor)
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

void		load(t_game *game, t_cursor *cursor)
{
	t_op_args	*op_args;
	int			to_read;
	int			x;

	op_args = get_op_args(cursor, game->board);
	if (op_args->arg1_type == T_REG || op_args->arg2_type != T_REG || op_args->arg3_type != 0)
	{
		ft_memdel((void **)&op_args);
		return ;
	}
	if (op_args->arg1_type == T_DIR)
		cursor->registry[op_args->arg2_value] = op_args->arg1_value;
	else if (op_args->arg1_type == T_IND)
	{
		to_read = 0;
		x = 0;
		while (x < 4)
		{
			to_read += game->board[(cursor->position + (op_args->arg1_value % IDX_MOD) % MEM_SIZE)];
			cursor->position += 1;
			x++;
		}
		cursor->registry[op_args->arg2_value] = to_read;
		if (to_read == 0)
			cursor->carry = true;
		else
			cursor->carry = false;
	}
}

void		store(t_game *game, t_cursor *cursor)
{
	t_op_args	*op_args;

	op_args = get_op_args(cursor, game->board);
	if (op_args->arg1_type != T_REG || op_args->arg2_type == T_DIR || op_args->arg3_type != 0)
	{
		ft_memdel((void **)&op_args);
		return ;
	}
	if (op_args->arg2_type == T_REG)
		cursor->registry[op_args->arg2_value] = cursor->registry[op_args->arg1_value];
	else
		game->board[cursor->position + (op_args->arg2_value % IDX_MOD) % MEM_SIZE] = cursor->registry[op_args->arg1_value];
}

void		add(t_game *game, t_cursor *cursor)
{
	t_op_args	*op_args;
	int			value;

	op_args = get_op_args(cursor, game->board);
	if (op_args->arg1_type != T_REG || op_args->arg2_type != T_REG || op_args->arg3_type != T_REG)
	{
		ft_memdel((void **)&op_args);
		return ;
	}
	value = cursor->registry[op_args->arg1_value] + cursor->registry[op_args->arg2_value];
	cursor->registry[op_args->arg3_value] = value;
	if (value == 0)
		cursor->carry = true;
	else
		cursor->carry = false;
}

void		subtract(t_game *game, t_cursor *cursor)
{
	t_op_args	*op_args;
	int			value;

	op_args = get_op_args(cursor, game->board);
	if (op_args->arg1_type != T_REG || op_args->arg2_type != T_REG || op_args->arg3_type != T_REG)
	{
		ft_memdel((void **)&op_args);
		return ;
	}
	value = cursor->registry[op_args->arg1_value] - cursor->registry[op_args->arg2_value];
	cursor->registry[op_args->arg3_value] = value;
	if (value == 0)
		cursor->carry = true;
	else
		cursor->carry = false;
}