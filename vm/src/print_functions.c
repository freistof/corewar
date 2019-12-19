/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 17:25:21 by rcorke         #+#    #+#                */
/*   Updated: 2019/12/19 13:33:03 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../include/vm.h"

void	hex_dump(unsigned char *board)
{
	int	x;
	int	line;

	x = 0;
	line = 0;
	while (x < MEM_SIZE)
	{
		if (x == 0)
		{
			ft_printf("0x%04x : ", line * HEX_DUMP_SIZE);
			line++;
		}
		if (x % (HEX_DUMP_SIZE) == 0 && x != 0)
		{
			ft_printf("\n0x%04x : ", line * HEX_DUMP_SIZE);
			line++;
		}
		if (board[x] != 0)
			ft_printf("\033[0;31m");
		ft_printf("%02x \033[0m", board[x]);
		x++;
	}
	ft_printf("\n");
}
