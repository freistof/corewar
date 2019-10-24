/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstappend.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/24 15:17:10 by fblom         #+#    #+#                 */
/*   Updated: 2019/10/24 15:17:11 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend(t_list **alst, t_list *new)
{
	t_list *list = *alst;

	while (list->next)
		list = list->next;
	list->next = new;
}