/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   name.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 17:46:08 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/11 17:46:08 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void			comment(int fd_in, int fd_out)
{
	char		buf[2048 + 1];
	int			i;
	int			ret;

	ret = read(fd_in, buf, 2048);
	if (ret <= 0)
		exit(1);
	buf[2048] = '\0';
	write(fd_out, ".comment \"", 10);
	i = 0;
	while (buf[i] != '\0')
	{
		write(fd_out, &buf[i], 1);
		i++;
	}
	write(fd_out, "\"\n", 2);
}
