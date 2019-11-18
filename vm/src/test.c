/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 13:44:28 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/11/18 16:49:21 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

int main(void)
{
	int board_size = 1000;
	unsigned char board[board_size];
	unsigned char test_str[50] = {6, 104, 3, 0, 0, 0, 0, 0, 0, 0, 0};
	t_cursor    *cursor;
	t_op_args	*args;
	t_game		*game;

	game = (t_game *)ft_memalloc(sizeof(t_game));
    cursor = (t_cursor *)ft_memalloc(sizeof(t_cursor));
	cursor->next = cursor;
    cursor->position = 0;
    cursor->registry[1] = 7;
    cursor->registry[2] = 15;
    cursor->registry[3] = 90;
	ft_memset(board, 0, board_size);
	ft_memcpy(board, test_str, 50);
	cursor->opcode = board[cursor->position];
	game->board = board;
	op_storei(game, cursor);
    return (0);
}
