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

void		initaliase_values_to_null(t_list *item)
{
	(((t_op *)(item->content))->argvalues[0].value) = 0;
	(((t_op *)(item->content))->argvalues[1].value) = 0;
	(((t_op *)(item->content))->argvalues[2].value) = 0;
	(((t_op *)(item->content))->argvalues[0].label) = NULL;
	(((t_op *)(item->content))->argvalues[1].label) = NULL;
	(((t_op *)(item->content))->argvalues[2].label) = NULL;
}

/*void		save_indirect(char *argument, t_list *item)
{
	;
}

int			check_indirect(char *argument)
{
	return (1);
}

*/
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


void		save_register(char *argument, t_list *item, int argno)
{
	(((t_op *)(item->content))->argvalues[argno]).value = ft_atoi(argument + 1);
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

void		save_argument_value(char *argument, int type, t_list *item, int argno)
{
	char	*trimmed;

	remove_comments(argument);
	trimmed = ft_strtrim(argument);
	if (type == T_REG)
	{
		if (!check_register(trimmed))
			error("Wrong register\n");
		else
			save_register(trimmed, item, argno);
	}
	if (type == T_DIR)
	{
		if (!check_direct(trimmed + 1))
			error("Wrong direct\n");
		else
			save_direct(trimmed + 1, item, argno);
	}
	free(trimmed);
}

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
		type = argsplit[i][0 + skip];
		if (argsplit[i][0 + skip] == 'r')
			type = REG_CODE;
		else if (argsplit[i][0 + skip] == '%')
			type = DIR_CODE;
		else
			type = IND_CODE;
		if (((t_op *)(item->content))->argtypes[i] & (1<<type))
		{
			((t_op *)(item->content))->argtypes[i] = 1<<type;
			save_argument_value(argsplit[i], 1<<type, item, i);
		}
		else
			error(INCORRECT_ARG_TYPE);
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
	while (argsplit[i])
	{
		free(argsplit[i]);
		i++;
	}
	free(argsplit);
	return (1);
}
