/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 11:00:03 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/19 13:21:41 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** See if players reported live in last cycle
*/

static void	check_players(t_game *game)
{
	int x;

	x = 0;
	while (x < game->num_players)
	{
		if (game->players[x]->last_reported_live < game->cycle_counter - \
		game->cycles_to_die)
		{
			if (game->players[x]->alive == true)
			{
				if (game->vis == false)
					ft_printf("PLAYER [%d] %s K.O.ed\n", \
					game->players[x]->id, game->players[x]->name);
				game->players[x]->alive = false;
				game->num_alive_players -= 1;
			}
		}
		x++;
	}
}

static void	check_players_and_reset_values(t_game *game)
{
	game->check_counter += 1;
	game->num_lives_reported = 0;
	check_players(game);
	game->cycles_to_die = 0;
}

void		end_check(t_game *game, t_cursor *cursor)
{
	if (game->num_lives_reported > NBR_LIVE || game->check_counter == \
	MAX_CHECKS)
	{
		game->max_cycles_to_die -= CYCLE_DELTA;
		game->check_counter = -1;
	}
	if (game->max_cycles_to_die < 0)
	{
		finish_game(game, cursor);
		game->max_cycles_to_die = 0;
	}
	check_players_and_reset_values(game);
}

/*
** Check cycles to die, kill all relevant cursors, modify cycles to die
*/

void		check(t_game *game, t_cursor *keep_cursor)
{
	int			x;
	t_cursor	*cursor;
	t_cursor	*prev;
	t_cursor	*next;

	prev = keep_cursor;
	cursor = prev->next;
	next = cursor->next;
	x = 0;
	while (x < game->num_cursors)
	{
		if (cursor && cursor->last_live < game->cycle_counter - \
		game->cycles_to_die)
			kill_cursor(game, prev, &cursor, next);
		prev = cursor;
		cursor = prev->next;
		next = cursor->next;
		x++;
	}
	end_check(game, keep_cursor);
}
