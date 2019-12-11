/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_vis.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 13:10:44 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/12/09 15:50:48 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	set_cursor(t_game *game, t_cursor *cursor)
{
	int		x;
	// struct timespec ts;
	// struct timespec ts2;

	// ts.tv_nsec = 5;
	// ts2.tv_sec = 1;
	x = 0;
	init_pair(44, COLOR_MAGENTA, COLOR_WHITE);
	while (x < game->num_cursors)
	{
		wattron(game->visual->field, COLOR_PAIR(44));
		mvwprintw(game->visual->field, (cursor->position / 64) + 1, ((cursor->position % 64) * 3) + 1, "%02x", game->board[cursor->position]);
		wattroff(game->visual->field, COLOR_PAIR(44));
		x++;
		cursor = cursor->next;
	}
	wrefresh(game->visual->field);
	int		i;
	int		y;

	i = 0;
	y = 1;
	wmove(game->visual->field, 1, 1);
	while (i < MEM_SIZE)
	{
		if (i != 0 && i % 64 == 0)
		{
			y++;
			wmove(game->visual->field, y, 1);
		}
		else if (i != 0)
			wprintw(game->visual->field, " ");
		if (i % (MEM_SIZE / game->num_players) == 0)
			wattron(game->visual->field, COLOR_PAIR(i / (MEM_SIZE / game->num_players) + 1));
		if (i % (MEM_SIZE / game->num_players) == game->players[i / (MEM_SIZE / game->num_players)]->code_size)
			wattroff(game->visual->field, COLOR_PAIR(i / (MEM_SIZE / game->num_players) + 1));
		wprintw(game->visual->field, "%02x", game->board[i]);
		i++;
	}
	// if (game->num_cursors > 250)
	// {
	// 	getch();
	// 	exit(1);
	// }
	// 	// sleep(1);
}

void		update_visualizer(t_game *game, t_cursor *cursor)
{
	int player;
	int centre_startx;
	int	startx;
	int	starty;

	centre_startx = ((MEM_SIZE / 64) / 2) - 7;
	startx = 5;
	starty = ((MEM_SIZE / 64) / 2) + 1;
	set_cursor(game, cursor);
	// wattron(game->visual->info, COLOR_PAIR(101));
	mvwprintw(game->visual->info, starty, centre_startx, "GAME INFO:");
	mvwprintw(game->visual->info, starty + 2, startx, RESET_VISUAL_INFO);
	mvwprintw(game->visual->info, starty + 2, startx, "Total Cycles: %-4d", game->cycle_counter);
	mvwprintw(game->visual->info, starty + 4, startx, RESET_VISUAL_INFO);
	mvwprintw(game->visual->info, starty + 4, startx, "Cycles to die: %-4d - %-4d", game->cycles_to_die, game->max_cycles_to_die);
	mvwprintw(game->visual->info, starty + 6, startx, RESET_VISUAL_INFO);
	mvwprintw(game->visual->info, starty + 6, startx, "Check counter: %-4d", game->check_counter);
	mvwprintw(game->visual->info, starty + 8, startx, RESET_VISUAL_INFO);
	mvwprintw(game->visual->info, starty + 8, startx, "Last player alive: %s", game->players[game->last_reported_live - 1]->name);
	mvwprintw(game->visual->info, starty + 10, startx, RESET_VISUAL_INFO);
	mvwprintw(game->visual->info, starty + 10, startx, "Number of cursors alive: %4d", game->num_cursors);
	mvwprintw(game->visual->info, starty + 12, startx, RESET_VISUAL_INFO);
	mvwprintw(game->visual->info, starty + 12, startx, "Number of lives reported: %-4d", game->num_lives_reported);
	// wattroff(game->visual->info, COLOR_PAIR(101));
	player = 0;
	while (player < game->num_players)
	{
		wattron(game->visual->info, COLOR_PAIR((player + 1) * 10));
		mvwprintw(game->visual->info, player * ((MEM_SIZE / 128) / game->num_players) + 2, 5, "Player [%d]:\t%s", player + 1, game->players[player]->name, game->players[player]->comment);
		mvwprintw(game->visual->info, player * ((MEM_SIZE / 128) / game->num_players) + 3, 5, "Comment:\t\t%s", game->players[player]->comment);
		mvwprintw(game->visual->info, player * ((MEM_SIZE / 128) / game->num_players) + 5, 5, "Last Live:\t\t%d", game->players[player]->last_reported_live);
		wattron(game->visual->info, A_BOLD);
		if (game->players[player]->alive == true)
			mvwprintw(game->visual->info, player * ((MEM_SIZE / 128) / game->num_players) + 5, 35, "\tALIVE");
		else if (game->players[player]->alive == false)
			mvwprintw(game->visual->info, player * ((MEM_SIZE / 128) / game->num_players) + 5, 35, "\tRIP IN PIECE");
		wattroff(game->visual->info, COLOR_PAIR((player + 1) * 10));
		wattroff(game->visual->info, A_BOLD);
		player++;
	}
	wrefresh(game->visual->info);
}

