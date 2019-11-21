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

t_list *save_data(int fd)
{
	t_list *list;

	list = ft_lstnew(NULL, 0);
	save_name_and_commment(&list, fd);
	// save_opcodes(&list, fd);
	return (list);
}