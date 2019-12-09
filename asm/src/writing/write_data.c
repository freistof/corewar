/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   write_data.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 14:06:25 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/02 14:06:26 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*get_output_file(char *input_file)
{
	int			len;
	char		*output_file;

	ft_printf("input_file: %s\n", input_file);
	len = ft_strstr(input_file, ".") - input_file;
	output_file = (char *)malloc(sizeof(char) * len + 4 + 1);
	output_file = ft_strncpy(output_file, input_file, len);
	output_file = ft_strcat(output_file, ".cor");
	ft_printf("output_file: %s\n", output_file);
	return (output_file);
}

void			write_data(t_list *list, char *input_file)
{
	int			fd;
	char		*output_file;

	output_file = get_output_file(input_file);
	fd = open(output_file, O_TRUNC | O_CREAT | O_APPEND | O_RDWR, 0644);
	free(output_file);
	if (fd == -1)
		error("Could not create file\n");
	ft_printf("fd: %i\n", fd);
	write_magic(fd);
	write_name(fd, list);
	write_null(fd);
	write_size(fd, list);
	write_comment(fd, list);
	write_null(fd);
	write_exec_code(fd, list);
}
