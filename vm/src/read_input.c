/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 12:27:17 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/13 14:59:36 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Checks whether arg is a flag (-n handled on 2nd loop through)
*/

static int		is_flag(char **argv, int argc, int *x, t_game *game)
{
	if (argv[*x])
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
		else if (ft_strequ(argv[*x], "-n") && *x < argc - 2)
		{
			if (ft_is_string_numbers(argv[*x + 1]))
			{
				*x += 1;
				return (1);
			}
		}
	}
	return (0);
}

/*
** Read player into file and get size
*/

static int		read_player(int fd, char **file)
{
	char	buf[BUFF_SIZE];
	int		file_size;
	int		read_value;
	char	*to_free;

	read_value = read(fd, buf, BUFF_SIZE);
	while (read_value > 0)
	{
		to_free = *file;
		*file = ft_strnjoin(*file, buf, file_size, read_value);
		free(to_free);
		file_size += read_value;
		read_value = read(fd, buf, BUFF_SIZE);
	}
	return (file_size);
}

/*
** Check and parse player
*/

static int		is_player(char *str, t_player *player, int p_num)
{
	int		fd;
	char	buf[BUFF_SIZE];
	char	*file;

	if (str && ft_strlen(str) > 4 && ft_strequ(ft_strsub(str, ft_strlen(str) \
	- 4, 4), ".cor") && p_num < MAX_PLAYERS)
	{
		file = ft_strnew(0);
		fd = open(str, O_RDONLY);
		if (fd < 0)
			return (0);
		else
		{
			player->file_size = read_player(fd, &file);
			player->file_name = ft_strdup(str);
			return (parse_player(file, player, p_num));
		}
	}
	return (0);
}

void			read_input(int argc, char **argv, t_player **players, \
t_game *game)
{
	int x;

	x = 1;
	while (x < argc)
	{
		if (is_flag(argv, argc, &x, game))
			;
		else if (is_player(argv[x], players[game->num_players], \
		game->num_players))
			game->num_players++;
		else
			input_error(players, game);
		x++;
	}
	if (!check_for_n(argc, argv, players, game->num_players) || \
	game->num_players == 0)
		input_error(players, game);
}
