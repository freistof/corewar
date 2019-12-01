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
# define INCORRECT_ARG_COUNT	"Incorrect argument count"
# define INCORRECT_ARG_TYPE		"Incorrect argument type"

typedef union					u_argval
{
	int	value;
	char *label;
}								t_argval;

typedef struct					s_op
{
	char						*name;
	int							number_of_arguments;
	int							argtypes[3];
	t_argval					argvalues[3];
	int							opcode;
	int							cycles;
	char						*meaning;
	int							codage_octal;
	int							label_size;
}								t_op;

enum							e_bool
{
	true = 1,
	false = 0,
}								t_bool;

/*
** INPUT
*/

int								input_file_validation(int argc, char **argv);

/*
** SAVING THE DATA
*/

void							save_data(int fd, t_list **list);
void							save_name_and_commment(t_list **list, int fd);
void						 	save_opcodes(t_list **list, int fd);
int								check_arguments(t_list *item, char *content);

/*
** EDITING THE INPUT
*/

void							replace_with_spaces(char *string);
void							remove_comments(char *string);

/*
** PRINT FUNCTIONS FOR DEBUGGING
*/

void							print_list(t_list **list);

/*
** ERROR MESSAGE
*/

void							error(char *error_message);

#endif
