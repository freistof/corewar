/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_visualizer.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/09 15:22:44 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/12/13 14:10:39 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

static void		init_player_info(t_game *game, t_cursor *cursor, \
t_visual *visual)
{
	int		player;

	player = 0;
	wattron(visual->info, A_BOLD);
	while (player < game->num_players)
	{
		wattron(visual->info, COLOR_PAIR(player + 1));
		mvwprintw(visual->info, player * (32 / game->num_players) + 2, 5, \
		"Player [%d]:\t%s", player + 1, game->players[player]->name, \
		game->players[player]->comment);
		mvwprintw(visual->info, player * (32 / game->num_players) + 3, 5, \
		"Comment:\t\t%s", game->players[player]->comment);
		mvwprintw(visual->info, player * (32 / game->num_players) + 5, 5, \
		"Last Live:");
		wattroff(visual->info, COLOR_PAIR(player + 1));
		player++;
	}
	wattroff(visual->info, A_BOLD);
}

static void		draw_info(t_game *game, t_cursor *cursor, t_visual *visual)
{
	init_player_info(game, cursor, visual);
	mvwprintw(visual->info, INFO_START_Y, 25, "GAME INFO:");
	mvwprintw(visual->info, INFO_START_Y + 4, 5, "Total cycles:");
	mvwprintw(visual->info, INFO_START_Y + 6, 5, "Cycles to die:");
	mvwprintw(visual->info, INFO_START_Y + 8, 5, "Check counter:");
	mvwprintw(visual->info, INFO_START_Y + 10, 5, "Last player alive:");
	mvwprintw(visual->info, INFO_START_Y + 12, 5, "Number of cursors alive:");
	mvwprintw(visual->info, INFO_START_Y + 14, 5, "Number of lives reported \
this cycle:");
	wattron(visual->info, A_BOLD);
	mvwprintw(visual->info, INFO_START_Y + 16, 5, "USE +/- TO \
	INCREASE/DECREASE DELAY BETWEEN CYCLES");
	mvwprintw(visual->info, INFO_START_Y + 25, 5, "PRESS SPACE TO START");
	wattroff(visual->info, A_BOLD);
	wrefresh(visual->info);
}

static void		draw_field(t_game *game, t_cursor *cursor, t_visual *visual)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < MEM_SIZE)
	{
		if (x % 64 == 0)
		{
			y++;
			wmove(visual->field, y, 1);
		}
		else
			wprintw(visual->field, " ");
		if (x % (MEM_SIZE / game->num_players) == 0)
			wattron(visual->field, COLOR_PAIR(x / (MEM_SIZE / \
			game->num_players) + 1));
		if (x % (MEM_SIZE / game->num_players) == game->players[x / \
		(MEM_SIZE / game->num_players)]->code_size)
			wattroff(visual->field, COLOR_PAIR(x / (MEM_SIZE / \
			game->num_players) + 1));
		wprintw(visual->field, "%02x", game->board[x]);
		x++;
	}
	wrefresh(visual->field);
}

static void		init_colors(void)
{
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
}

void			init_visualizer(t_game *game, t_cursor *cursor)
{
	t_visual	*visual;
	int			ch;

	initscr();
	curs_set(0);
	start_color();
	noecho();
	cbreak();
	visual = (t_visual *)ft_memalloc(sizeof(t_visual));
	visual->field = newwin(VISUAL_BOX_FIELD_Y, VISUAL_BOX_FIELD_X, 0, 0);
	visual->info = newwin(VISUAL_BOX_INFO_Y, VISUAL_BOX_INFO_X, 0, \
	(MEM_SIZE / 64) * 3 + 2);
	box(visual->field, 0, 0);
	box(visual->info, 0, 0);
	init_colors();
	refresh();
	draw_field(game, cursor, visual);
	draw_info(game, cursor, visual);
	game->visual = visual;
	ch = 0;
	while (ch != ' ')
		ch = getch();
	put_ascii_art(game->visual->info);
}
