/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   initialise_struct.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 12:39:39 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/02 12:39:40 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		initaliase_values_to_null(t_list *item)
{
	(((t_op *)(item->content))->argvalues[0].value) = 0;
	(((t_op *)(item->content))->argvalues[1].value) = 0;
	(((t_op *)(item->content))->argvalues[2].value) = 0;
	(((t_op *)(item->content))->argvalues[0].label) = NULL;
	(((t_op *)(item->content))->argvalues[1].label) = NULL;
	(((t_op *)(item->content))->argvalues[2].label) = NULL;
}
