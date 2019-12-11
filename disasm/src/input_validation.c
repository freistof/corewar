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

int				input_validation(int argc, char **argv)
{
	if (argc != 2)
	{
		ft_printf("%s\n", USAGE);
		return (0);
	}
	argv = NULL; // remove this
	return (1);
}
