/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   input.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 12:23:06 by fblom         #+#    #+#                 */
/*   Updated: 2019/10/24 12:23:09 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int		input_file_validation(int argc, char **argv)
{
	int		fd;

	if (argc == 1)
	{
		ft_printf("%s\n", USAGE);
		exit(1);
	}
	fd = open(argv[argc - 1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("%s %s\n", FILE_ERROR, argv[argc - 1]);
		exit(1);
	}
	return (fd);
}
