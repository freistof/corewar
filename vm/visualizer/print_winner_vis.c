/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_winner_vis.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 18:10:53 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/11 18:29:19 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

void		print_winner_vis(t_game *game)
{
	werase(game->visual->field);
	curs_set(25);
	// wrefresh(game->visual->field);
	wattron(game->visual->field, A_BOLD);
	mvwprintw(game->visual->field, 30, 50, "THE \
WINNER IS: %s", game->players[game->last_reported_live - 1]->name);
	// mvwprintw(game->visual->field, 500, 50, "THE \
	// WINNER IS: %s", game->players[game->last_reported_live - 1]->name);
	// mvwprintw(game->visual->field, 1500, 150, "THE \
	// WINNER IS: %s", game->players[game->last_reported_live - 1]->name);
	// mvwprintw(game->visual->field, 2500, 250, "THE \
	// WINNER IS: %s", game->players[game->last_reported_live - 1]->name);
	wattroff(game->visual->field, A_BOLD);
	wrefresh(game->visual->field);
}
