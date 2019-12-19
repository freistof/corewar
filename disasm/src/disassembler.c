/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   disassembler.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 17:08:04 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/11 17:08:04 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "disasm.h"

static char	*get_output_file(char *filename)
{
	int		fd;
	int		len;
	int		ext_start;
	char	*output_file;

	len = ft_strlen(filename);
	ext_start = len - 4;
	if (!ft_strequ(filename + ext_start, ".cor"))
		error(WRONG_EXTENSION);
	output_file = ft_strnew(len - 2);
	ft_strncpy(output_file, filename, len - 4);
	ft_strncpy(output_file + ext_start, ".d", 2);
	fd = open(output_file, O_TRUNC | O_CREAT | O_APPEND | O_RDWR, 0644);
	if (fd == -1)
		error(OUTPUT_ERROR);
	return (output_file);
}

static int	create_output_file(char *filename)
{
	int		fd;
	int		len;
	int		ext_start;
	char	*output_file;

	len = ft_strlen(filename);
	ext_start = len - 4;
	if (!ft_strequ(filename + ext_start, ".cor"))
		error(WRONG_EXTENSION);
	output_file = ft_strnew(len - 2);
	ft_strncpy(output_file, filename, len - 4);
	ft_strncpy(output_file + ext_start, ".d", 2);
	fd = open(output_file, O_TRUNC | O_CREAT | O_APPEND | O_RDWR, 0644);
	if (fd == -1)
		error(OUTPUT_ERROR);
	free(output_file);
	return (fd);
}

void		disassembler(char *filename)
{
	int		fd_input;
	int		fd_output;
	int		exec_size;
	char	*output_file;

	fd_input = open(filename, O_RDONLY);
	if (fd_input == -1)
		error(FILE_ERROR);
	fd_output = create_output_file(filename);
	output_file = get_output_file(filename);
	magic(fd_input);
	name(fd_input, fd_output);
	null(fd_input);
	exec_size = size(fd_input);
	comment(fd_input, fd_output);
	null(fd_input);
	exec_code(fd_input, fd_output, exec_size);
	ft_printf("Writing output to %s\n", output_file);
	free(output_file);
}
