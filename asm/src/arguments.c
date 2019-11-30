/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   arguments.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/30 15:11:50 by fblom         #+#    #+#                 */
/*   Updated: 2019/11/30 15:11:50 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		valid_argument(void)
{
	;
}

int			valid_argument_count(char **argsplit, int arg_no)
{
	int		i;

	i = 0;
	while (argsplit[i])
	{
		ft_printf("%s\n", argsplit[i]);
		i++;
	}
	ft_printf("i: %i\n", i);
	if (i == arg_no)
		return (1);
	return (0);
}

int			check_arguments(t_list *item, char *content)
{
	int		arg_no;
	int		i;
	char	**argsplit;

	ft_printf("content: %s\n", content);
	arg_no = (((t_op *)(item->content))->number_of_arguments);
	argsplit = ft_strsplit(content, ',');
	i = 0;
/*	while (argsplit[i])
	{
		ft_printf("%s + ", argsplit[i]);
		i++;
	}
	ft_printf("\n");*/
	if (valid_argument_count(argsplit, arg_no))
		;//ft_printf("valid\n");
	else
	{
		ft_printf("%s\n", (char *)(((t_op *)(item->content))->name));
		ft_printf("%i\n", (((t_op *)(item->content))->number_of_arguments));
		ft_printf("invalid\n");
	}
	i = 0;
	content = 0;
	return (1);
}
