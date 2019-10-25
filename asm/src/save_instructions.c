/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   save_instructions.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/25 14:34:09 by fblom         #+#    #+#                 */
/*   Updated: 2019/10/25 14:34:09 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**
*/

void	save_instructions(t_list **head, char *file_content, int *i)
{
	t_list *list;

	list = *head;
	while (file_content[*i] != '\0')
	{
		save_label(file_content, i);
/*		save_opcode();
		save_codage_octal();
		save_argument_types();
		save_label_or_value();
		save_argument_values();
		save_size();*/
		(*i)++;
	}
}
