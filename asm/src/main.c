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
	char	*input_file;

	fd = input_file_validation(argc, argv);
	input_file = argv[argc - 1];
	list = ft_lstnew(NULL, 0);
	save_data(fd, &list);
	// print_list(list);
	write_data(list, input_file);
	while (1)
		;
	return (0);
}
