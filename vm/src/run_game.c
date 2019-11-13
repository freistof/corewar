/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_game.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 19:05:30 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/13 19:34:31 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	kill_cursor(t_run *run, t_cursor *prev, t_cursor *current, t_cursor *next)
{
	prev->next = next;
	ft_memdel((void **)&current);
	run->num_cursors -= 1;
}

void	check(t_game *game, t_player **players, t_cursor *cursor, t_run *run)
{
	int			x;
	t_cursor	*prev;
	t_cursor	*next;

	if (run->cycles_to_die == 0)
		return (kill_all_cursors(game, cursor));
	x = 1;
	prev = cursor;
	cursor = cursor->next;
	next = cursor->next;
	while (x < run->num_cursors)
	{
		if (cursor->last_live > run->cycles_to_die)
			kill_cursor(run, prev, cursor, next);
		x++;
	}
	if (run->num_lives_reported > NBR_LIVE)
		run->cycles_to_die -= CYCLE_DELTA;
	else if (run->num_checks == MAX_CHECKS)
	{
		run->cycles_to_die -= CYCLE_DELTA;
		run->num_checks = 0;
	}
	run->num_lives_reported = 0;
}

void	run_game(t_game *game, t_player **players, t_cursor *cursor)
{
	t_run *run;

	run->last_reported_live = cursor->id;
	run->counter = 0;
	run->cycles_to_die = CYCLE_TO_DIE;
	run->checks_completed = 0;
	run->num_cursors = game->num_players;
	run->num_lives_reported = 0;
	run->num_checks = 0;
}