/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   free_functions.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 16:49:37 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/11/18 16:51:57 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		free_player(t_player *player)
{
	ft_memdel((void **)&player->name);
	ft_memdel((void **)&player->file_name);
	ft_memdel((void **)&player->comment);
	ft_memdel((void **)&player->code);
	ft_memdel((void **)&player);
}

void		free_players(t_game *game)
{
	int x;

	x = 0;
	while (x < game->num_players)
	{
		free_player(game->players[x]);
		x++;
	}
}

void		free_game(t_game *game)
{
	ft_memdel((void **)&game->board);
	ft_memdel((void **)&game);
}
