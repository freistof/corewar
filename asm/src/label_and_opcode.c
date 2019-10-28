/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   label_and_opcode.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/25 15:41:23 by fblom         #+#    #+#                 */
/*   Updated: 2019/10/25 15:41:23 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		check_if_label(char *file_content, int *i)
{
	while (ft_strchr(LABEL_CHARS, file_content[*i]))
		*i += 1;
	if (file_content[*i] == LABEL_CHAR)
		return (1);
	return (0);
}

void	save_label(char *file_content, int *i)
{
	if (check_if_label(file_content, i))
	{
		;
	}
	else
		return ;
}

void	save_opcodes(void)
{
	return ;
}
