/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_error.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 13:06:30 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/18 16:49:54 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		usage(void)
{
	ft_putstr(USAGE1);
	ft_putstr(USAGE2);
	ft_putstr(USAGE3);
	exit(1);
}

void		input_error(t_player **players, t_game *game)
{
	int x;

	x = 0;
	while (x < MAX_PLAYERS)
	{
		free_player(players[x]);
		x++;
	}
	if (players)
		free(players);
	if (game)
		free(game);
	usage();
}
