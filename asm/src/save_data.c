/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_data.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 14:19:17 by fblom         #+#    #+#                 */
/*   Updated: 2019/10/24 14:19:17 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**
*/

void	save_opcodes(t_list **list, char **file_content)
{
	;
}

/*
** function saves name and comment in first two list items
** moves pointer to end of name and comment
*/

void	save_name_and_commment(t_list **list, char **file_content)
{
	;
}

/*
** main function that creates list of name, comment and all opcodes
** all list items should be appended at the end of the list with ft_lstappend
** returns list to main
*/

t_list *save_data(char *file_content)
{
	t_list *head;
	t_list *list;

	head = ft_lstnew(NULL, 0);
	list = head;
	save_name_and_commment(&list, &file_content);
	save_opcodes(&list, &file_content);
	ft_printf("%s\n", file_content);
	return (list);
}
