/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_visual_field.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 12:43:28 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/12/13 14:02:11 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		update_visual_field(t_game *game, int position, int id)
{
	int		i;
	int		x;
	int		y;

	i = 0;
	wattron(game->visual->field, COLOR_PAIR(id));
	while (i < 4)
	{
		x = (((position + i) % MEM_SIZE) % 64) * 3 + 1;
		y = (((position + i) % MEM_SIZE) / 64) + 1;
		mvwprintw(game->visual->field, y, x, "%02x", game->board[position + i]);
		i++;
	}
	wattroff(game->visual->field, COLOR_PAIR(id));
}
