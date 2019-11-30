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
	t_list *item;

	item = *list;
	item->content = malloc(sizeof(t_op));
	ft_memcpy((void *)item->content, (void *)&g_op_tab[opcode - 1], sizeof(t_op));
	item->content_size = sizeof(t_op);
	check_arguments(item, content);
}

int			instruction(char *line, int *opcode, int *index)
{
	int 		i;
	int			correct;

	i = 0;
	while(ft_isspace(*line))
		line++;
	correct = 0;
	i = 0;
	while (i < 16)
	{
		if (ft_strnequ(line, g_op_tab[i].name, ft_strlen(g_op_tab[i].name)))
		{
			*opcode = g_op_tab[i].opcode;
			correct = 1;
		}
		i++;
	}
	if (correct)
		*index += ft_strlen(g_op_tab[*opcode - 1].name) + 1;
	return (correct);
}

void			check_for_label(t_list *item, char *line, int *index)
{
	int			i;

	i = 0;
	while (ft_isspace(line[i]))
		i++;
	while (ft_strchr(LABEL_CHARS, line[i]))
		i++;
	if (line[i] == ':')
	{
		item->content_size = i;
		item->content = ft_strndup(line, i);
		i++;
		while (ft_isspace(line[i]))
			i++;
		*index = i;
	}
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
		if (ret == 0 || !content)
			break ;
		check_for_label(iterate, content, &i);
		iterate->next = ft_lstnew(NULL, 0);
		iterate = iterate->next;
		if (instruction(&content[i], &opcode, &i) == 1)
			save_instruction(&iterate, &content[i], opcode);
		free(content);
		iterate->next = ft_lstnew(NULL, 0);
		iterate = iterate->next;
	}
}
