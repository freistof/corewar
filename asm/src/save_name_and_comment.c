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

/*
** exits the program when there is a syntax error in .s file 
*/

void    syntax_error(void)
{
	ft_printf("%s", SYNTAX_ERROR);
	exit(1);
}

/*
** duplicates the string between quotation marks
*/

char    *get_quote(int *index, char *str)
{
	char	*quote;
	int		start;

	if (str[*index] != '"')
		syntax_error();
	*index += 1;
	start = *index;
	while (str[*index] != '"')
		*index += 1;
	quote = ft_strsub(str, start, *index - start);
	*index += 1;
	return (quote);
}

/*
** function saves name and comment in first two list items
** moves pointer to end of name and comment
*/

void	save_name_and_commment(t_list **list, char *file_content)
{
	int     index;
	t_list  *iterate;

	index = 5;
	iterate = *list;
	if (ft_strnequ(file_content, ".name", 5) == 0)
		syntax_error();
	skip_whitespaces(&index, file_content);
	iterate->content = get_quote(&index, file_content);
	if (ft_strlen(iterate->content) > PROG_NAME_LENGTH)
		syntax_error();
	skip_whitespaces(&index, file_content);
	if (ft_strnequ(&file_content[index], ".comment", 8) == 0)
		syntax_error();
	index += 8;
	skip_whitespaces(&index, file_content);
	iterate->next = ft_lstnew(get_quote(&index, file_content), 0);
	if (ft_strlen(iterate->next->content) > COMMENT_LENGTH)
		syntax_error();
	skip_whitespaces(&index, file_content);
}