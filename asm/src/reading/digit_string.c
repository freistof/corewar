/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   digit_string.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/05 15:48:14 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/05 15:48:14 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				digit_string(char *argument)
{
	int			i;
	char		*digit_string;

	digit_string = ft_strmap(argument, (char (*)(char)) &ft_isdigit);
	i = 0;
	if (argument[i] == '-')
		i++;
	while (argument[i] != '\0')
	{
		if (digit_string[i] == '\0')
		{
			free(digit_string);
			return (false);
		}
		i++;
	}
	free(digit_string);
	return (true);
}
