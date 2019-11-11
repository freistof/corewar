/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   print_functions.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: rcorke <rcorke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/11 17:25:21 by rcorke         #+#    #+#                */
/*   Updated: 2019/11/11 17:29:03 by rcorke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	print_code(t_player *player)
{
	for (int i = 0; i < player->code_size; i++)
	{
		if (i % 16 == 0 && i != 0)
			NL;
		ft_printf("%02x ", player->code[i]);
	}
}
