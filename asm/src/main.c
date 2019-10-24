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
	char	*file_content;
	t_list	*list;

	file_content = input(argc, argv);
	list = save_data(file_content);
	return (0);
}
