/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_for_n_flag.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 17:31:33 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/13 14:31:03 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Loops through the arg string, checking for the -n flag and updating
** each players's index. Reorders players array with updated IDs.
*/

static void	init_new_ids_and_ctr(int *arr, int num_players, int *i)
{
	int x;

	x = 0;
	while (x < num_players)
	{
		arr[x] = -1;
		x++;
	}
	*i = 1;
}

static int	find_lowest_number_not_used(int num_players, int *new_order)
{
	int x;
	int j;

	x = 0;
	j = 1;
	while (x < num_players)
	{
		if (new_order[x] == j)
		{
			j++;
			x = -1;
		}
		x++;
	}
	return (j);
}

static int	swap_players(t_player **player_one, t_player **player_two)
{
	t_player *temp;

	temp = *player_one;
	*player_one = *player_two;
	*player_two = temp;
	return (-1);
}

static void	reorder_players(t_player **players, int num_players, \
int *new_order)
{
	int x;

	x = 0;
	while (x < num_players)
	{
		if (new_order[x] == -1)
			new_order[x] = find_lowest_number_not_used(num_players, new_order);
		x++;
	}
	x = 0;
	while (x < num_players)
	{
		players[new_order[x] - 1]->id = x + 1;
		x++;
	}
	x = 0;
	while (x < num_players)
	{
		if (x + 1 != players[x]->id)
			x = swap_players(&(players[x]), &(players[players[x]->id - 1]));
		x++;
	}
}

int			check_for_n(int argc, char **argv, t_player **players, \
int num_players)
{
	int		x;
	int		new_ids[4];
	int		current_id;

	init_new_ids_and_ctr(new_ids, num_players, &x);
	while (x < argc)
	{
		if (ft_strequ(argv[x], "-n"))
		{
			if (argv[x + 1] && ft_is_string_numbers(argv[x + 1]))
				current_id = ft_atoi(argv[x + 1]);
			else
				current_id = -1;
			if (current_id <= num_players && current_id > 0 && \
				check_if_player(argv[x + 2], players, num_players) \
				&& new_ids[current_id - 1] == -1)
				new_ids[current_id - 1] = find_player_id(players, \
				argv[x + 2], num_players);
			else
				return (0);
		}
		x++;
	}
	reorder_players(players, num_players, new_ids);
	return (1);
}
