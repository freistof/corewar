/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   disasm.h                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 16:45:15 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/11 16:45:16 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISASM_H
# define DISASM_H

# include <fcntl.h>

# include "libft.h"
# include "ft_printf/ft_printf.h"

# define USAGE					"Usage: ./disasm <sourcefile.cor>"
# define WRONG_EXTENSION		"Use .cor extension"
# define FILE_ERROR				"Cannot open file"
# define OUTPUT_ERROR			"Cannot create output file"
# define INCORRECT_MAGIC		"Magic number incorrect"
# define MISSING_NULLS			"Null bytes expected but not found"

# define COREWAR_EXEC_MAGIC		0xf383ea00

# define T_REG					1
# define T_DIR					2
# define T_IND					4

typedef struct				s_data
{
	int						opcode;
	int						codage;
	int						i;
}							t_data;

typedef struct				s_argval
{
	int						value;
	char					*label;
}							t_argval;

typedef struct				s_op
{
	char					*name;
	int						number_of_arguments;
	int						argtypes[3];
	t_argval				argvalues[3];
	int						opcode;
	int						cycles;
	char					*meaning;
	int						codage_octal;
	int						label_size;
	int						size;
	int						position;
}							t_op;

int							input_validation(int argc);

void						error(char *message);

void						disassembler(char *filename);

void						magic(int fd_in);
void						name(int fd_in, int fd_out);
void						null(int fd_in);
int							size(int fd_in);
void						comment(int fd_in, int fd_out);
void						exec_code(int fd_in, int fd_out, int size);
void						arguments(int fd_in, int fd_out, t_data *data);

int							swap_bits(int number);
int							swap_bits_two_byte(int number);

#endif
