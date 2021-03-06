/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_board.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 17:08:21 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/18 17:21:15 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		fill_cursor_values(t_cursor **cursor)
{
	int x;

	x = 1;
	while (x < MAX_REGISTRIES)
	{
		(*cursor)->registry[x] = 0;
		x++;
	}
	(*cursor)->jump = 0;
	(*cursor)->last_live = 0;
	(*cursor)->opcode = 0;
	(*cursor)->wait_cycle = 0;
	(*cursor)->carry = false;
}

static t_cursor	*init_cursors(t_game *game)
{
	int			x;
	t_cursor	*head;
	t_cursor	*cursor;

	x = game->num_players;
	cursor = (t_cursor *)ft_memalloc(sizeof(t_cursor));
	while (x > 0)
	{
		cursor->id = x;
		cursor->position = (MEM_SIZE / game->num_players) * (x - 1);
		cursor->registry[0] = x * -1;
		fill_cursor_values(&cursor);
		if (x == game->num_players)
			head = cursor;
		if (x > 1)
		{
			cursor->next = (t_cursor *)ft_memalloc(sizeof(t_cursor));
			cursor = cursor->next;
		}
		x--;
	}
	cursor->next = head;
	return (head);
}

static void		load_players(t_game *game, t_player **players)
{
	int x;

	x = 0;
	while (x < game->num_players)
	{
		ft_memcpy(&(game->board[(MEM_SIZE / game->num_players) * x]), \
		players[x]->code, players[x]->code_size);
		x++;
	}
}

void			init_board(t_game *game, t_player **players)
{
	t_cursor *cursor;

	game->board = (unsigned char *)ft_memalloc(sizeof(unsigned char) \
	* MEM_SIZE);
	load_players(game, players);
	cursor = init_cursors(game);
	game->players = players;
	run_game(game, cursor);
}
