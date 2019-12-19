/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_values.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 12:46:23 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/19 13:26:21 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	init_game(t_game *game)
{
	game->players = NULL;
	game->visual = NULL;
	game->board = NULL;
	game->cycle_counter = 0;
	game->num_lives_reported = 0;
	game->cycles_to_die = 0;
	game->dump = -1;
	game->num_players = 0;
	game->vis = false;
	game->delay = 50;
	game->silent = false;
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
		players[x]->alive = true;
		players[x]->last_reported_live = 0;
		x++;
	}
}
