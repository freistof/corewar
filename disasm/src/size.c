/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   size.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 18:42:51 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/11 18:42:52 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

int			size(int fd_in)
{
	int		size;

	read(fd_in, &size, 4);
	size = swap_bits(size);
	return (size);
}
