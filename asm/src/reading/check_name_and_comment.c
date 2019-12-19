/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_name_and_comment.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 12:02:18 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/19 12:02:19 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** Skips whitespaces, saves what's between quotation marks in the list
*/

static void		save_quote(t_list **list, char *content, int skip)
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
		if (!ft_strchrint(&content[i + 1], '"'))
			error(NO_QUOTE_END);
		len = ft_strrchr(&content[i + 1], '"') - &content[i] - 1;
		item->content_size = len;
		item->content = ft_strndup(&content[i + 1], len);
		check_length(skip, item->content);
		check_end(content, i, len);
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

	content = ft_strtrim(content);
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
	free(content);
}

/*
** Check if the string contains NAME_CMD_STRING or COMMENT_CMD_STRING
** If so, set integer to 1
*/

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

void			check_name_and_comment(char *content, t_list *item,\
										int *name, int *comment)
{
	if (check_content(content, name, comment))
		save_content(&item, content);
	else
	{
		remove_comments(content);
		if (!empty_line(content))
			error(SYNTAX_ERROR);
	}
}
