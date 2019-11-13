/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 12:39:40 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/11/13 13:24:43 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		main(int argc, char **argv)
{
	t_player	**player;
	t_game		*game;

	if (argc < 2)
		usage();
	player = (t_player **)ft_memalloc(sizeof(t_player *) * MAX_PLAYERS);
	game = (t_game *)ft_memalloc(sizeof(t_game));
	init_game(game);
	init_players(player);
	read_input(argc, argv, player, game);
	// init_corewar();
	// corewar();
	return (0);
}
