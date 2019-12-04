/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_bits.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/02 17:53:23 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/02 17:53:23 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int			swap_bits(int number)
{
	number = ((number>>24)&0xff) |
			((number<<8)&0xff0000) |
			((number>>8)&0xff00) |
			((number<<24)&0xff000000);
	return (number);			
}

int			swap_bits_two_byte(int number)
{
	number = ((number>>8)&0xff) |
			((number<<8)&0xff00);
	return (number);
}