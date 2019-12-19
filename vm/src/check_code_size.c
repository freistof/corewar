/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_code_size.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/18 14:42:08 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/18 14:42:30 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int			check_code_size(char *file, t_player *player, int *i)
{
	int		code_size;

	code_size = (unsigned char)file[*i] << 24;
	code_size += (unsigned char)file[*i + 1] << 16;
	code_size += (unsigned char)file[*i + 2] << 8;
	code_size += (unsigned char)file[*i + 3];
	if (code_size > (MEM_SIZE / 6))
		return (0);
	*i += 4;
	player->code_size = code_size;
	return (1);
}
