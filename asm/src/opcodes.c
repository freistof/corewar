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

static void	save_instruction(t_list **list, char *content, int opcode)
{
	// t_op operation;
	t_list *item;

	item = *list;
	item->content = malloc(sizeof(t_op));
	ft_memcpy((void *)item->content, (void *)&g_op_tab[opcode], sizeof(t_op));
	item->content_size = sizeof(t_op);
	ft_strdup(content);
}

int			instruction(char *line, int *opcode)
{
	int 		i;

	i = 0;
	while (i < 16)
	{
		if (ft_strstr(line, g_op_tab[i].name) == line)
		{
			*opcode = i;
			return (1);
		}
		i++;
	}
	return (0);
}

void			save_opcodes(t_list **list, int fd)
{
	int			ret;
	char		*content;
	t_list		*iterate;
	int			opcode;
	int			i;

	iterate = *list;
	while (iterate->next)
		iterate = iterate->next;
	ret = 1;
	opcode = 0;
	while (ret == 1)
	{
		i = 0;
		ret = get_next_line(fd, &content);
		if (ret == 0)
			break ;
		while (ft_isspace(content[i]))
			i++;
		if (instruction(&content[i], &opcode) == 1)
			save_instruction(&iterate, content, opcode);
		else
		{
			ft_printf("continue\n");
			free(content);
			continue;
		}
		ft_printf("%s\n", ((t_op *)iterate->content)->name);
		free(content);
		iterate->next = ft_lstnew(NULL, 0);
		iterate = iterate->next;
	}
}
