/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   opcode_three.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/17 15:33:30 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/12/12 13:37:26 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

/*
** JUMP, AFF, FORK, LFORK
*/

void			op_jump(t_game *game, t_cursor *cursor)
{
	if (cursor->carry == true)
	{
		cursor->jump = (short)byte_to_hex(game->board, cursor->position + 1);
	}
	else
		cursor->jump = 3;
}

void			op_aff(t_game *game, t_cursor *cursor)
{
	t_op_args	*args;
	int			value;

	args = get_op_args(cursor, game->board, 4);
	if (check_arg_types(args, ARG_REG, ARG_NOTHING, ARG_NOTHING))
	{
		value = get_arg_value(args->arg1_type, args->arg1_value, cursor, \
		game->board);
		ft_printf("%c", value);
	}
	ft_memdel((void **)&args);
}

static t_cursor	*copy_cursor(t_cursor *original)
{
	t_cursor	*new;
	int			x;

	new = (t_cursor *)ft_memalloc(sizeof(t_cursor));
	if (!new)
	{
		ft_printf("malloc error!\n");
		exit(1);
	}
	new->id = original->id;
	new->carry = original->carry;
	new->opcode = 0;
	new->last_live = original->last_live;
	new->wait_cycle = original->wait_cycle;
	new->jump = 0;
	x = 0;
	while (x < MAX_REGISTRIES)
	{
		new->registry[x] = original->registry[x];
		x++;
	}
	return (new);
}

void			op_fork(t_game *game, t_cursor *cursor)
{
	t_cursor	*new;
	t_cursor	*next;

	new = copy_cursor(cursor);
	new->position = (cursor->position + ((short)byte_to_hex(game->board, \
	cursor->position + 1) % IDX_MOD) % MEM_SIZE);
	next = cursor->next;
	cursor->next = new;
	new->next = next;
	cursor->jump = 3;
	game->num_cursors += 1;
}

void			op_lfork(t_game *game, t_cursor *cursor)
{
	t_cursor	*new;
	t_cursor	*next;

	new = copy_cursor(cursor);
	new->position = (cursor->position + (short)byte_to_hex(game->board, \
	cursor->position + 1)) % MEM_SIZE;
	next = cursor->next;
	cursor->next = new;
	new->next = next;
	cursor->jump = 3;
	game->num_cursors += 1;
}
