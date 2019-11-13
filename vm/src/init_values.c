/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_values.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 12:46:23 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/13 14:31:27 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	init_game(t_game *game)
{
	game->board = NULL;
	game->last_alive = 0;
	game->cycle_counter = 0;
	game->live_counter = 0;
	game->cycles_to_die = 0;
	game->check_counter = 0;
	game->dump = 0;
	game->num_players = 0;
}

void	init_players(t_player **players)
{
	int		x;

	x = 0;
	while (x < MAX_PLAYERS)
	{
		players[x] = (t_player *)ft_memalloc(sizeof(t_player));
		players[x]->name = NULL;
		players[x]->file_name = NULL;
		players[x]->comment = NULL;
		players[x]->code = NULL;
		players[x]->id = 0;
		players[x]->code_size = 0;
		x++;
	}
}
