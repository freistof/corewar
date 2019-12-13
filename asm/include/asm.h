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
# define REGISTER_CHAR			'r'
# define DIRECT_CHAR			'%'
# define ARG_SEPERATOR			','
# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define NAME_CMD_STRING		".name"
# define COMMENT_CMD_STRING		".comment"

# define EXTENSION				".cor"
# define LEN_EXTENSION			ft_strlen(EXTENSION)

# define T_REG					1
# define T_DIR					2
# define T_IND					4

# define REG_CODE				0
# define DIR_CODE				1
# define IND_CODE				2

# define REG_NUMBER				16

# define PROG_NAME_LENGTH		(128)
# define COMMENT_LENGTH			(2048)
# define COREWAR_EXEC_MAGIC		0xea83f3

/*
** USAGE AND ERRORS
*/

# define USAGE					"Usage: ./asm <sourcefile.s>"
# define OUTPUT_MESSAGE			"Writing output program to"

# define FILE_ERROR				"Can't read source file: error"
# define SYNTAX_ERROR			"Syntax error in input file"
# define NO_NAME				"No name given: error"
# define NO_COMMENT				"No comment given: error"
# define INCORRECT_ARG_COUNT	"Incorrect argument count: error"
# define INCORRECT_ARG_TYPE		"Incorrect argument type: error"
# define ERR_FILE_CREATE		"Could not create file"
# define ERR_REGISTER_VAL		"Incorrect register value: error"
# define ERR_REGISTER			"Wrong register: error"
# define ERR_INDIRECT			"Wrong indirect: error"
# define ERR_DIRECT				"Wrong direct: error"
# define LABEL_NOT_FOUND		"Label not found: error"
# define NO_QUOTE_END			"Quote has no ending quotation mark: error"

typedef struct					s_argval
{
	unsigned long long			value;
	char						*label;
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
	int							size;
	int							position;
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
void							save_name_and_comment(t_list **list, int fd,\
								int *line);
void							save_instructions(t_list **list, int fd,\
								int *line, int *pos);
int								save_label(t_list *item, char *l, int *index);
void							save_direct(char *arg, t_list *it, int argno);
void							save_indirect(char *arg, t_list *it, int argno);
void							save_register(char *arg, t_list *it, int argno);

/*
** CHECKING THE DATA
*/

int								check_arguments(t_list *item, char *content);
int								check_direct(char *argument);
int								check_indirect(char *argument);
int								check_register(char *argument);
int								label_string(char *arg, char *allowed);
int								digit_string(char *arg);

/*
** EDITING THE INPUT
*/

void							replace_with_spaces(char *string);
void							remove_comments(char *string);
int								empty_line(char *content);

/*
** WRITING
*/

void							write_data(t_list *list, char *input_file);
void							write_magic(int fd);
void							write_name(int fd, t_list *list);
void							write_comment(int fd, t_list *list);
void							write_null(int fd);
void							write_size(int fd, t_list *list);
void							write_exec_code(int fd, t_list *list);

void							write_direct(int f, t_op *i, int a, t_list **h);
void							write_ind(int f, t_op *i, int a, t_list **h);
void							write_register(int f, t_op *i, int arg);

int								label_direct_value(char *l, t_list **h, int p);

/*
** BITS
*/

int								swap_bits(int number);
int								swap_bits_two_byte(int number);

/*
** PRINT FUNCTIONS FOR DEBUGGING
*/

void							print_list(t_list *list);

/*
** ERROR MESSAGE
*/

void							error(char *error_message);

#endif
