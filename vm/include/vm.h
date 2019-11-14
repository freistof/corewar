/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 12:39:27 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/11/14 17:17:09 by rcorke        ########   odam.nl         */
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

# define CYCLE_TO_DIE			1536
# define CYCLE_DELTA			50
# define NBR_LIVE				21
# define MAX_CHECKS				10
# define T_REG					1
# define T_DIR					2
# define T_IND					3

# define MIN_LONG_STR "-9223372036854775808"
# define MAX_LONG_STR "9223372036854775807"
# define HERE ft_putstr("here\n")
# define NL ft_putchar('\n')

enum				e_bool
{
	false = 0,
	true = 1,
}					t_bool;

typedef struct		s_op_args
{
	int arg1_type;
	int arg2_type;
	int arg3_type;
	int arg1_value;
	int arg2_value;
	int arg3_value;
}					t_op_args;

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
	t_player		**players;
	unsigned char	*board;
	long			dump;
	int				last_alive;
	int				cycle_counter;
	int				cycles_to_die;
	int				max_cycles_to_die;
	int				check_counter;
	int				num_players;
	int				last_reported_live;
	int				num_cursors;
	int				num_lives_reported;
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
void				read_input(int argc, char **argv, t_player **players, \
t_game *game);
int					parse_player(char *file, t_player *player, int \
player_num);

/*
** INPUT ERROR
*/
void				input_error(t_player **players, t_game *game);
void				usage(void);

/*
** LOOKUP PLAYER
*/
char				*find_player_name(t_player **players, int id, \
int num_players);
int					find_player_id(t_player **players, char *player_name, \
int num_players);
int					check_if_player(char *check, t_player **players, \
int num_players);

int					check_for_n(int argc, char **argv, t_player **players, \
int num_players);

/*
** DEBUG
*/
void				print_code(t_player *player);
void				print_players(t_player **players, int num_players);
void				hex_dump(unsigned char *board);
void				print_cursor(t_cursor *cursor);

/*
** ADD TO LIBFT
*/
int					ft_is_string_numbers(char *str);
long				ft_long_atoi(const char *str);
int					ft_fits_in_long(char *str);

/*
** INIT BOARD
*/
void				init_board(t_game *game, t_player **players);


/*
** RUN GAME
*/
void				run_game(t_game *game, t_player **players, t_cursor *cursor);


/*
** BYTE TO INT
*/
int					byte_to_int(unsigned char *board, int position);

/*
** GET OP ARGS
*/
t_op_args	*get_op_args(t_cursor *cursor, unsigned char *board);

# define USAGE1 "Usage: ./corewar [-dump N -n N] <champion1.cor> <...>\n"
# define USAGE2 "-dump N:\tDumps memory after N cycles then exits"
# define USAGE3 "\n-n N:\tSets player id\n"

#endif
