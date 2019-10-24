/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   asm.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/23 18:27:21 by fblom         #+#    #+#                 */
/*   Updated: 2019/10/23 18:27:21 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "ft_printf/ft_printf.h"

# include <fcntl.h>

/*
** USAGE AND ERRORS
*/

# define USAGE "Usage: ./asm <sourcefile.s>"
# define FILE_ERROR "Can't read source file"

/*
** INPUT
*/

void	input(int argc, char **argv);
int		input_file_validation(int argc, char **argv);

#endif
