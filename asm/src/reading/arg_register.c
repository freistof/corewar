/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arg_register.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 12:02:10 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/02 12:02:11 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		save_register(char *argument, t_list *item, int argno)
{
	(((t_op *)(item->content))->argvalues[argno]).value = ft_atoi(argument + 1);
	((t_op *)(item->content))->size += 1;
	ft_printf("current size: %i\n", ((t_op *)(item->content))->size);
}

int			check_register(char *argument)
{
	int		i;
	char	*digit_string;

	digit_string = ft_strmap(argument + 1, (char (*)(char)) &ft_isdigit);
	i = 0;
	while (argument[i + 1] != '\0')
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
