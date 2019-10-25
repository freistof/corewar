/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   skip_whitespaces.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/25 14:17:40 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/10/25 14:20:25 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void    skip_whitespaces(int *index, char *str)
{
    while (str[*index] == ' ' || str[*index] == '\t' || str[*index] == '\n')
        *index++;
}