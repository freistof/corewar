/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 17:25:21 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/11 12:13:27 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

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
		if (x % (MEM_SIZE / 32) == 0 && x != 0)
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
	for (int i = 0; i < MAX_REGISTRIES; i++)
		ft_printf("[%d]%d   ", i, cursor->registry[i]);
	NL;
	if (cursor->next)
		ft_printf("NEXT (ID):\t%10d\n", cursor->next->id);
}

void	print_temp_board(unsigned char *board)
{
	for (int i = 0; i < 50; i++)
	{
		ft_printf("%02x ", board[i]);
		if (i != 0 && i % 10 == 0)
			NL;
	}
}

void	print_registries(t_game *game, t_cursor *cursor)
{
	for (int i = 0; i < game->num_cursors; i++)
	{
		for (int x = 0; x < 16; x++)
			ft_printf("[%d]: %d\n", i, cursor->registry[x]);
		cursor = cursor->next;
	}
}

void	print_winner(t_game *game)
{
	// int x;
	// int	last_alive;

	// x = 0;
	// last_alive = -1;
	ft_printf("WINNER IS %s\n", game->players[game->last_reported_live - 1]->name);
	game->players[game->last_reported_live - 1]->last_reported_live = -1;

	// while (x < game->num_players)
	// {
	// 	if (game-)
	// 		ft_printf("WINNER IS %s\n", game->players[x]->name);
	// 	x++;
	// }
}
