/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 17:25:21 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/13 18:24:53 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_code(t_player *player)
{
	for (int i = 0; i < player->code_size; i++)
	{
		if (i % 16 == 0 && i != 0)
			NL;
		ft_printf("%02x ", player->code[i]);
	}
}

void	print_players(t_player **players, int num_players)
{
	for (int i = 0; i < num_players; i++)
		ft_printf("PLAYER[%i] - NAME [%60s]\tID [%d]\tFILE NAME [%50s]\tCODE \
		SIZE [%d]\tFILE SIZE [%d]\n", i, players[i]->name, players[i]->id, \
		players[i]->file_name, players[i]->code_size, players[i]->file_size);
	NL;
}

void	hex_dump(unsigned char *board)
{
	int x;
	
	x = 0;
	while (x < MEM_SIZE)
	{
		if (x % (MEM_SIZE / 64) == 0 && x != 0)
			NL;
		if (board[x] != 0)
			ft_printf("\033[0;31m");
		ft_printf("%02x \033[0m", board[x]);
		x++;
	}
	NL;
}

void	print_cursor(t_cursor *cursor)
{
	ft_printf("ID:\t\t%10d\n", cursor->id);
	if (cursor->carry == false)
		ft_printf("CARRY:\t\t%10d\n", 0);
	else
		ft_printf("CARRY:\t%10d\n", 1);
	ft_printf("OPCODE:\t\t%10d\nLAST LIVE:\t%10d\n", cursor->opcode, cursor->last_live);
	ft_printf("WAIT CYCLE:\t%10d\nPOSITION:\t%10d\nJUMP:\t\t%10d\nREGISTRY: ", cursor->wait_cycle, cursor->position, cursor->jump);
	for (int i = 0; i < 16; i++)
		ft_printf("[%d]%d   ", i, cursor->registry[i]);
	NL;
	if (cursor->next)
		ft_printf("NEXT (ID):\t%10d\n", cursor->next->id);
}
