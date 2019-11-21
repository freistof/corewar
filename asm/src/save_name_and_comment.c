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

void 	save_quote(t_list **list, char *content, int skip)
{
	t_list *item;
	int		i;
	int		len;

	item = *list;
	i = 0;
	len = 0;
	content += skip;
	while (ft_isspace(content[i]))
		i++;
	if (content[i] == '"')
	{
		len = ft_strrchr(content, '"') - content;
		item->content_size = len;
		item->content = ft_strndup(&content[i], len);
		return ;
	}
	if (skip == 5)
		error(NO_NAME);
	else if (skip == 8)
		error(NO_COMMENT);
}

void	 save_name_and_commment(t_list **list, int fd)
{
	int		ret = 1;
	char 	*content;
	t_list 	*iterate;
	int		i;

	iterate = *list;
	while (ret == 1)
	{
		i = 0;
		ret = get_next_line(fd, &content);
		if (ret == 0)
			break ;
		while (ft_isspace(content[i]))
			i++;
		if (ft_strnequ(&content[i], ".name", 5))
			save_quote(&iterate, &content[i], 5);
		if (ft_strnequ(&content[i], ".comment", 8))
			save_quote(&iterate, &content[i], 8);
		free(content);
		iterate->next = ft_lstnew(NULL, 0);
		iterate = iterate->next;
	}
}