static void	draw_game_info(t_game *game, t_cursor *cursor, t_visual *visual)
{
	// char *fre = "#%%%%%%\%##,/,,, ..**,.((#,&*@&\%*&\%@&\%\n(%%%%#%.%((/ ,/. ,,*#&@@##/(.&@(.,/,*%%\n#*(/%%#  .*,/( .&@@@@@%%%%#/@*#....**\n&(%%&(&    ***/\%@@@@@@@@@&%%%%#.,*,./\%(\n&/#%%\%    ..&&@@@@@@@@@&/&\%&%%\%#.,,*#\n&(&&&   (@@@@@@@@@@@@@@@@@@&&&%%,/,*(*/\n&&& \%&@@@@@&&&&&&&@@@@@@@@@&&&/\%#//\%*\n&&&&\%&@@@@@&&&&&&&&&&&&&@@@@@@@&&(@/*(#\n&&@\%&@@@@@@@@@&%%%%%%\%&@@@@@@@@@@#&&@\n&&.&@@@@@@@@@@@@@&&&&@@@&@*@&@@@@@&&@@@\n@@@%%@@@@@@@@\%@@@@&\%@@@@#@@@@@&@@&&&&%%\n%%\%&&&&@(&@@@&@#&@&&\%@@@@#@@@@&/&%#%##\%\n%%#%%%% *,*(@@@@@%%%%#@@@@@@@@**#&@&&\%&\n#/%%#(%%.  ,\%*,##(#\%##(#%%#(//*//&%%\%&&\n(*(\%**(#.  .,*(##*.((*/\%##((/**(,****//\n##%%%%%%(/..,(####(##(####(//**(%%.....\n%%%%%%%%\%#..*##(..*#\%##(((((/**@@#&&&&\%\n%%%%%%%%***.,%%##%%%%(\%&@#/*(#&@(\%((#\n&&&&&&&&/*(..#%%,,/\%&&\%#((##/*\%(%#%#&&&\n&&@%%%%/***, .#/*(%%%%\%###///%%&&@@\%#&&\n@@&%%\%.....,, **..*####(////@@@@@@@@@@@\n@&&&&&\%&&&&\%...,,((####(((/(@@@@@@@@@@@\n@@@\%@@@&@@@*  ....,(%%###(((#@@@@@@@@@@\n@@@@@@@@#     ..**(#######((#(##/@@@@@@";
	int centre_startx;
	int	startx;
	int	starty;

	centre_startx = ((MEM_SIZE / 64) / 2) - 7;
	startx = 5;
	starty = ((MEM_SIZE / 64) / 2) + 1;
	wattron(visual->info, COLOR_PAIR(101));
	mvwprintw(visual->info, starty, centre_startx, "GAME INFO:");
	mvwprintw(visual->info, starty + 2, startx, "Total Cycles: %-4d", game->cycle_counter);
	mvwprintw(visual->info, starty + 4, startx, "Cycles to die: %-4d - %-4d", game->cycles_to_die, game->max_cycles_to_die);
	mvwprintw(visual->info, starty + 6, startx, "Check counter: %-4d", game->check_counter);
	mvwprintw(visual->info, starty + 8, startx, "Last player alive: %s", game->players[game->last_reported_live - 1]->name);
	mvwprintw(visual->info, starty + 10, startx, "Number of cursors alive: %-4d", game->num_cursors);
	mvwprintw(visual->info, starty + 12, startx, "Number of lives reported: %-4d", game->num_lives_reported);
	wattroff(visual->info, COLOR_PAIR(101));
	wattroff(visual->info, A_BOLD);
}

