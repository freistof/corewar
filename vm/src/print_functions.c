/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 17:25:21 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/12 18:30:35 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_code(t_player *player)
{
	for (int i = 0; i < player->code_size; i++)
	{
		if (i % 16 == 0 && i != 0)
			NL;
		ft_printf("%02x ", player->code[i]);
	}
}

void	print_players(t_player **players, int num_players)
{
	for (int i = 0; i < num_players; i++)
		ft_printf("PLAYER[%i] - FILE NAME [%50s]\n", i, players[i]->file_name);
		// ft_printf("PLAYER[%i] - NAME [%60s]\tID [%d]\tFILE NAME [%50s]\tCODE SIZE [%d]\tFILE SIZE [%d]\n", i, players[i]->name, players[i]->id, players[i]->file_name, players[i]->code_size, players[i]->file_size);
	NL;
}
