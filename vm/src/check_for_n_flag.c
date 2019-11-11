/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_for_n_flag.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 17:31:33 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/11 19:22:59 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Loops through the arg string, checking for the -n flag and updating
** each players's index
*/

static void	print_lazy_array(char **arr, int size)
{
	for (int i = 0; i < size; i++)
		ft_printf("ARRAY[%i]: %s\n", i, arr[i]);
}

static int	check_if_player(char *check, t_player **players, int num_players)
{
	int x;

	x = 0;
	while (x < num_players)
	{
		if (ft_strequ(check, players[x]->file_name))
			return (1);
		x++;
	}
	return (0);
}

static void	init_lazy_array(char **arr, int num_players)
{
	int x;

	x = 0;
	while (x < num_players)
	{
		arr[x] = NULL;
		x++;
	}
}

static int	find_player_id(t_player **players, char *str, int num_players)
{
	int x;

	x = 0;
	while (x < num_players)
	{
		if (ft_strequ(players[x]->file_name, str))
			return (players[x]->id);
		x++;
	}
	return (0);
}

static void	reorder_player_ids(t_player **players, int num_players, int *lazy_array)
{
	int x;
	int new_order[num_players]

	x = 0;
	while (x < num_players)
	{
		if (lazy_array[x] != 0)
			new_order[lazy_array[x]] = x + 1;
		x++;
	}
}

int			check_for_n(int argc, char **argv, t_player **players, \
int num_players)
{
	int		x;
	char	**lazy_way;
	int		lazy_array[4];
	int		current_id;

	// lazy_way = (char **)ft_memalloc(sizeof(char *) * num_players);
	// init_lazy_array(lazy_way, num_players);
	for (int i = 0; i < num_players; i++)
		lazy_array[i] = 0;
	x = 1;
	while (x < argc)
	{
		if (ft_strequ(argv[x], "-n"))
		{
			if (argv[x + 1])
				current_id = ft_atoi(argv[x + 1]);
			ft_printf("CURRENT ID: %d\n", current_id);
			if (argv[x + 1] && ft_is_string_numbers(argv[x + 1]) && \
				current_id <= num_players && argv[x + 2] \
				&& check_if_player(argv[x + 2], players, num_players) \
				&& lazy_array[current_id - 1] == 0)// lazy_way[current_id] == NULL)
				lazy_array[current_id - 1] = find_player_id(players, argv[x + 2], num_players);
				// lazy_way[current_id] = ft_strdup(argv[x + 2]);
			else
			{
				ft_printf("FAILED ON CHECK\n");
				return (0);
			}
		}
		x++;
	}
	reorder_player_ids(players, num_players, lazy_array);
	for (int i = 0; i < num_players; i++)
		ft_printf("ARR[%d]: %d\n", i, lazy_array[i]);
	// print_lazy_array(lazy_way, num_players);
	return (1);
}
