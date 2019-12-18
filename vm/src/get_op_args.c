/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_op_args.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 16:36:51 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/18 17:19:04 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

int			get_arg_value(int arg_type, int arg_value, t_cursor *cursor, \
unsigned char *board)
{
	if (arg_type == T_DIR)
		return (arg_value);
	else if (arg_type == T_REG)
		return (cursor->registry[arg_value - 1]);
	else if (arg_type == T_IND)
	{
		return (byte_to_int(board, cursor->position + (arg_value % \
		IDX_MOD) % MEM_SIZE));
	}
	return (0);
}

static void	get_encoding_bits(t_op_args *args, int position, \
unsigned char *board)
{
	int second_arg;
	int	third_arg;

	args->arg1_type = board[position] >> 6;
	second_arg = board[position] >> 4;
	if ((second_arg & T_IND) == T_IND)
		args->arg2_type = T_IND;
	else if ((second_arg & T_DIR) == T_DIR)
		args->arg2_type = T_DIR;
	else if ((second_arg & T_REG) == T_REG)
		args->arg2_type = T_REG;
	third_arg = board[position] >> 2;
	if ((third_arg & T_IND) == T_IND)
		args->arg3_type = T_IND;
	else if ((third_arg & T_DIR) == T_DIR)
		args->arg3_type = T_DIR;
	else if ((third_arg & T_REG) == T_REG)
		args->arg3_type = T_REG;
}

int			get_arg(int arg_type, unsigned char *board, int *position, \
int dir_size)
{
	int rtn;
	int x;

	x = 0;
	rtn = 0;
	if (arg_type == T_IND || (arg_type == T_DIR && dir_size == 2))
	{
		rtn = (short)byte_to_hex(board, *position);
		*position += 2;
	}
	else if (arg_type == T_DIR)
	{
		rtn = byte_to_int(board, *position);
		*position += 4;
	}
	else if (arg_type == T_REG)
	{
		rtn += board[(*position % MEM_SIZE)];
		*position += 1;
	}
	return (rtn);
}

t_op_args	*get_op_args(t_cursor *cursor, unsigned char *board, \
int dir_size)
{
	t_op_args	*args;
	int			args_position;
	int			x;

	args_position = cursor->position + 1;
	args = (t_op_args *)ft_memalloc(sizeof(t_op_args));
	if (!args)
		exit(1);
	get_encoding_bits(args, args_position, board);
	args_position += 1;
	x = 0;
	args->arg1_value = get_arg(args->arg1_type, board, &args_position, \
	dir_size);
	args->arg2_value = get_arg(args->arg2_type, board, &args_position, \
	dir_size);
	args->arg3_value = get_arg(args->arg3_type, board, &args_position, \
	dir_size);
	cursor->jump = args_position - cursor->position;
	return (args);
}
