/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_error.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 13:06:30 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/19 13:40:00 by rcorke        ########   odam.nl         */
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
	ft_putstr(USAGE7);
	exit(1);
}

void		input_error(t_player **players, t_game *game)
{
	int x;

	x = 0;
	while (x < MAX_PLAYERS && players)
	{
		if (players[x])
			free_player(players[x]);
		x++;
	}
	if (players)
		free(players);
	if (game)
		free(game);
	usage();
}

int			error_and_return_null(char *error)
{
	if (error)
	{
		ft_putstr_fd("ERROR: ", 2);
		ft_putstr_fd(error, 2);
	}
	return (0);
}
