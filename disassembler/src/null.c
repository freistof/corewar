/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   null.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 18:33:37 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/11 18:33:37 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

void			null(int fd_in)
{
	int			reading;
	int			ret;

	ret = read(fd_in, &reading, 4);
	if (ret <= 0)
		exit(1);
	if (reading != 0)
		error(MISSING_NULLS);
}
