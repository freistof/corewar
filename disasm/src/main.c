/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 16:44:56 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/11 16:44:57 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

int			main(int argc, char **argv)
{
	if (!input_validation(argc))
		return (0);
	disassembler(argv[1]);
}
