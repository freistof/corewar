/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_board.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 17:08:21 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/13 18:41:54 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		fill_cursor_values(t_cursor **cursor)
{
	int x;

	x = 1;
	while (x < 16)
	{
		(*cursor)->registry[x] = -1;
		x++;
	}
	(*cursor)->jump = -1;
	(*cursor)->last_live = -1;
	(*cursor)->opcode = -1;
	(*cursor)->wait_cycle = -1;
}

static t_cursor	*init_cursors(t_game *game, t_player **players)
{
	int			x;
	int			j;
	t_cursor	*head;
	t_cursor	*cursor;

	x = game->num_players;
	j = 0;
	while (x > 0)
	{
		cursor = (t_cursor *)ft_memalloc(sizeof(t_cursor));
		cursor->id = x;
		cursor->position = (MEM_SIZE / game->num_players) * j;
		cursor->carry = false;
		cursor->registry[0] = x;
		fill_cursor_values(&cursor);
		cursor->next = NULL;
		if (x == game->num_players)
			head = cursor;
		if (x > 1)
			cursor = cursor->next;
		x--;
		j++;
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
	cursor = init_cursors(game, players);
	hex_dump(game->board);
	print_cursor(cursor);
}
