/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   finish_game.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 10:58:25 by rcorke         #+#    #+#                */
<<<<<<< HEAD
/*   Updated: 2019/12/11 19:11:59 by rcorke        ########   odam.nl         */
=======
/*   Updated: 2019/12/05 17:15:09 by lvan-vlo      ########   odam.nl         */
>>>>>>> dad0c8c767484a2c5f7206b7fad37cf8077ffe85
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	finish_game(t_game *game, t_cursor *cursor)
{
<<<<<<< HEAD
	if (game->vis == false)
		print_winner(game);
	else
	{
		print_winner_vis(game);
		fireworks(game);
	}
=======
	if (game->num_alive_players > 0)
	{
		// HERE;
		print_winner(game);
	}
	else
		ft_printf("NO WINNERS M8\n");
>>>>>>> dad0c8c767484a2c5f7206b7fad37cf8077ffe85
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
