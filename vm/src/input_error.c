/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_error.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 13:06:30 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/13 15:15:03 by rcorke        ########   odam.nl         */
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

static void	free_player(t_player *player)
{
	ft_memdel((void **)&player->name);
	ft_memdel((void **)&player->file_name);
	ft_memdel((void **)&player->comment);
	ft_memdel((void **)&player->code);
	ft_memdel((void **)&player);
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
