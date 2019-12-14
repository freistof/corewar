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

t_op g_op_tab[17] =
{
	{"live", 1, {T_DIR, 0, 0}, {0}, 1, 10, "alive", 0, 0, 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG, 0}, {0}, 2, 5, "load", 1, 0, 0, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, {0}, 3, 5, "store", 1, 0, 0, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, {0}, 4, 10, "addition", 1, 0, 0, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, {0}, 5, 10, "soustraction", 1, 0, 0, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, {0}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, 0, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, {0}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, 0, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, {0}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, 0, 0},
	{"zjmp", 1, {T_DIR, 0, 0}, {0}, 9, 20, "jump if zero", 0, 1, 0, 0},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, {0}, 10, 25,
		"load index", 1, 1, 0, 0},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, {0}, 11, 25,
		"store index", 1, 1, 0, 0},
	{"fork", 1, {T_DIR, 0, 0}, {0}, 12, 800, "fork", 0, 1, 0, 0},
	{"lld", 2, {T_DIR | T_IND, T_REG, 0}, {0}, 13, 10, "long load", 1, 0, 0, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, {0}, 14, 50,
		"long load index", 1, 1, 0, 0},
	{"lfork", 1, {T_DIR, 0, 0}, {0}, 15, 1000, "long fork", 0, 1, 0, 0},
	{"aff", 1, {T_REG, 0, 0}, {0}, 16, 2, "aff", 1, 0, 0, 0},
	{0, 0, {0}, {0}, 0, 0, 0, 0, 0, 0, 0}
};

static void		copy_instruction(t_list **list, char *content, int opcode,\
								int *pos)
{
	t_list *item;

	item = *list;
	item->content = malloc(sizeof(t_op));
	ft_memcpy((void *)item->content, (void *)&g_op_tab[opcode - 1],\
	sizeof(t_op));
	item->content_size = sizeof(t_op);
	check_arguments(item, content);
	(((t_op *)item->content))->position = *pos;
	*pos += (((t_op *)item->content))->size;
}

static int		check_instruction(char *line, int *opcode, int *index)
{
	int			i;
	int			correct;
	int			spaces;

	spaces = 0;
	while (ft_isspace(*line))
	{
		spaces++;
		line++;
	}
	correct = 0;
	i = 0;
	while (i < 16)
	{
		if (ft_strnequ(line, g_op_tab[i].name, ft_strlen(g_op_tab[i].name)) && \
			valid_instruction(*(line + ft_strlen(g_op_tab[i].name))))
		{
			*opcode = g_op_tab[i].opcode;
			correct = 1;
		}
		i++;
	}
	if (correct)
		*index += ft_strlen(g_op_tab[*opcode - 1].name) + spaces;
	return (correct);
}

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

void			save_instructions(t_list **list, int fd, int *line, int *pos)
{
	t_list		*item;
	char		*content;
	int			ret;
	int			i;
	static int	opcode;

	item = *list;
	while (1)
	{
		i = 0;
		ret = get_next_line(fd, &content);
		if (!ret)
			break ;
		remove_comments(content);
		*line += 1;
		save_label(item, content, &i);
		item = skip_to_end(&item);
		if (check_instruction(&content[i], &opcode, &i) == 1)
			copy_instruction(&item, &content[i], opcode, pos);
		else if (!empty_line(&content[i]))
			error(SYNTAX_ERROR);
		item = skip_to_end(&item);
		free(content);
	}
}
