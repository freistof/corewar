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
	int			i;
	int			len;
	char		*output_file;

	len = ft_strlen(input_file);
	i = len - 1;
	while (input_file[i] != '.' && i > 0)
		i--;
	output_file = ft_strnew(i + LEN_EXTENSION + 1);
	output_file = ft_strncpy(output_file, input_file, i);
	output_file = ft_strcat(output_file, EXTENSION);
	return (output_file);
}

void			write_data(t_list *list, char *input_file)
{
	int			fd;
	char		*output_file;

	output_file = get_output_file(input_file);
	fd = open(output_file, O_TRUNC | O_CREAT | O_APPEND | O_RDWR, 0644);
	if (fd == -1)
		error(ERR_FILE_CREATE);
	write_magic(fd);
	write_name(fd, list);
	write_null(fd);
	write_size(fd, list);
	write_comment(fd, list);
	write_null(fd);
	write_exec_code(fd, list);
	ft_printf("%s %s\n", OUTPUT_MESSAGE, output_file);
	free(output_file);
}
