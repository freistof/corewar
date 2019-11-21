/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   asm.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/23 18:27:21 by fblom          #+#    #+#                */
/*   Updated: 2019/10/28 13:05:40 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "ft_printf/ft_printf.h"

# include <fcntl.h>

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"
# define LABEL_CHAR				':'
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)

# define T_REG					1
# define T_DIR					2
# define T_IND					4

# define LABEL_CHARS			"abcdefghijklmnopqrstuvwxyz_0123456789"

/*
** USAGE AND ERRORS
*/

# define USAGE					"Usage: ./asm <sourcefile.s>"
# define FILE_ERROR				"Can't read source file"
# define SYNTAX_ERROR			"Syntax error in .s file"
# define NO_NAME				"No name given"
# define NO_COMMENT				"No comment given"

typedef struct					s_op
{
	char						*name;
	short						opcode;
	int							arguments[3];
	int							something;
	int							something_else;
	char						*meaning;
	int							something_other;
	int							something_new;
}								t_op;

enum							e_bool
{
	true = 0,
	false = 1,
}								t_bool;

enum							e_value_type
{
	value = 1,
	label = 2,
};

typedef struct					s_command
{
	int							opcode;
	int							codage_octal;
	int							arg_type[3];
	int							type_value;
	void						*value;
}								t_command;

/*
** INPUT
*/

int								input_file_validation(int argc, char **argv);

/*
** SAVING THE DATA
*/

t_list							*save_data(int fd);
void							save_name_and_commment(t_list **list, int fd);
void						 	save_opcodes(t_list **list, int fd);

/*
** PRINT FUNCTIONS FOR DEBUGGING
*/

void							print_list(t_list **list);

/*
** ERROR MESSAGE
*/

void							error(char *error_message);

#endif
