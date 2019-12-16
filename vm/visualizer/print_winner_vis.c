/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_winner_vis.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 18:10:53 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/16 15:31:01 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

void		print_winner_vis(t_game *game)
{
	werase(game->visual->field);
	curs_set(25);
	wattron(game->visual->field, A_BOLD);
	mvwprintw(game->visual->field, 30, 50, "THE \
WINNER IS %s [P%d]", game->players[game->last_reported_live - 1]->name, \
game->players[game->last_reported_live - 1]->id);
	wattroff(game->visual->field, A_BOLD);
	wrefresh(game->visual->field);
}
