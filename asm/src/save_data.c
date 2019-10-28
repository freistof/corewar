/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:19:17 by fblom          #+#    #+#                */
/*   Updated: 2019/10/28 10:23:48 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** main function that creates list of name, comment and all opcodes
** all list items should be appended at the end of the list with ft_lstappend
** returns list to main
*/

t_list *save_data(char *file_content)
{
	t_list *head;
	t_list *list;
	int i;

	i = 0;
	head = ft_lstnew(NULL, 0);
	list = head;
	save_name_and_commment(&list, &file_content);
	save_opcodes(&list, &file_content);
	ft_printf("%s\n", file_content);
	save_instructions(&list, file_content, &i);
	return (list);
}