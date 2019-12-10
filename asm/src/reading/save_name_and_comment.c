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

void			save_quote(t_list **list, char *content, int skip)
{
	t_list		*item;
	int			i;
	int			len;

	item = *list;
	i = 0;
	len = 0;
	content += skip;
	while (ft_isspace(content[i]))
		i++;
	if (content[i] == '"')
	{
		len = ft_strrchr(&content[i + 1], '"') - &content[i] - 1;
		item->content_size = len;
		item->content = ft_strndup(&content[i + 1], len);
		return ;
	}
	if (skip == 5)
		error(NO_NAME);
	else if (skip == 8)
		error(NO_COMMENT);
}

static void		save_content(t_list **list, char *content)
{
	t_list		*item;

	item = *list;
	if (ft_strnequ(content, ".name", 5))
	{
		item->content = ft_strdup(NAME_CMD_STRING);
		item->next = ft_lstnew(NULL, 0);
		item = item->next;
		save_quote(&item, content, 5);
	}
	if (ft_strnequ(content, ".comment", 8))
	{
		item->content = ft_strdup(COMMENT_CMD_STRING);
		item->next = ft_lstnew(NULL, 0);
		item = item->next;
		save_quote(&item, content, 8);
	}
}

static int		check_content(char *content, int *name, int *comment)
{
	content = ft_strtrim(content);
	if (!content || !ft_strlen(content))
		return (0);
	if (ft_strnequ(content, ".name", 5) && *name == 0)
	{
		*name = 1;
		free(content);
		return (1);
	}
	if (ft_strnequ(content, ".comment", 8) && *comment == 0)
	{
		*comment = 1;
		free(content);
		return (1);
	}
	free(content);
	return (0);
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

void			save_name_and_comment(t_list **list, int fd, int *line)
{
	static int	name;
	static int	comment;
	char		*content;
	int			ret;
	t_list		*item;

	item = *list;
	ret = 1;
	while (!name || !comment)
	{
		ret = get_next_line(fd, &content);
		if (!ret)
			break ;
		remove_comments(content);
		*line += 1;
		if (check_content(content, &name, &comment))
			save_content(&item, content);
		free(content);
		item = skip_to_end(&item);
	}
	if (!name)
		error(NO_NAME);
	if (!comment)
		error(NO_COMMENT);
}
