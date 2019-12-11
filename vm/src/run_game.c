/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   run_game.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/13 19:05:30 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/11 15:35:28 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	cursor_jump(t_cursor *cursor)
{
	cursor->position = (cursor->position + cursor->jump) % MEM_SIZE;
	cursor->jump = 1;
}

void	check_cursor(t_game *game, t_cursor *cursor)
{
	if (cursor->wait_cycle > 0)
		cursor->wait_cycle -= 1;
	if (cursor->wait_cycle == 0)
	{
		execute_op(game, cursor);
		cursor_jump(cursor);
		cursor->opcode = game->board[cursor->position];
		set_wait_cycle(cursor);
	}
}

void	main_loop(t_game *game, t_cursor *cursor)
{
	int x;
	int	cursor_c;

	while (1)
	{
		x = 0;
		cursor_c = game->num_cursors;
		if (game->cycle_counter == game->dump)
		{
			hex_dump(game->board);
			finish_game(game, cursor);
		}
		if (game->cycles_to_die >= game->max_cycles_to_die)
			check(game, cursor);
		while (x < game->num_cursors)
		{
			check_cursor(game, cursor);
			cursor = cursor->next;
			x++;
		}
		game->cycle_counter += 1;
		game->cycles_to_die += 1;
		if (game->vis)
			update_visual_info(game, cursor);
		// usleep(50000);
		// if (game->cycle_counter == 7201)
		// 	ft_printf("{209}NUMBER OF CURSORS : %d cycles: %d\n", game->num_cursors, game->cycle_counter);
		// if (game->cycle_counter == 8132)
		// 	ft_printf("{413}NUMBER OF CURSORS : %d cycles: %d\n", game->num_cursors, game->cycle_counter);
		// if (game->cycle_counter == 9391)
		// 	ft_printf("{941}NUMBER OF CURSORS : %d cycles: %d\n", game->num_cursors, game->cycle_counter);
		// if (game->cycle_counter == 10998)
		// 	ft_printf("{2373}NUMBER OF CURSORS : %d cycles: %d\n", game->num_cursors, game->cycle_counter);
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
	if (game->vis)
		init_visualizer(game, cursor);
	// hex_dump(game->board);
	main_loop(game, cursor);
}
