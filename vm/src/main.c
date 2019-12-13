/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 12:39:40 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/12/12 16:22:57 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

int		main(int argc, char **argv)
{
	t_player	**players;
	t_game		*game;

	if (argc < 2)
		usage();
	players = (t_player **)ft_memalloc(sizeof(t_player *) * MAX_PLAYERS);
	game = (t_game *)ft_memalloc(sizeof(t_game));
	init_game(game);
	init_players(players);
	read_input(argc, argv, players, game);
	init_board(game, players);
	return (0);
}
