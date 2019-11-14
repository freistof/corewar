/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_op_args.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/14 16:36:51 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/14 17:22:45 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	get_encoding_bits(t_op_args *args, int position, \
unsigned char *board)
{
	int first_arg;
	int second_arg;
	int	third_arg;

	args->arg1_type = board[position] >> 6;
	second_arg = board[position] >> 4;
	if (second_arg & T_IND == T_IND)
		args->arg2_type = T_IND;
	else if (second_arg & T_DIR == T_DIR)
		args->arg2_type = T_DIR;
	else if (second_arg & T_REG == T_REG)
		args->arg2_type = T_REG;
	third_arg = board[position] >> 2;
	if (third_arg & T_IND == T_IND)
		args->arg3_type = T_IND;
	else if (third_arg & T_DIR == T_DIR)
		args->arg3_type = T_DIR;
	else if (third_arg & T_REG == T_REG)
		args->arg3_type = T_REG;
}

int			get_arg(int arg_type, unsigned char *board, int *position)
{
	int rtn;
	int x;

	x = 0;
	rtn = 0;
	if (arg_type == T_DIR)
	{
		while (x < 4)
		{
			rtn += board[(*position % MEM_SIZE)]
			*position += 1;
			x++;
		}
	}
	else if (arg_type == T_IND)
	{
		rtn += board[(*position % MEM_SIZE)]
		*position += 1;
		rtn += board[(*position % MEM_SIZE)]
		*position += 1;
	}
	else if (arg_type == T_REG)
	{
		rtn += board[(*position % MEM_SIZE)]
		*position += 1;
	}
}

t_op_args	*get_op_args(t_cursor *cursor, unsigned char *board)
{
	t_op_args	*args;
	int			args_position;
	int 		x;

	args_position = cursor->position + 1;
	args = (t_op_args *)ft_memalloc(sizeof(t_op_args));
	get_encoding_bits(args, args_position, board);
	args_position += 1;	
	x = 0;
	args->arg1_value = get_arg(args->arg1_type, board, &args_position);
	args->arg2_value = get_arg(args->arg2_type, board, &args_position);
	args->arg3_value = get_arg(args->arg3_type, board, &args_position);
	cursor->jump = args_position - cursor->position;
	cursor->position = args_position;
	return (args);
}
