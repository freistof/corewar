/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 12:27:17 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/16 15:39:45 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

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

static int		free_sub(char *str)
{
	if (str)
	{
		free(str);
		ft_putstr_fd("ERROR: Champions must be .cor files.\n\n", 2);
	}
	else
		ft_putstr_fd("ERROR: Non-existant champion.\n\n", 2);
	return (0);
}

/*
** Check and parse player
*/

static int		is_player(char *str, t_player *player, int p_num)
{
	int		fd;
	char	buf[BUFF_SIZE];
	char	*file;
	char	*sub_string;

	if (str && ft_strlen(str) > 4 && p_num < MAX_PLAYERS)
	{
		sub_string = ft_strsub(str, ft_strlen(str) - 4, 4);
		if (!ft_strequ(sub_string, ".cor"))
			return (free_sub(sub_string));
		free(sub_string);
		file = ft_strnew(0);
		fd = open(str, O_RDONLY);
		if (fd < 0)
			return (free_sub(NULL));
		else
		{
			player->file_size = read_player(fd, &file);
			player->file_name = ft_strdup(str);
			return (parse_player(file, player, p_num));
		}
	}
	else if (p_num >= MAX_PLAYERS)
		ft_putstr_fd("ERROR: Too many players.\n\n", 2);
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
