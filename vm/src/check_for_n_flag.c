/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_for_n_flag.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 17:31:33 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/12 18:29:25 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** Loops through the arg string, checking for the -n flag and updating
** each players's index. Reorders players array with updated IDs.
*/

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

static char	*find_player_name(t_player **players, int this_id, int num_players)
{
	int x;

	x = 0;
	while (x < num_players)
	{
		if (players[x]->id == this_id)
			return (players[x]->file_name);
		x++;
	}
	return (NULL);
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

static void	swap_players(t_player **player_one, t_player **player_two)
{
	t_player *temp;
	// t_player *to_free;

	temp = *player_one;
	*player_one = *player_two;
	*player_two = temp;
	// temp = (t_player *)ft_memalloc(sizeof(temp));
	// temp->code_size = (*player_one)->code_size;
	// temp->file_size = (*player_one)->file_size;
	// temp->id = (*player_one)->id;
	// temp->code = (unsigned char *)ft_memalloc(sizeof(unsigned char) * temp->code_size);
	// ft_memcpy(temp->code, (*player_one)->code, temp->code_size);
	// temp->comment = (char *)ft_memalloc(sizeof(char) * COMMENT_LENGTH + 1);
	// ft_memcpy(temp->comment, (*player_one)->comment, COMMENT_LENGTH);
	// temp->file_name = ft_strdup((*player_one)->file_name);
	// temp->name = (char *)ft_memalloc(sizeof(char) * PROG_NAME_LENGTH + 1);
	// ft_memcpy(temp->name, (*player_one)->name, PROG_NAME_LENGTH);

	// (*player_one)->code_size = (*player_two)->code_size;
	// (*player_one)->file_size = (*player_two)->file_size;
	// (*player_one)->id = (*player_two)->id;
	// ft_memdel((void **)&(*player_one)->code);
	// HERE;
	// (*player_one)->code = (unsigned char *)ft_memalloc(sizeof(unsigned char) * (*player_one)->code_size);
	// ft_memcpy((*player_one)->code, (*player_two)->code, (*player_one)->code_size);
	// ft_memdel((void **)&(*player_one)->comment);
	// (*player_one)->comment = (char *)ft_memalloc(sizeof(char) * COMMENT_LENGTH + 1);
	// ft_memcpy((*player_one)->comment, (*player_two)->comment, COMMENT_LENGTH);
	// ft_memdel((void **)&(*player_one)->file_name);
	// (*player_one)->file_name = ft_strdup((*player_two)->file_name);
	// ft_memdel((void **)&(*player_one)->name);
	// (*player_one)->name = (char *)ft_memalloc(sizeof(char) * PROG_NAME_LENGTH + 1);
	// ft_memcpy((*player_one)->name, (*player_two)->name, PROG_NAME_LENGTH);

	// ft_memdel((void **)&(*player_two));
	// *player_two = temp;
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
	print_players(players, num_players);
	while (x < num_players)
	{
		if (x + 1 != players[x]->id)
			swap_players(&(players[x]), &(players[players[x]->id]));
		// print_players(players, num_players);
		x++;
	}
	print_players(players, num_players);
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
			if (current_id <= num_players && current_id > 0 && argv[x + 2] \
				&& check_if_player(argv[x + 2], players, num_players) \
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