static void	draw_info(t_game *game, t_cursor *cursor, t_visual *visual)
{
	int		player;

	player = 0;
	wattron(visual->info, A_BOLD);
	while (player < game->num_players)
	{
		wattron(visual->info, COLOR_PAIR((player + 1) * 10));
		mvwprintw(visual->info, player * ((MEM_SIZE / 128) / game->num_players) + 2, 5, "Player [%d]:\t%s", player + 1, game->players[player]->name, game->players[player]->comment);
		mvwprintw(visual->info, player * ((MEM_SIZE / 128) / game->num_players) + 3, 5, "Comment:\t\t%s", game->players[player]->comment);
		mvwprintw(visual->info, player * ((MEM_SIZE / 128) / game->num_players) + 5, 5, "Last Live:\t\t%-4d", game->players[player]->last_reported_live);
		wattron(visual->info, A_BOLD);
		if (game->players[player]->alive == true)
			mvwprintw(visual->info, player * ((MEM_SIZE / 128) / game->num_players) + 5, 35, "\tALIVE");
		else if (game->players[player]->alive == false)
			mvwprintw(visual->info, player * ((MEM_SIZE / 128) / game->num_players) + 5, 35, "\tRIP IN PIECE");
		wattroff(visual->info, COLOR_PAIR((player + 1) * 10));
		wattroff(visual->info, A_BOLD);
		player++;
	}
	draw_game_info(game, cursor, visual);
}

static void	draw_field(t_game *game, t_cursor *cursor, t_visual *visual)
{
	int		i;
	int		y;

	i = 0;
	y = 1;
	wmove(visual->field, 1, 1);
	while (i < MEM_SIZE)
	{
		if (i != 0 && i % 64 == 0)
		{
			y++;
			wmove(visual->field, y, 1);
		}
		else if (i != 0)
			wprintw(visual->field, " ");
		if (i % (MEM_SIZE / game->num_players) == 0)
			wattron(visual->field, COLOR_PAIR(i / (MEM_SIZE / game->num_players) + 1));
		if (i % (MEM_SIZE / game->num_players) == game->players[i / (MEM_SIZE / game->num_players)]->code_size)
			wattroff(visual->field, COLOR_PAIR(i / (MEM_SIZE / game->num_players) + 1));
		wprintw(visual->field, "%02x", game->board[i]);
		i++;
	}
}

// void	init_visualizer(t_game *game, t_cursor *cursor)
// {
// 	t_visual	*visual;

// 	initscr();
// 	curs_set(0);
// 	start_color();
// 	noecho();
// 	visual = (t_visual *)ft_memalloc(sizeof(t_visual));
// 	visual->field = newwin(VISUAL_BOX_FIELD_Y, VISUAL_BOX_FIELD_X, 0, 0);
// 	visual->info = newwin(VISUAL_BOX_INFO_Y, VISUAL_BOX_INFO_X, 0, (MEM_SIZE / 64) * 3 + 2);
// 	refresh();
// 	box(visual->field, 0, 0);
// 	box(visual->info, 0, 0);
// 	init_pair(1, COLOR_RED, COLOR_BLACK);
// 	init_pair(2, COLOR_BLUE, COLOR_BLACK);
// 	init_pair(3, COLOR_GREEN, COLOR_BLACK);
// 	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
// 	init_color(102, 0, 0, 0);
// 	init_color(100, 255, 255, 255);
// 	init_pair(101, COLOR_BLACK, 102);
// 	init_pair(10, COLOR_RED, COLOR_BLACK);
// 	init_pair(20, COLOR_BLUE, COLOR_BLACK);
// 	init_pair(30, COLOR_GREEN, COLOR_BLACK);
// 	init_pair(40, COLOR_YELLOW, COLOR_BLACK);

// 	init_pair(5, COLOR_WHITE, COLOR_WHITE);
// 	// init_color(5, 255, 0, 0);
// 	draw_field(game, cursor, visual);
// 	wbkgd(visual->info, 5);
// 	draw_info(game, cursor, visual);
// 	wrefresh(visual->field);
// 	wrefresh(visual->info);
// 	game->visual = visual;
// 	getch();
// }
