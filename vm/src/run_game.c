/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_game.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 19:05:30 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/14 15:08:19 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	kill_all_cursors(t_game *game, t_cursor *cursor)
{
	int			x;
	t_cursor	*to_free;
	
	x = 0;
	while (x < game->num_cursors)
	{
		to_free = cursor;
		cursor = cursor->next;
		ft_memdel((void **)&to_free);
		to_free = NULL;
		x++;
	}
	game->num_cursors = 0;
}

void	kill_cursor(t_game *game, t_cursor *prev, t_cursor *cur, t_cursor *next)
{
	prev->next = next;
	ft_memdel((void **)&cur);
	game->num_cursors -= 1;
}

/*
** Check cycles to die, kill all relevant cursors, modify cycles to die
*/
void	check(t_game *game, t_cursor *keep_cursor)
{
	int			x;
	t_cursor	*cursor;
	t_cursor	*prev;
	t_cursor	*next;

	cursor = keep_cursor;
	if (game->max_cycles_to_die == 0)
		return (kill_all_cursors(game, cursor));
	x = 1;
	prev = cursor;
	cursor = cursor->next;
	next = cursor->next;
	while (x < game->num_cursors)
	{
		if (cursor->last_live > game->max_cycles_to_die)
			kill_cursor(game, prev, cursor, next);
		x++;
	}
	if (game->num_lives_reported > NBR_LIVE)
		game->max_cycles_to_die -= CYCLE_DELTA;
	else if (game->check_counter == MAX_CHECKS)
	{
		game->max_cycles_to_die -= CYCLE_DELTA;
		game->check_counter = 0;
	}
	game->num_lives_reported = 0;
	game->cycles_to_die = 0;
}

int		is_valid_opcode(t_cursor *cursor)
{
	if (cursor->opcode > 0 && cursor->opcode < 17)
		return (1);
	return (0);
}

void	perform_op(t_game *game, t_cursor *cursor)
{
	if (cursor->opcode == 1)
		live(game, cursor);
}

void	check_cursor(t_game *game, t_cursor *cursor)
{
	if (cursor->wait_cycle > 0)
		cursor->wait_cycle -= 1;
	if (cursor->wait_cycle == 0)
	{
		if (is_valid_opcode(cursor))
			perform_op(game, cursor);
		jump(cursor);
		cursor->opcode = game->board[cursor->position];
		set_wait_cycle(cursor);
	}
}

void	main_loop(t_game *game, t_cursor *cursor)
{
	int x;

	x = 0;
	if (game->cycles_to_die == game->max_cycles_to_die)
		check(game, cursor);
	while (x < game->num_cursors)
	{
		check_cursor(game, cursor);
		cursor = cursor->next;
		x++;
	}
	game->cycle_counter += 1;
	game->cycles_to_die += 1;
	main_loop(game, cursor);
}

void	run_game(t_game *game, t_player **players, t_cursor *cursor)
{
	game->last_reported_live = cursor->id;
	game->cycle_counter = 0;
	game->max_cycles_to_die = CYCLE_TO_DIE;
	game->cycles_to_die = 0;
	game->num_cursors = game->num_players;
	game->num_lives_reported = 0;
	game->check_counter = 0;
}
