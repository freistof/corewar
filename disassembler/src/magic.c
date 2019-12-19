/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   magic.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 17:09:35 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/11 17:09:35 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void			magic(int fd_in)
{
	unsigned int	read_magic;
	int				ret;

	ret = read(fd_in, &read_magic, 4);
	if (ret <= 0)
		exit(1);
	if (read_magic == COREWAR_EXEC_MAGIC)
		return ;
	else
		error(INCORRECT_MAGIC);
}
