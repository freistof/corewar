/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   magic.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 14:23:13 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/02 14:23:13 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			write_magic(int fd)
{
	int		magic;

	magic = COREWAR_EXEC_MAGIC;
	magic = swap_bits(magic);
	write(fd, &magic, 4);
}
