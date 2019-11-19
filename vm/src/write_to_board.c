/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_to_board.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/19 15:47:03 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/11/19 15:49:00 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	write_to_board(unsigned char *board, int position, unsigned char *byte)
{
	board[position % MEM_SIZE] = byte[0];
	board[(position + 1) % MEM_SIZE] = byte[1];
	board[(position + 2) % MEM_SIZE] = byte[2];
	board[(position + 3) % MEM_SIZE] = byte[3];
}