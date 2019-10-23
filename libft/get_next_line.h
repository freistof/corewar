/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.h                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/25 13:24:43 by fblom         #+#    #+#                 */
/*   Updated: 2019/01/25 13:24:44 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"

# define BUFF_SIZE 42

typedef struct		s_line
{
	char			*string;
	int				fd;
	struct s_line	*next;
}					t_line;

int					get_next_line(const int fd, char **line);

#endif
