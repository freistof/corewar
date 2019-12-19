/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   swap_bits.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: fblom <marvin@codam.nl>                      +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/11 18:48:16 by fblom         #+#    #+#                 */
/*   Updated: 2019/12/11 18:48:16 by fblom         ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int			swap_bits(int number)
{
	number = ((number >> 24) & 0xff) |
			((number << 8) & 0xff0000) |
			((number >> 8) & 0xff00) |
			((number << 24) & 0xff000000);
	return (number);
}

int			swap_bits_two_byte(int number)
{
	number = ((number >> 8) & 0xff) |
			((number << 8) & 0xff00);
	return (number);
}

int			extract_bit(int n, int k, int p)
{
	if (p == 0)
		p = 7;
	else if (p == 1)
		p = 5;
	else if (p == 2)
		p = 3;
	return (((1 << k) - 1) & (n >> (p - 1)));
}
