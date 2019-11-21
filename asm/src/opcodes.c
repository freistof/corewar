/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opcodes.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 15:10:13 by fblom         #+#    #+#                 */
/*   Updated: 2019/11/21 15:10:13 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
extern t_op g_op_tab[17];

static void	save_instruction(t_list **list, char *content)
{
	(*list)->content = ft_strdup(content);
	(*list)->content_size = ft_strlen(content);
}

int			instruction(char *line)
{
 	int 		i;

	i = 0;
	while (g_op_tab[i].name)
	{
		if (ft_strstr(line, g_op_tab[i].name) == line)
			return (1);
		i++;
	}
	return (0);
}

void			save_opcodes(t_list **list, int fd)
{
	int			ret;
	char		*content;
	t_list		*iterate;
	int			i;

	iterate = *list;
	while (iterate->next)
		iterate = iterate->next;
	ret = 1;
	while (ret == 1)
	{
		i = 0;
		ret = get_next_line(fd, &content);
		if (ret == 0)
			break ;
		while (ft_isspace(content[i]))
			i++;
		if (instruction(&content[i]))
			save_instruction(&iterate, content);
		free(content);
		iterate->next = ft_lstnew(NULL, 0);
		iterate = iterate->next;
	}
}
