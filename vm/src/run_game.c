/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_game.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 19:05:30 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/19 16:57:16 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"


void	kill_all_cursors(t_game *game, t_cursor *cursor)
{
	int			x;
	t_cursor	*to_free;
	
	x = 0;
	while (x < game->num_cursors)
	{
		to_free = cursor;
		cursor = cursor->next;
		ft_memdel((void **)&to_free);
		to_free = NULL;
		x++;
	}
	game->num_cursors = 0;
}

void	print_winner(t_game *game)
{
	int x;

	x = 0;
	while (x < game->num_players)
	{
		if (game->players[x]->alive == true)
			ft_printf("WINNER IS %s\n", game->players[x]->name);
		x++;
	}
}

void	finish_game(t_game *game, t_cursor *cursor)
{
	if (game->num_alive_players == 1)
		print_winner(game);
	else
		ft_printf("NO WINNERS M8\n");
	if (game->num_cursors > 0 && cursor)
		kill_all_cursors(game, cursor);
	free_players(game);
	free_game(game);
	exit(0);
}

void	kill_cursor(t_game *game, t_cursor *prev, t_cursor *cur, t_cursor *next)
{
	prev->next = next;
	ft_memdel((void **)&cur);
	cur = next;
	game->num_cursors -= 1;
	if (game->num_cursors == 1)
	{
		ft_memdel((void **)&cur);
		finish_game(game, NULL);
	}
	// for (int i = 0; i < game->num_cursors; i++)
	// {
	// 	print_cursor(cur);
	// 	cur = cur->next;
	// }
}

/*
** Check if players reported live in last cycles to die, kill if they didn't
*/
void	check_players(t_game *game, t_cursor *cursor)
{
	int x;

	x = 0;
	while (x < game->num_players)
	{
		if (game->players[x]->last_reported_live < game->cycles_to_die)
			game->players[x]->alive = false;
		x++;
	}
	if (game->num_alive_players == 1 || game->num_alive_players == 0)
		finish_game(game, cursor);
}

/*
** Check cycles to die, kill all relevant cursors, modify cycles to die
*/
void	check(t_game *game, t_cursor *keep_cursor)
{
	int			x;
	t_cursor	*cursor;
	t_cursor	*prev;
	t_cursor	*next;

	cursor = keep_cursor;
	if (game->max_cycles_to_die == 0)
	{
		return (kill_all_cursors(game, cursor));
	}
	x = 1;
	prev = cursor;
	cursor = prev->next;
	next = cursor->next;
	// ft_printf("CYCLES TO DIE: %d\tnum lives reported: %d\n", game->max_cycles_to_die, game->num_lives_reported);
	while (x < game->num_cursors)
	{
		if (cursor && cursor->last_live > game->max_cycles_to_die)
		{
			// HERE;
			kill_cursor(game, prev, cursor, next);
		}
		cursor = cursor->next;
		x++;
	}
	if (game->num_lives_reported > NBR_LIVE)
		game->max_cycles_to_die -= CYCLE_DELTA;
	else if (game->check_counter == MAX_CHECKS)
	{
		// ft_printf("REDUCING CTD, CHECKCTR == MAX CHECKS\n");
		game->max_cycles_to_die -= CYCLE_DELTA;
	}
	game->check_counter = 0;
	game->num_lives_reported = 0;
	check_players(game, cursor);
	game->cycles_to_die = 0;
}

void	execute_op_2(t_game *game, t_cursor *cursor)
{
	if (cursor->opcode == 11)
		op_storei(game, cursor);
	else if (cursor->opcode == 12)
		op_fork(game, cursor);
	else if (cursor->opcode == 13)
		op_lload(game, cursor);
	else if (cursor->opcode == 14)
		op_lloadi(game, cursor);
	else if (cursor->opcode == 15)
		op_lfork(game, cursor);
	else if (cursor->opcode == 16)
		op_aff(game, cursor);
}

void	execute_op(t_game *game, t_cursor *cursor)
{
	if (cursor->opcode == 1)
		op_live(game, cursor);
	else if (cursor->opcode == 2)
		op_load(game, cursor);
	else if (cursor->opcode == 3)
		op_store(game, cursor);
	else if (cursor->opcode == 4)
		op_add(game, cursor);
	else if (cursor->opcode == 5)
		op_subtract(game, cursor);
	else if (cursor->opcode == 6)
		op_and(game, cursor);
	else if (cursor->opcode == 7)
		op_or(game, cursor);
	else if (cursor->opcode == 8)
		op_xor(game, cursor);
	else if (cursor->opcode == 9)
		op_jump(game, cursor);
	else if (cursor->opcode == 10)
		op_loadi(game, cursor);
	else
		execute_op_2(game, cursor);
}

void	cursor_jump(t_cursor *cursor)
{
	// ft_printf("jump: %d\n", cursor->jump);
	cursor->position = (cursor->position + cursor->jump) % MEM_SIZE;
	cursor->jump = 1;
}

void	check_cursor(t_game *game, t_cursor *cursor)
{
	if (cursor->wait_cycle > 0)
		cursor->wait_cycle -= 1;
	if (cursor->wait_cycle == 0)
	{
		// ft_printf("CURSOR ID: %d\tPOSITION: %d\tOPCODE %d\n", cursor->id, cursor->position, cursor->opcode);
		// ft_printf("CURSOR ID: %d\tPOSITION: %d\tOPCODE %d\n", cursor->id, cursor->position, cursor->opcode);
		execute_op(game, cursor);
		cursor_jump(cursor);
		cursor->opcode = game->board[cursor->position];
		set_wait_cycle(cursor);
	}
}

void	main_loop(t_game *game, t_cursor *cursor)
{
	int x;
	// static int stat;

	while (1)
	{
		// ft_printf("CURSOR ID: %d\tPOSITION: %d\n", cursor->id, cursor->position);		
		x = 0;
		if (game->cycle_counter == game->dump)
		{
			hex_dump(game->board);
			finish_game(game, cursor);
		}
		if (game->cycles_to_die == game->max_cycles_to_die)
			check(game, cursor);
		while (x < game->num_cursors)
		{
			check_cursor(game, cursor);
			cursor = cursor->next;
			x++;
		}
		game->cycle_counter += 1;
		game->cycles_to_die += 1;
		// stat++;
		// if (stat > 100)
		// {
		// 	hex_dump(game->board);
		// 	exit(1);
		// }
	}
}

void	run_game(t_game *game, t_player **players, t_cursor *cursor)
{
	game->last_reported_live = cursor->id;
	game->cycle_counter = 0;
	game->max_cycles_to_die = CYCLE_TO_DIE;
	game->cycles_to_die = 0;
	game->num_cursors = game->num_players;
	game->num_alive_players = game->num_players;
	game->num_lives_reported = 0;
	game->check_counter = 0;
	// for (int i = 0; i < 4; i++)
	// {
	// 	print_cursor(cursor);
	// 	cursor = cursor->next;
	// }
	main_loop(game, cursor);
}
