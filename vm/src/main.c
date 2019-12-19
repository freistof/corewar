/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 12:39:40 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/12/19 13:22:21 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

static void	introduction(t_game *game, t_player **players)
{
	int x;

	x = 0;
	ft_printf("yoooooo it's a fight y'all get in here\n");
	while (x < game->num_players)
	{
		ft_printf("PLAYER [%i] - weighing %d bytes - '%s' (%s)\n", x + 1, \
		players[x]->code_size, players[x]->name, players[x]->comment);
		x++;
	}
	ft_printf("\n");
}

int			main(int argc, char **argv)
{
	t_player	**players;
	t_game		*game;

	if (argc < 2)
		usage();
	players = (t_player **)ft_memalloc(sizeof(t_player *) * MAX_PLAYERS);
	game = (t_game *)ft_memalloc(sizeof(t_game));
	game->players = players;
	init_game(game);
	init_players(players);
	read_input(argc, argv, players, game);
	if (game->vis == false)
		introduction(game, players);
	init_board(game, players);
	return (0);
}
