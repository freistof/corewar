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
	magic = ((magic>>24)&0xff) | // move byte 3 to byte 0
                    ((magic<<8)&0xff0000) | // move byte 1 to byte 2
                    ((magic>>8)&0xff00) | // move byte 2 to byte 1
                    ((magic<<24)&0xff000000); // byte 0 to byte 3
	write(fd, &magic, 4);
}
