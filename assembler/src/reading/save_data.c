/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:19:17 by fblom          #+#    #+#                */
/*   Updated: 2019/10/28 13:07:22 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Initialises line number and position
** Calls function that will save name and comment
** Call function that will save instructions
*/

void	save_data(int fd, t_list **head)
{
	int	line;
	int	position;

	line = 1;
	position = 0;
	save_name_and_comment(head, fd, &line);
	save_instructions(head, fd, &line, &position);
}
