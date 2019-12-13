/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   is_flag.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/12 14:00:13 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/13 18:00:37 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

/*
** Check dump or -t flag
*/

static int		check_dump_or_delay(char **argv, int argc, int *x, t_game *game)
{
	if (ft_strequ(argv[*x], "-dump") && *x < argc - 1)
	{
		if (ft_is_string_numbers(argv[*x + 1]) && \
		ft_fits_in_long(argv[*x + 1]))
		{
			game->dump = ft_long_atoi(argv[*x + 1]);
			*x += 1;
			return (1);
		}
	}
	else if (ft_strequ(argv[*x], "-t") && *x < argc - 1)
	{
		if (ft_is_string_numbers(argv[*x + 1]) && \
		ft_fits_in_int(argv[*x + 1]))
		{
			game->delay = ft_long_atoi(argv[*x + 1]);
			*x += 1;
			return (1);
		}
	}
	return (0);
}

/*
** Checks whether arg is a flag (-n handled on 2nd loop through)
*/

int				is_flag(char **argv, int argc, int *x, t_game *game)
{
	if (argv[*x])
	{
		if ((ft_strequ(argv[*x], "-dump") && *x < argc - 1) || \
		(ft_strequ(argv[*x], "-t") && *x < argc - 1))
			return (check_dump_or_delay(argv, argc, x, game));
		else if (ft_strequ(argv[*x], "-n") && *x < argc - 2)
		{
			if (ft_is_string_numbers(argv[*x + 1]))
			{
				*x += 1;
				return (1);
			}
		}
		else if (ft_strequ(argv[*x], "-v"))
		{
			game->vis = true;
			return (1);
		}
		else if (argv[*x][0] == '-')
		{
			ft_putstr_fd("ERROR: Incorrect flag.\n\n", 2);
			input_error(game->players, game);
		}
	}
	return (0);
}
