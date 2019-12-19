/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input_validation.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 16:47:40 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/11 16:47:40 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

int				input_validation(int argc)
{
	if (argc != 2)
	{
		ft_printf("%s\n", USAGE);
		return (0);
	}
	return (1);
}
