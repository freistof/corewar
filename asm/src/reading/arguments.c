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

static void	save_argument_value(char *argument, int type, t_list *item, int i)
{
	char	*trimmed;

	trimmed = ft_strtrim(argument);
	if (type == T_REG)
	{
		if (!check_register(trimmed))
			error("Wrong register: error");
		else
			save_register(trimmed, item, i);
	}
	if (type == T_DIR)
	{
		if (!check_direct(trimmed + 1))
			error("Wrong direct: error");
		else
			save_direct(trimmed + 1, item, i);
	}
	if (type == T_IND)
	{
		if (!check_indirect(trimmed))
			error("Wrong indirect: error");
		else
			save_indirect(trimmed, item, i);
	}
	free(trimmed);
}

static void	valid_argument(char **argsplit, t_list *item)
{
	int		i;
	int		type;

	i = 0;
	((t_op *)(item->content))->size = 1;
	if ((((t_op *)item->content))->codage_octal)
		(((t_op *)item->content))->size += 1;
	while (argsplit[i])
	{
		type = argsplit[i][0];
		if (argsplit[i][0] == 'r')
			type = REG_CODE;
		else if (argsplit[i][0] == '%')
			type = DIR_CODE;
		else
			type = IND_CODE;
		if (((t_op *)(item->content))->argtypes[i] & (1 << type))
		{
			((t_op *)(item->content))->argtypes[i] = 1 << type;
			save_argument_value(argsplit[i], 1 << type, item, i);
		}
		else
			error(INCORRECT_ARG_TYPE);
		i++;
	}
}

static int	valid_argument_count(char **argsplit, int arg_no)
{
	int		i;

	i = 0;
	while (argsplit[i])
		i++;
	if (i == arg_no || i == 0)
		return (1);
	return (0);
}

static char	**trim_split(char **argsplit)
{
	int		i;
	char	*temp;

	i = 0;
	while (argsplit[i])
	{
		temp = ft_strtrim(argsplit[i]);
		free(argsplit[i]);
		argsplit[i] = temp;
		i++;
	}
	return (argsplit);
}

int			check_arguments(t_list *item, char *content)
{
	int		arg_no;
	int		i;
	char	**argsplit;

	arg_no = (((t_op *)(item->content))->number_of_arguments);
	remove_comments(content);
	argsplit = ft_strsplit(content, ',');
	argsplit = trim_split(argsplit);
	i = 0;
	if (valid_argument_count(argsplit, arg_no))
		valid_argument(argsplit, item);
	else
		error(INCORRECT_ARG_COUNT);
	i = 0;
	while (argsplit[i])
	{
		free(argsplit[i]);
		i++;
	}
	free(argsplit);
	return (1);
}
