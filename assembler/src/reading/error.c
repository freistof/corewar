/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   error.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/21 15:01:58 by fblom         #+#    #+#                 */
/*   Updated: 2019/11/21 15:01:58 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		error(char *error_message)
{
	free_list(list_head(NULL));
	ft_printf("%s\n", error_message);
	exit(1);
}
