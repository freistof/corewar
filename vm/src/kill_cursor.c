/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   kill_cursor.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/26 10:48:14 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/04 14:35:01 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	kill_all_cursors(t_game *game, t_cursor *cursor)
{
	int			x;
	t_cursor	*to_free;

	x = 0;
	ft_putstr("KILL THEM ALL\n");
	// ft_printf("NUM CURSORS: %d\n", game->num_cursors);
	// ft_printf("CURSOR ADDR: %p\tNEXT ADDR: %p\tNEXT ADDR: %p\n", cursor, cursor->next, cursor->next->next);
	// print_cursor(cursor);
	// print_cursor(cursor->next);
	// for (int i = 0; i < game->num_cursors; i++)
	// {
	// 	print_cursor(cursor);
	// 	cursor = cursor->next;
	// }
	// print_cursor(cursor);
	while (x < game->num_cursors)
	{
		to_free = cursor;
		cursor = cursor->next;
		if (to_free)
		{
			free(to_free);
		}
		// ft_memdel((void **)&to_free);
		// to_free = NULL;
		x++;
	}
	game->num_cursors = 0;
}

void	kill_cursor(t_game *game, t_cursor *prev, t_cursor **cur, t_cursor *next)
{
	t_cursor *to_free;

	to_free = *cur;
	*cur = prev;
	prev->next = next;
	free(to_free);
	to_free = NULL;
	game->num_cursors -= 1;
	if (game->num_cursors == 1)
	{
		finish_game(game, NULL);
	}
}
