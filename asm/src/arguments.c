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

void		valid_argument(char **argsplit, t_list *item)
{
	int 	i;
	int		skip;
	int		type;

	i = 0;
	while (argsplit[i])
	{
		skip = 0;
		while (ft_isspace(argsplit[i][skip]))
			skip++;
		if (argsplit[i][0 + skip] == 'r')
			type = 0;
		else if (argsplit[i][0 + skip] == '%')
			type = 1;
		else
			type = 2;
		if (((t_op *)(item->content))->argtypes[i] & (1<<type))
			ft_printf("correct argument\n");
		else
			ft_printf("incorrect argument\n");
		i++;
	}
}

int			valid_argument_count(char **argsplit, int arg_no)
{
	int		i;

	i = 0;
	while (argsplit[i])
		i++;
	if (i == arg_no)
		return (1);
	return (0);
}

int			check_arguments(t_list *item, char *content)
{
	int		arg_no;
	int		i;
	char	**argsplit;

	arg_no = (((t_op *)(item->content))->number_of_arguments);
	argsplit = ft_strsplit(content, ',');
	i = 0;
	if (valid_argument_count(argsplit, arg_no))
		valid_argument(argsplit, item);
	else
		error(INCORRECT_ARG_COUNT);
	i = 0;
	content = 0;
	return (1);
}
