/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kill_cursor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 10:48:14 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/18 17:02:15 by rcorke        ########   odam.nl         */
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
		if (to_free)
			free(to_free);
		x++;
	}
	game->num_cursors = 0;
}

void	kill_cursor(t_game *game, t_cursor *prev, t_cursor **cur, \
t_cursor *next)
{
	t_cursor *to_free;

	to_free = *cur;
	*cur = prev;
	prev->next = next;
	if (to_free)
		free(to_free);
	to_free = NULL;
	game->num_cursors -= 1;
	if (game->num_cursors == 0)
		finish_game(game, NULL);
}
