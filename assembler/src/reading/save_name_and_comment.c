/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_name_and_comment.c                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/25 14:11:20 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/10/28 13:07:40 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Move pointer to end of list and add a new item
*/

static t_list	*skip_to_end(t_list **list)
{
	t_list		*item;

	item = *list;
	while (item->next)
		item = item->next;
	item->next = ft_lstnew(NULL, 0);
	item = item->next;
	return (item);
}

void			save_name_and_comment(t_list **list, int fd, int *line)
{
	static int	name;
	static int	comment;
	char		*content;
	int			ret;
	t_list		*item;

	item = *list;
	while (!name || !comment)
	{
		ret = get_next_line(fd, &content);
		if (!ret)
			break ;
		*line += 1;
		check_name_and_comment(content, item, &name, &comment);
		free(content);
		item = skip_to_end(&item);
	}
	if (!name)
		error(NO_NAME);
	if (!comment)
		error(NO_COMMENT);
}
