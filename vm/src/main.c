/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 12:39:40 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/11/11 18:02:50 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int argc, char **argv)
{
	t_player	**player;
	t_game		game[1];

	player = (t_player **)ft_memalloc(sizeof(t_player *) * MAX_PLAYERS);
	init_game(game);
	init_players(player);
	read_input(argc, argv, player, game);
	// init_corewar();
	// corewar();
	return (0);
}
