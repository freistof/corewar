/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   execute_op.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 10:54:22 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/26 10:54:41 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	execute_op_2(t_game *game, t_cursor *cursor)
{
	if (cursor->opcode == 11)
		op_storei(game, cursor);
	else if (cursor->opcode == 12)
		op_fork(game, cursor);
	else if (cursor->opcode == 13)
		op_lload(game, cursor);
	else if (cursor->opcode == 14)
		op_lloadi(game, cursor);
	else if (cursor->opcode == 15)
		op_lfork(game, cursor);
	else if (cursor->opcode == 16)
		op_aff(game, cursor);
}

void	execute_op(t_game *game, t_cursor *cursor)
{
	if (cursor->opcode == 1)
		op_live(game, cursor);
	else if (cursor->opcode == 2)
		op_load(game, cursor);
	else if (cursor->opcode == 3)
		op_store(game, cursor);
	else if (cursor->opcode == 4)
		op_add(game, cursor);
	else if (cursor->opcode == 5)
		op_subtract(game, cursor);
	else if (cursor->opcode == 6)
		op_and(game, cursor);
	else if (cursor->opcode == 7)
		op_or(game, cursor);
	else if (cursor->opcode == 8)
		op_xor(game, cursor);
	else if (cursor->opcode == 9)
		op_jump(game, cursor);
	else if (cursor->opcode == 10)
		op_loadi(game, cursor);
	else
		execute_op_2(game, cursor);
}