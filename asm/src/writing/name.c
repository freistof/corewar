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
	char		name[128];
	int			i;

	while (list)
	{
		if (ft_strnstr(list->content, NAME, 5))
		{
			list = list->next;
			break;
		}
		list = list->next;
	}
	ft_printf("name: %s\n", list->content);
	ft_strcpy(name, list->content);
	i = ft_strlen(list->content);
	while (i < 128)
	{
		name[i] = '\0';
		i++;
	}
	write(fd, name, 128);
}
