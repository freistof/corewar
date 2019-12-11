/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vis_test.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 16:03:10 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/12/10 17:12:23 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#define RED_WHITE 20
#define RED_WHITE_CH_TYPE 5120

#define BLUE_BLACK 5
// #define BLUE_BLACK_CH_TYPE 1280

// #define WHITE_BLACK 1
// #define BLUE_BLACK_CH_TYPE 256

short	get_color_pair(WINDOW *win, chtype chr)
{
	// if ((chr & A_COLOR) / 256 == RED_WHITE)
	// 	return (RED_WHITE);
	// else if ((chr & A_COLOR) == BLUE_BLACK_CH_TYPE)
	// 	return (BLUE_BLACK);
	// wprintw(win, "\nCHR: %d", chr);
	// wprintw(win, "\nCOLOR: %d", (chr & (short)A_COLOR));
	// wprintw(win, "\nATTR: %d", (chr & (short)A_ATTRIBUTES));
	// wprintw(win, "\nCHARTEXT: %d", (chr & (short)A_CHARTEXT));
	// return (0);
}

int		main(void)
{
	WINDOW	*win;
	attr_t	current;
	short	color_pair;
	chtype	chr;

	initscr();
	curs_set(0);
	start_color();
	noecho();
	win = newwin(15, 15, 0, 0);
	refresh();
	init_pair(BLUE_BLACK, COLOR_BLUE, COLOR_BLACK);
	wattron(win, COLOR_PAIR(BLUE_BLACK));
	mvwprintw(win, 1, 1, "TEST");
	wattroff(win, COLOR_PAIR(BLUE_BLACK));
	wrefresh(win);
	getch();
	wmove(win, 1, 1);
	// attr_get(&current, &color_pair, NULL);
	chr = mvwinch(win, 1, 2);
	// wprintw(win, "%d\n", chr);
	// color_pair = (chr & A_COLOR) / 256;
	// if ((chr & COLOR_PAIR(1)) == COLOR_PAIR(1))
	// 	wprintw(win, "IS RED/BLACK");
	// wprintw(win, "%c", chr);
	// getch();
	// wprintw(win, "%d", get_color_pair(chr));
	color_pair = (chr & A_COLOR) / 256;
	getch();
	mvwchgat(win, 1, 1, 1, A_REVERSE, color_pair, NULL);
	wrefresh(win);
	getch();
	endwin();
}