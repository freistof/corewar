/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 13:44:28 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/12/05 16:51:21 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"
#include <stdio.h>

int main(void)
{
	int board_size = 1000;
	unsigned char board[board_size];
	unsigned char test_str[50] = {13, 164, 0, 5, 0, 15, 3, 3, 9, 3, 16, 3, 18, 3, 0, 0, 0, 0, 0, 5, 0, 0, 0, 42};
	t_cursor    *cursor;
	t_op_args	*args;
	t_game		*game;

	game = (t_game *)ft_memalloc(sizeof(t_game));
    cursor = (t_cursor *)ft_memalloc(sizeof(t_cursor));
	cursor->next = cursor;
    cursor->position = 0;
	cursor->registry[0] = 5;
    cursor->registry[1] = 10;
    cursor->registry[2] = 3;
    cursor->registry[3] = 12;
	ft_memset(board, 0, board_size);
	ft_memcpy(board, test_str, 50);
	cursor->opcode = board[cursor->position];
	game->board = board;
	op_lloadi(game, cursor);
	for (int i = 0; i < 20; i++)
		ft_printf("%02x ", board[i]);
	ft_printf("\nreg value: %d\n", cursor->registry[2]);
    return (0);
}
