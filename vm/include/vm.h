/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   vm.h                                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/01 12:39:27 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/12/11 19:06:14 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include <fcntl.h>
# include <limits.h>
# include <stdbool.h>
# include <ncurses.h>
# include <time.h>
# include "../../libft/libft.h"
# include "../../libft/ft_printf/ft_printf.h"

# define USAGE1 "Usage: ./corewar [-dump N -n N -v -t N] <champion1.cor> <...>\n\n"
# define USAGE2 "FLAGS:\n-dump N:\tDumps memory after N cycles then exits"
# define USAGE3 "\n-n N:\t\tSets player id\n"
# define USAGE4 "-v:\t\tVisualizer\n"
# define USAGE5 "-t N:\t\tSets delay time (ms) between cycles for visualizer "
# define USAGE6 "if -v is activated (0 <= N < MAX_INT).\n"

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
# define MAX_REGISTRIES			16

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

# define ARG_NOTHING 0
# define ARG_REG 1
# define ARG_DIR 2
# define ARG_REG_OR_DIR 3
# define ARG_IND 4
# define ARG_REG_OR_IND 5
# define ARG_DIR_OR_IND 6
# define ARG_ANY 7

# define VISUAL_BOX_FIELD_X ((MEM_SIZE / 64) * 3 + 1)
# define VISUAL_BOX_FIELD_Y ((MEM_SIZE / 64) + 2)
# define VISUAL_BOX_INFO_X ((MEM_SIZE / 64) + 10)
# define VISUAL_BOX_INFO_Y ((MEM_SIZE / 64) + 2)
# define RESET_VISUAL_INFO	"                                        "
# define INFO_START_Y 33

/*
** NOTHING = 0					0
** REGISTER = 001				1
** DIRECT = 010					2
** REG | DIRECT = 011			3
** INDIRECT = 100				4
** REG | INDIRECT = 101			5
** IND | DIRECT = 110			6
** REG | IND | DIRECT = 111		7
*/

// enum				e_bool
// {
// 	false = 0,
// 	true = 1,
// }					t_bool;

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
	int				last_reported_live;
	bool			alive;
}					t_player;

typedef struct 		s_visual
{
	WINDOW			*field;
	WINDOW			*info;
}					t_visual;

typedef struct		s_game
{
	t_player		**players;
	t_visual		*visual;
	unsigned char	*board;
	long			dump;
	bool			vis;
	long			delay;
	int				cycle_counter;
	int				cycles_to_die;
	int				max_cycles_to_die;
	int				check_counter;
	int				num_players;
	int				num_alive_players;
	int				last_reported_live;
	int				num_cursors;
	int				num_lives_reported;
}					t_game;

typedef struct		s_cursor
{
	int				id;
	bool			carry;
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
void				print_code(t_player *player); //REMOVE
void				print_players(t_player **players, int num_players); //REMOVE
void				hex_dump(unsigned char *board);
void				print_cursor(t_cursor *cursor); //REMOVE
void				print_temp_board(unsigned char *board);	//REMOVE
void				print_winner(t_game *game);
void				print_registries(t_game *game, t_cursor *cursor); //REMOVE


/*
** ADD TO LIBFT
*/
int					ft_is_string_numbers(char *str);
long				ft_long_atoi(const char *str);
int					ft_fits_in_long(char *str);
/*SITTING IN ITS OWN FILE */
int					ft_fits_in_int(char *str);

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
int					byte_to_hex(unsigned char *board, int position);
unsigned char		*int_to_byte(int value);

/*
** GET OP ARGS
*/
t_op_args			*get_op_args(t_cursor *cursor, unsigned char *board, int dir_size);
int  				get_arg_value(int arg_type, int arg_value, t_cursor *cursor, unsigned char *board);
int					check_arg_types(t_op_args *args, int type1, int type2, int type3);


/*
** FREE
*/
void		free_player(t_player *player);
void		free_players(t_game *game);
void		free_game(t_game *game);

/*
** operations
*/
void				op_live(t_game *game, t_cursor *cursor);
void				op_add(t_game *game, t_cursor *cursor);
void				op_subtract(t_game *game, t_cursor *cursor);
void				op_store(t_game *game, t_cursor *cursor);
void				op_storei(t_game *game, t_cursor *cursor);
void				op_and(t_game *game, t_cursor *cursor);
void				op_or(t_game *game, t_cursor *cursor);
void        		op_xor(t_game *game, t_cursor *cursor);
void				op_jump(t_game *game, t_cursor *cursor);
void				op_aff(t_game *game, t_cursor *cursor);
void				op_fork(t_game *game, t_cursor *cursor);
void				op_lfork(t_game *game, t_cursor *cursor);
void				op_load(t_game *game, t_cursor *cursor);
void				op_loadi(t_game *game, t_cursor *cursor);
void				op_lload(t_game *game, t_cursor *cursor);
void				op_lloadi(t_game *game, t_cursor *cursor);

void				write_to_board(unsigned char *board, int position, unsigned char *byte);

/*
** SET WAIT CYCLE
*/
void				set_wait_cycle(t_cursor *cursor);

/*
** KILL CURSOR
*/
void				kill_all_cursors(t_game *game, t_cursor *cursor);
void				kill_cursor(t_game *game, t_cursor *prev, t_cursor **cur, t_cursor *next);

/*
** EXECUTE OP
*/
void				execute_op(t_game *game, t_cursor *cursor);

/*
** CHECK
*/
void				check(t_game *game, t_cursor *keep_cursor);

/*
** VISUALIZER
*/
void        		init_visualizer(t_game *game, t_cursor *cursor);
// void				update_visualizer(t_game *game, t_cursor *cursor);
void				update_visual_info(t_game *game, t_cursor *cursor);
void				update_visual_field(t_game *game, int position, int id);
void				put_ascii_art(WINDOW *win);
void				print_winner_vis(t_game *game);

/*
** FINISH GAME
*/
void				finish_game(t_game *game, t_cursor *cursor);


/*
** ASCII BONUS
*/
# define SIG1 "___.           ___________                                    "
# define SIG2 "\\_ |__ ___.__. \\_   _____/______  ____                 "
# define SIG3 " | __ <   |  |  |    __) \\_  __ \\/ __ \\               "
# define SIG4 " | \\_\\ \\___  |  |     \\   |  | \\|  ___/              "
# define SIG5 " |___  / ____|  \\___  /   |__|   \\___  > /\\           "
# define SIG6 "     \\/\\/           \\/               \\/  )/           "
# define SIG7 "__________.__       .__        ____    .____             "
# define SIG8 "\\______   \\__| ____ |  |__    /  _ \\   |    |    __ __  ____"
# define SIG9 " |       _/  |/ ___\\|  |  \\   >  _ </\\ |    |   |  |  \\/ ___\\"
# define SIG10 " |    |   \\  \\  \\___|   Y  \\ /  <_\\ \\/ |    |___|  |  |  \\___"
# define SIG11 " |____|_  /__|\\___  >___|  / \\_____\\ \\ |_______ \\____/ \\___  >"
# define SIG12 "        \\/        \\/     \\/         \\/         \\/          \\/ "

/*
** FIREWORKS BONUS
*/
#include <stddef.h>
#include <stdint.h>
#include <math.h>
typedef struct particle_t {
    float pos[2];
    float center[2];
    float vel[2];
    float life;
    uint8_t color;
    bool exploded;
}				particle;
void	fireworks(t_game *game);

#endif
