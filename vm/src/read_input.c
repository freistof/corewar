/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   read_input.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 12:27:17 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/11 19:05:59 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int				ft_is_string_numbers(char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		if (!ft_isdigit(str[x]))
			return (0);
		x++;
	}
	return (1);
}

/*
** Checks whether arg is a flag (-n handled on 2nd loop through)
*/

static int		is_flag(char **argv, int *x, t_game *game, t_player **players)
{
	if (argv[*x])
	{
		if (ft_strequ(argv[*x], "-dump"))
		{
			if (argv[*x + 1] && ft_is_string_numbers(argv[*x + 1]))
			{
				game->dump = ft_atoi(argv[*x + 1]);
				*x += 1;
				return (1);
			}
		}
		else if (ft_strequ(argv[*x], "-n"))
		{
			if (argv[*x + 1] && ft_is_string_numbers(argv[*x + 1]))
				return (1);
		}
	}
	return (0);
}

/*
** Check if player and add it to players struct if so
*/

static int		is_player(char *str, t_player *player, int p_num)
{
	int		fd;
	int		read_value;
	int		file_size;
	char	buf[BUFF_SIZE];
	char	*file;
	char	*to_free;

	file = ft_strnew(0);
	if (str && ft_strequ(ft_strsub(str, ft_strlen(str) - 4, 4), ".cor"))
	{
		fd = open(str, O_RDONLY);
		if (fd < 0)
			return (0);
		else
		{
			read_value = read(fd, buf, BUFF_SIZE);
			file_size = 0;
			while (read_value > 0)
			{
				to_free = file;
				file = ft_strnjoin(file, buf, file_size, read_value);
				free(to_free);
				file_size += read_value;
				read_value = read(fd, buf, BUFF_SIZE);
			}
			player->file_size = file_size;
			player->file_name = ft_strdup(str);
			return (parse_player(file, player, p_num));
		}
	}
	return (0);
}

void	read_input(int argc, char **argv, t_player **players, t_game *game)
{
	int x;
	int	player_num;

	x = 1;
	player_num = 0;
	while (x < argc)
	{
		if (is_flag(argv, &x, game, players))
			x++;
		else if (is_player(argv[x], players[player_num], player_num))
		{
			game->num_players++;
			player_num++;
		}
		else
		{
			ft_printf("%s FAILED\n", argv[x]);
		// 	corewar_error(players, game);
		}
		x++;
	}
	check_for_n(argc, argv, players, game->num_players);
}
