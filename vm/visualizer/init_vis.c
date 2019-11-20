/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_vis.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/20 13:10:44 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/11/20 16:42:36 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	draw_game_info(t_game *game, t_cursor *cursor, t_visual *visual)
{
	char *fre = "#%%%%%%\%##,/,,, ..**,.((#,&*@&\%*&\%@&\%\n(%%%%#%.%((/ ,/. ,,*#&@@##/(.&@(.,/,*%%\n#*(/%%#  .*,/( .&@@@@@%%%%#/@*#....**\n&(%%&(&    ***/\%@@@@@@@@@&%%%%#.,*,./\%(\n&/#%%\%    ..&&@@@@@@@@@&/&\%&%%\%#.,,*#\n&(&&&   (@@@@@@@@@@@@@@@@@@&&&%%,/,*(*/\n&&& \%&@@@@@&&&&&&&@@@@@@@@@&&&/\%#//\%*\n&&&&\%&@@@@@&&&&&&&&&&&&&@@@@@@@&&(@/*(#\n&&@\%&@@@@@@@@@&%%%%%%\%&@@@@@@@@@@#&&@\n&&.&@@@@@@@@@@@@@&&&&@@@&@*@&@@@@@&&@@@\n@@@%%@@@@@@@@\%@@@@&\%@@@@#@@@@@&@@&&&&%%\n%%\%&&&&@(&@@@&@#&@&&\%@@@@#@@@@&/&%#%##\%\n%%#%%%% *,*(@@@@@%%%%#@@@@@@@@**#&@&&\%&\n#/%%#(%%.  ,\%*,##(#\%##(#%%#(//*//&%%\%&&\n(*(\%**(#.  .,*(##*.((*/\%##((/**(,****//\n##%%%%%%(/..,(####(##(####(//**(%%.....\n%%%%%%%%\%#..*##(..*#\%##(((((/**@@#&&&&\%\n%%%%%%%%***.,%%##%%%%(\%&@#/*(#&@(\%((#\n&&&&&&&&/*(..#%%,,/\%&&\%#((##/*\%(%#%#&&&\n&&@%%%%/***, .#/*(%%%%\%###///%%&&@@\%#&&\n@@&%%\%.....,, **..*####(////@@@@@@@@@@@\n@&&&&&\%&&&&\%...,,((####(((/(@@@@@@@@@@@\n@@@\%@@@&@@@*  ....,(%%###(((#@@@@@@@@@@\n@@@@@@@@#     ..**(#######((#(##/@@@@@@";
	int centre_startx;
	int	startx;
	int	starty;

	centre_startx = ((MEM_SIZE / 64) / 2) - 7;
	startx = 5;
	starty = ((MEM_SIZE / 64) / 2) + 1;
	wattron(visual->info, COLOR_PAIR(101));
	mvwprintw(visual->info, starty, centre_startx, "GAME INFO:");
	mvwprintw(visual->info, starty + 2, startx, "Total Cycles: %d", game->cycle_counter);
	mvwprintw(visual->info, starty + 4, startx, "Cycles to die: %d", game->max_cycles_to_die);
	mvwprintw(visual->info, starty + 6, startx, "Cycle delta Δ: %d", CYCLE_DELTA);
	mvwprintw(visual->info, starty + 8, startx, "Last player alive: %s", game->players[game->last_reported_live - 1]->name);
	mvwprintw(visual->info, starty + 10, startx, "Number of cursors alive: %d", game->num_cursors);
	mvwprintw(visual->info, starty + 11, 0, "%s", fre);
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
		mvwprintw(visual->info, player * ((MEM_SIZE / 128) / game->num_players) + 5, 5, "Last Live:\t\t%d", game->players[player]->last_reported_live);
		if (game->players[player]->alive == true)
			mvwprintw(visual->info, player * ((MEM_SIZE / 128) / game->num_players) + 5, 25, "\t\tALIVE");
		else if (game->players[player]->alive == false)
			mvwprintw(visual->info, player * ((MEM_SIZE / 128) / game->num_players) + 5, 25, "\t\tRIP IN PIECE");
		wattroff(visual->info, COLOR_PAIR((player + 1) * 10));
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

void	init_visualizer(t_game *game, t_cursor *cursor)
{
	t_visual	*visual;

	ft_printf("test");
	initscr();
	curs_set(0);
	start_color();
	visual = (t_visual *)ft_memalloc(sizeof(t_visual));
	visual->field = newwin((MEM_SIZE / 64) + 2, (MEM_SIZE / 64) * 3 + 1, 0, 0);
	visual->info = newwin((MEM_SIZE / 64) + 2, (MEM_SIZE / 64), 0, (MEM_SIZE / 64) * 3 + 2);
	refresh();
	box(visual->field, 0, 0);
	box(visual->info, 0, (MEM_SIZE / 64) * 3 + 2);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_color(102, 0, 0, 0);
	init_color(100, 255, 255, 255);
	init_pair(101, COLOR_BLACK, 102);
	init_pair(10, COLOR_RED, 102);
	init_pair(20, COLOR_BLUE, 102);
	init_pair(30, COLOR_GREEN, 102);
	init_pair(40, COLOR_YELLOW, 102);

	init_pair(5, COLOR_WHITE, COLOR_WHITE);
	// init_color(5, 255, 0, 0);
	draw_field(game, cursor, visual);
	wbkgd(visual->info, 5);
	draw_info(game, cursor, visual);
	wrefresh(visual->field);
	wrefresh(visual->info);
	game->visual = visual;
}
