/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   update_visual_info.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 15:55:05 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/12/18 17:41:06 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

static void	update_game_info(t_game *game)
{
	mvwprintw(game->visual->info, INFO_START_Y + 4, 40, "%12d", \
	game->cycle_counter);
	mvwprintw(game->visual->info, INFO_START_Y + 6, 40, "%4d (CD %4d)", \
	game->cycles_to_die, game->max_cycles_to_die);
	mvwprintw(game->visual->info, INFO_START_Y + 8, 40, "%12d", \
	game->check_counter);
	mvwprintw(game->visual->info, INFO_START_Y + 10, 40, "%12d", \
	game->last_reported_live);
	mvwprintw(game->visual->info, INFO_START_Y + 12, 40, "%12d", \
	game->num_cursors);
	mvwprintw(game->visual->info, INFO_START_Y + 14, 48, "%4d", \
	game->num_lives_reported);
	mvwprintw(game->visual->info, INFO_START_Y + 16, 5, "\t\t\t\t\t\t\t\t");
	mvwprintw(game->visual->info, INFO_START_Y + 16, 5, "CURRENT DELAY: \
%d", game->delay);
}

static void	update_player_info(t_game *game)
{
	int		player;

	player = 0;
	while (player < game->num_players)
	{
		wattron(game->visual->info, COLOR_PAIR(player + 1));
		if (game->players[player]->alive)
			mvwprintw(game->visual->info, player * (32 / game->num_players) + \
			5, 25, "%d", game->players[player]->last_reported_live);
		else
			mvwprintw(game->visual->info, player * (32 / game->num_players) + \
			5, 25, "RIP   ");
		wattroff(game->visual->info, COLOR_PAIR(player + 1));
		player++;
	}
}

static void	undo_cursor_update(t_game *game, t_cursor *cursor)
{
	int		cursor_i;
	int		x;
	int		y;
	short	color_pair;
	chtype	chr;

	cursor_i = 0;
	while (cursor_i < game->num_cursors)
	{
		y = cursor->position / 64 + 1;
		x = (cursor->position % 64) * 3 + 1;
		chr = mvwinch(game->visual->field, y, x);
		color_pair = (chr & A_COLOR) / 256;
		mvwchgat(game->visual->field, y, x, 2, 0, color_pair, NULL);
		cursor_i++;
		cursor = cursor->next;
	}
}

static void	update_cursors(t_game *game, t_cursor *cursor)
{
	int		cursor_i;
	int		x;
	int		y;
	short	color_pair;
	chtype	chr;

	cursor_i = 0;
	while (cursor_i < game->num_cursors)
	{
		y = cursor->position / 64 + 1;
		x = (cursor->position % 64) * 3 + 1;
		chr = mvwinch(game->visual->field, y, x);
		color_pair = (chr & A_COLOR) / 256;
		mvwchgat(game->visual->field, y, x, 2, A_STANDOUT, color_pair, NULL);
		cursor_i++;
		cursor = cursor->next;
	}
	wrefresh(game->visual->field);
	undo_cursor_update(game, cursor);
}

void		update_visual_info(t_game *game, t_cursor *cursor)
{
	int ch;

	usleep(game->delay * 1000);
	nodelay(game->visual->info, true);
	ch = wgetch(game->visual->info);
	if (ch == ' ')
	{
		ch = getch();
		while (ch != ' ')
			ch = getch();
	}
	if (ch == '+' && game->delay < 2147483)
		game->delay += 5;
	if (ch == '-' && game->delay > 0)
		game->delay -= 5;
	update_cursors(game, cursor);
	update_player_info(game);
	update_game_info(game);
	wrefresh(game->visual->info);
}
