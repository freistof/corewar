/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_arg_types.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/13 14:18:51 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/13 14:23:08 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	reset_indirects(t_op_args *args, int result)
{
	if (args->arg1_type == 4)
		args->arg1_type = T_IND;
	if (args->arg2_type == 4)
		args->arg2_type = T_IND;
	if (args->arg3_type == 4)
		args->arg3_type = T_IND;
	return (result);
}

int			check_arg_types(t_op_args *args, int type1, int type2, int type3)
{
	if ((args->arg1_type == T_REG && (args->arg1_value < 1 || \
	args->arg1_value > 16)) || (args->arg2_type == T_REG && (args->arg2_value \
	< 1 || args->arg2_value > 16)) || (args->arg3_type == T_REG && \
	(args->arg3_value < 1 || args->arg3_value > 16)))
		return (0);
	if (args->arg1_type == T_IND)
		args->arg1_type = 4;
	if (args->arg2_type == T_IND)
		args->arg2_type = 4;
	if (args->arg3_type == T_IND)
		args->arg3_type = 4;
	if (((args->arg1_type == 0 && type1 != 0) || (args->arg1_type & type1) \
	!= args->arg1_type) || ((args->arg2_type == 0 && type2 != 0) || \
	(args->arg2_type & type2) != args->arg2_type) || ((args->arg3_type == 0 \
	&& type3 != 0) || (args->arg3_type & type3) != args->arg3_type))
		return (reset_indirects(args, 0));
	return (reset_indirects(args, 1));
}
