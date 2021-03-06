/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   finish_game.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 10:58:25 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/16 17:51:05 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_winner(t_game *game)
{
	ft_printf("WINNER IS %s [P%d]\n", game->players[game->last_reported_live - \
	1]->name, game->players[game->last_reported_live - 1]->id);
	game->players[game->last_reported_live - 1]->last_reported_live = -1;
}

void	finish_game(t_game *game, t_cursor *cursor)
{
	if (game->vis == false)
		print_winner(game);
	else
		fireworks(game);
	if (game->num_cursors > 0 && cursor)
	{
		kill_all_cursors(game, cursor);
	}
	free_players(game);
	free_game(game);
	if (game->vis)
	{
		getch();
		endwin();
	}
	exit(0);
}
