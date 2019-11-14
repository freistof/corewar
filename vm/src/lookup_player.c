/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   lookup_player.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 14:27:08 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/13 15:59:08 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		find_player_id(t_player **players, char *player_str, int num_players)
{
	int x;

	x = 0;
	while (x < num_players)
	{
		if (ft_strequ(players[x]->file_name, player_str))
			return (players[x]->id);
		x++;
	}
	return (0);
}

char	*find_player_name(t_player **players, int this_id, int num_players)
{
	int x;

	x = 0;
	while (x < num_players)
	{
		if (players[x]->id == this_id)
			return (players[x]->file_name);
		x++;
	}
	return (NULL);
}

int		check_if_player(char *check, t_player **players, int num_players)
{
	int x;

	x = 0;
	while (x < num_players)
	{
		if (ft_strequ(check, players[x]->file_name))
			return (1);
		x++;
	}
	return (0);
}
