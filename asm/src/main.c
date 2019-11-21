/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main_asm.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/23 18:26:40 by fblom         #+#    #+#                 */
/*   Updated: 2019/10/23 18:26:41 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			main(int argc, char **argv)
{
	int		fd;
	t_list	*list;

	fd = input_file_validation(argc, argv);
	list = save_data(fd);
	print_list(&list);
	while (1);
	return (0);
}
