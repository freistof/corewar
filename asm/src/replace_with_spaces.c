/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   replace_with_spaces.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 15:51:49 by fblom         #+#    #+#                 */
/*   Updated: 2019/11/30 15:51:50 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		replace_with_spaces(char *string)
{
	int		i;

	i = 0;
	while (string[i] != '\0')
	{
		if (ft_isspace(string[i]) || string[i] == ',')
			string[i] = ',';
		i++;
	}
}
