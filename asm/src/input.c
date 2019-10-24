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

static int		input_file_validation(int argc, char **argv)
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

static char		*read_file(int fd)
{
	int		ret;
	char	buffer[BUFF_SIZE + 1];
	char	*temp;
	char	*file_content;

	ret = 1;
	file_content = ft_strnew(1);
	while (ret)
	{
		ret = read(fd, buffer, BUFF_SIZE);
		buffer[ret] = '\0';
		temp = ft_strjoin(file_content, buffer);
		free(file_content);
		file_content = temp;
	}
	return (file_content);
}

char			*input(int argc, char **argv)
{
	int		fd;
	char	*file_content;

	fd = input_file_validation(argc, argv);
	file_content = read_file(fd);
	ft_printf("%s\n", file_content);
	return (file_content);
}
