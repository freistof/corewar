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
** main function that creates list of name, comment and all opcodes
** all list items should be appended at the end of the list with ft_lstappend
** returns list to main
*/

void	save_data(int fd, t_list **head)
{
	int	line;

	line = 1;
	save_name_and_comment(head, fd, &line);
	save_instructions(head, fd, &line);
}
