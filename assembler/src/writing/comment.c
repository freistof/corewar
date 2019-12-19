/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   comment.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 16:39:40 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/02 16:39:40 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			write_comment(int fd, t_list *list)
{
	char		name[COMMENT_LENGTH];
	int			i;

	while (list)
	{
		if (list->content && ft_strnstr(list->content, COMMENT_CMD_STRING, 8))
		{
			list = list->next;
			break ;
		}
		list = list->next;
	}
	ft_strcpy(name, list->content);
	i = ft_strlen(list->content) + 1;
	while (i < COMMENT_LENGTH)
	{
		name[i] = '\0';
		i++;
	}
	write(fd, name, COMMENT_LENGTH);
}
