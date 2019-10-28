/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   asm.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/23 18:27:21 by fblom          #+#    #+#                */
/*   Updated: 2019/10/28 10:23:30 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "ft_printf/ft_printf.h"
# include "op.h"

# include <fcntl.h>

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

# define LABEL_CHAR				':'

/*
/*t_op	op_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};
*/

/*
** USAGE AND ERRORS
*/

# define USAGE "Usage: ./asm <sourcefile.s>"
# define FILE_ERROR "Can't read source file"
# define SYNTAX_ERROR "Syntax error in .s file"

/*
** ENUMS FOR ASSAMBLY
*/

enum	e_instructions
{
	live = 1,
	ld,
	st,
	add,
	sub,
	and,
	or,
	xor,
	zjmp,
	ldi,
	sti,
	fork,
	lld,
	lldi,
	lfork,
	aff
};

enum	e_bool
{
	true = 0,
	false = 1,
}			t_bool;

enum		e_value_type
{
	value = 1,
	label = 2,
};

enum			e_arguments
{
	T_REG = 1,
	T_DIR = 2,
	T_IND = 4,
};

typedef struct	s_command
{
	int			opcode;
	int			codage_octal;
	int			arg_type[3];
	int			type_value;
	void		*value;
}				t_command;

/*
** INPUT
*/

char			*input(int argc, char **argv);

/*
** SAVING THE DATA
*/

t_list *save_data(char *file_content);
void	save_name_and_commment(t_list **list, char **file_content);

void    skip_whitespaces(int *index, char *str);
t_list	*save_data(char *file_content);
void	save_instructions(t_list **head, char *file_content, int *i);
void	save_label(char *file_content, int *i);
void	save_opcode(void);
void	save_codage_octal(void);
void	save_argument_types(void);
void	save_label_or_value(void);
void	save_argument_values(void);
void	save_size(void);

#endif
