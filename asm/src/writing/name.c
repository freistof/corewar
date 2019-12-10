/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   name.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 15:58:06 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/02 15:58:06 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			write_name(int fd, t_list *list)
{
	char		name[PROG_NAME_LENGTH];
	int			i;

	while (list)
	{
		if (list->content && ft_strnstr(list->content, NAME_CMD_STRING, 5))
		{
			list = list->next;
			break ;
		}
		list = list->next;
	}
	ft_strcpy(name, list->content);
	i = ft_strlen(list->content);
	while (i < PROG_NAME_LENGTH)
	{
		name[i] = '\0';
		i++;
	}
	write(fd, name, PROG_NAME_LENGTH);
}
