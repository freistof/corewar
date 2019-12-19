/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   valid_seperators.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/14 12:31:33 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/14 12:31:33 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				valid_seperators(char *content, int arg_no)
{
	int			i;
	int			seperators;

	i = 0;
	seperators = 0;
	while (content[i] != '\0')
	{
		if (content[i] == ARG_SEPERATOR)
			seperators++;
		i++;
	}
	if (seperators == arg_no - 1)
		return (1);
	return (0);
}
