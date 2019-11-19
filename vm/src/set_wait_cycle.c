/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_wait_cycle.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 15:55:03 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/11/19 13:04:44 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	set_wait_cycle_2(t_cursor *cursor)
{
	if (cursor->opcode == 11)
		cursor->wait_cycle = 25;
	else if (cursor->opcode == 12)
		cursor->wait_cycle = 800;
	else if (cursor->opcode == 13)
		cursor->wait_cycle = 10;
	else if (cursor->opcode == 14)
		cursor->wait_cycle = 50;
	else if (cursor->opcode == 15)
		cursor->wait_cycle = 1000;
	else if (cursor->opcode == 16)
		cursor->wait_cycle = 2;
}

void		set_wait_cycle(t_cursor *cursor)
{
	if (cursor->opcode == 1)
		cursor->wait_cycle = 10;
	else if (cursor->opcode == 2)
		cursor->wait_cycle = 5;
	else if (cursor->opcode == 3)
		cursor->wait_cycle = 5;
	else if (cursor->opcode == 4)
		cursor->wait_cycle = 10;
	else if (cursor->opcode == 5)
		cursor->wait_cycle = 10;
	else if (cursor->opcode == 6)
		cursor->wait_cycle = 6;
	else if (cursor->opcode == 7)
		cursor->wait_cycle = 6;
	else if (cursor->opcode == 8)
		cursor->wait_cycle = 6;
	else if (cursor->opcode == 9)
		cursor->wait_cycle = 20;
	else if (cursor->opcode == 10)
		cursor->wait_cycle = 25;
	else
		set_wait_cycle_2(cursor);
}