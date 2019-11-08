/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 12:39:27 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/11/07 13:47:25 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include "ft_printf/ft_printf.h"

enum				e_bool
{
	false = 0,
	true = 1,
}					t_bool;

typedef struct		s_player
{
	int				id;
	char			*name;
	char			*comment;
	int				code_size;
	int				*code;
}					t_player;

typedef struct		s_game
{
	int				*board;
	int				last_alive;
	int				cycle_counter;
	int				live_counter;
	int				cycles_to_die;
	int				check_counter;
	int				dump;
}					t_game;

typedef struct		s_cursor
{
	int				id;
	t_bool			carry;
	int				opcode;
	int				last_live;
	int				wait_cycle;
	int				position;
	int				jump;
	int				registry[16];
	struct s_cursor	*next;
}					t_cursor;

#endif