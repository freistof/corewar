/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_error.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 13:06:30 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/11 18:11:39 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		usage(void)
{
	ft_putstr(USAGE1);
	ft_putstr(USAGE2);
	ft_putstr(USAGE3);
	ft_putstr(USAGE4);
	ft_putstr(USAGE5);
	ft_putstr(USAGE6);
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