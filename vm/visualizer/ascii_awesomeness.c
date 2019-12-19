/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ascii_awesomeness.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 16:50:50 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/12/13 14:54:28 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		put_ascii_art(WINDOW *win)
{
	wattron(win, COLOR_PAIR(5));
	mvwprintw(win, INFO_START_Y + 18, 7, SIG1);
	mvwprintw(win, INFO_START_Y + 19, 7, SIG2);
	mvwprintw(win, INFO_START_Y + 20, 7, SIG3);
	mvwprintw(win, INFO_START_Y + 21, 7, SIG4);
	mvwprintw(win, INFO_START_Y + 22, 7, SIG5);
	mvwprintw(win, INFO_START_Y + 23, 7, SIG6);
	mvwprintw(win, INFO_START_Y + 24, 4, SIG7);
	mvwprintw(win, INFO_START_Y + 24, 47, SIG8);
	mvwprintw(win, INFO_START_Y + 25, 4, SIG9);
	mvwprintw(win, INFO_START_Y + 25, 47, SIG10);
	mvwprintw(win, INFO_START_Y + 26, 4, SIG11);
	mvwprintw(win, INFO_START_Y + 26, 47, SIG12);
	mvwprintw(win, INFO_START_Y + 27, 4, SIG13);
	mvwprintw(win, INFO_START_Y + 27, 47, SIG14);
	mvwprintw(win, INFO_START_Y + 28, 4, SIG15);
	mvwprintw(win, INFO_START_Y + 28, 47, SIG16);
	mvwprintw(win, INFO_START_Y + 29, 4, SIG17);
	mvwprintw(win, INFO_START_Y + 29, 47, SIG18);
	wattroff(win, COLOR_PAIR(5));
}
