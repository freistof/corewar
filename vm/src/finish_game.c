/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   finish_game.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 10:58:25 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/11 19:11:59 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	finish_game(t_game *game, t_cursor *cursor)
{
	if (game->vis == false)
		print_winner(game);
	else
	{
		print_winner_vis(game);
		fireworks(game);
	}
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
	// while (1);
	exit(0);
}
