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

/*
** Main function
** Gets file descriptor
** Creates list start in which all instructions and labels will be saved
** Calls function that will save the data
** Calls function that will write the data
*/

int			main(int argc, char **argv)
{
	int		fd;
	t_list	*list;
	char	*input_file;

	fd = input_file_validation(argc, argv);
	input_file = argv[argc - 1];
	list = ft_lstnew(NULL, 0);
	list_head(list);
	save_data(fd, &list);
	write_data(list, input_file);
	free_list(list);
	return (0);
}
