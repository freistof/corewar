/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_label.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 12:19:17 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/02 12:19:17 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				save_label(t_list *item, char *line, int *index)
{
	int			i;
	int			start;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	if (!line || !ft_strlen(&line[i]))
		return (1);
	start = i;
	while (ft_strchr(LABEL_CHARS, line[i]))
		i++;
	if (line[i] == ':')
	{
		item->content_size = i;
		item->content = ft_strndup(line + start, i - start);
		i++;
		while (ft_isspace(line[i]))
			i++;
		*index = i;
		return (1);
	}
	return (0);
}
