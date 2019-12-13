/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 17:25:21 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/13 17:36:38 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

void	hex_dump(unsigned char *board)
{
	int x;

	x = 0;
	while (x < MEM_SIZE)
	{
		if (x % (HEX_DUMP_SIZE) == 0 && x != 0)
			NL;
		if (board[x] != 0)
			ft_printf("\033[0;31m");
		ft_printf("%02x \033[0m", board[x]);
		x++;
	}
	NL;
}
