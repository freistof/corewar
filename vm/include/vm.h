/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 12:39:27 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/11/12 17:21:38 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <fcntl.h>
# include <limits.h>
# include "../../libft/libft.h"
# include "ft_printf/ft_printf.h"

# define MAX_PLAYERS			4
# define MEM_SIZE				(4*1024)
# define IDX_MOD				(MEM_SIZE / 8)
# define CHAMP_MAX_SIZE			(MEM_SIZE / 6)
# define MAGIC_BYTE_1			-22
# define MAGIC_BYTE_2			-125
# define MAGIC_BYTE_3			-13
# define MIN_PLAYER_FILE_SIZE	2192
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

# define HERE ft_putstr("here\n")
# define NL ft_putchar('\n')

enum				e_bool
{
	false = 0,
	true = 1,
}					t_bool;

typedef struct		s_player
{
	int				id;
	char			*name;
	char			*file_name;
	char			*comment;
	int				code_size;
	unsigned char	*code;
	int				file_size;
}					t_player;

typedef struct		s_game
{
	unsigned char	*board;
	int				last_alive;
	int				cycle_counter;
	int				live_counter;
	int				cycles_to_die;
	int				check_counter;
	int				dump;
	int				num_players;
}					t_game;

typedef struct		s_cursor
{
	int				id;
	enum e_bool		carry;
	int				opcode;
	int				last_live;
	int				wait_cycle;
	int				position;
	int				jump;
	int				registry[16];
	struct s_cursor	*next;
}					t_cursor;

void				init_game(t_game *game);
void				init_players(t_player **players);
void				read_input(int argc, char **argv, t_player **players, t_game *game);
int					parse_player(char *file, t_player *player, int player_num);



int			check_for_n(int argc, char **argv, t_player **players, \
int num_players);

//DEBUG
void				print_code(t_player *player);
void				print_players(t_player **players, int num_players);

//ADD TO LIBFT:
int					ft_is_string_numbers(char *str);
#endif
