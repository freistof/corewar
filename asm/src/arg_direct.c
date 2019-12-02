/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_direct.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 12:01:58 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/02 12:01:58 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		save_direct(char *argument, t_list *item, int argno)
{
	if (ft_isdigit(argument[0]) || argument[0] == '-')
		(((t_op *)(item->content))->argvalues[argno]).value = ft_atoi(argument);
	else
		(((t_op *)(item->content))->argvalues[argno]).label = ft_strdup(argument + 1);
}

int			check_direct(char *argument)
{
	int		i;
	char	*digit_string;

	digit_string = ft_strmap(argument, (char (*)(char)) &ft_isdigit);
	i = 1;
	if (argument[0] == ':')
	{
		while (argument[i])
		{
			if (!ft_strchr(LABEL_CHARS, argument[i]))
				return false;
			i++;
		}
	}
	else
	{
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
	}
	free(digit_string);
	return (true);
}
