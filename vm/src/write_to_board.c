/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_to_board.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 15:47:03 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/12/11 18:08:09 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	write_to_board(unsigned char *board, int position, unsigned char *byte)
{
	if (position < 0)
		board[(unsigned int)position % MEM_SIZE] = byte[0];
	else
		board[position % MEM_SIZE] = byte[0];
	if (position + 1 < 0)
		board[(unsigned int)(position + 1) % MEM_SIZE] = byte[1];
	else
		board[(position + 1) % MEM_SIZE] = byte[1];
	if (position + 2 < 0)
		board[(unsigned int)(position + 2) % MEM_SIZE] = byte[2];
	else
		board[(position + 2) % MEM_SIZE] = byte[2];
	if (position + 3 < 0)
		board[(unsigned int)(position + 3) % MEM_SIZE] = byte[3];
	else
		board[(position + 3) % MEM_SIZE] = byte[3];
}
