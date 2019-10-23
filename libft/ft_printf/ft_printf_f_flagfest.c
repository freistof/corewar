/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   printf_d_flagfest.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: svan-win <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/04/13 03:10:51 by svan-win      #+#    #+#                 */
/*   Updated: 2019/04/18 17:20:57 by svan-win      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	put_one_d(char *str, double d)
{
	int i;

	i = ft_printf(str, d);
	ft_printf("i = %d\n", i);
}

static void	put_set_double(double d)
{
	put_one_d("\n-4printf: %0000 33...12..0+0f$\n", d);
	put_one_d("\n-3printf: %####0000 33...12..#0+0f$\n", d);
	put_one_d("\n-2printf: %####0000 33...12..5#0+0f$\n", d);
	put_one_d("\n-1printf: %####0000 33...12..5.#0+0f$\n", d);
	put_one_d("\n00printf: %####000033...12..5.#00f$\n", d);
	put_one_d("\n01printf: %###-#0000 33...12..#0+0f$\n", d);
	put_one_d("\n02printf: %###-#0000 33...12..5#0+0f$\n", d);
	put_one_d("\n03printf: %###-#0000 33...12..5.#0+0f$\n", d);
	put_one_d("\n04printf: %###-#0000 10..33...12..#0+0f$\n", d);
	put_one_d("\n05printf: %###-#0000 33...10  7..#0+0f$\n", d);
	put_one_d("\n06printf: %###-#0000 33...12..#0+0f$\n", d);
	put_one_d("\n07printf: %###-#0000 10..5..2.f$\n", d);
	put_one_d("\n08printf: %###-#0000 10+5#3.f$\n", d);
	put_one_d("\n09printf: %###-#0000 10+5#4f$\n", d);
	put_one_d("\n10printf: %###-#0000 33...12..#0+0Lf$\n", d);
	put_one_d("\n11printf: %###-#0000 33...12..#0+0lf$\n", d);
	put_one_d("\n12printf: %###-#0000 33...12..5#0+hlh0f$\n", d);
	put_one_d("\n13printf: %###-#0000 33...12..5.#0llhll+0f$\n", d);
	put_one_d("\n14printf: %###-#0000 10..33...12..#0+lll0f$\n", d);
	put_one_d("\n15printf: %###-#0000 33...10  7..#0+0Lf$\n", d);
	put_one_d("\n16printf: %###-#0000 33...10  7..2#0+0Lf$\n", d);
	put_one_d("\n17printf: %###-#0000 33...10  7..2#0+0f$\n", d);
	put_one_d("\n18printf: %Lf$\n", d);
}

static void	put_one(char *str, long double d)
{
	int i;

	i = ft_printf(str, d);
	ft_printf("i = %d\n", i);
}

static void	put_set(long double d)
{
	put_set_double((double)d);
	put_one("\n-4printf: %0000 33...12..0+0f$\n", d);
	put_one("\n-3printf: %####0000 33...12..#0+0f$\n", d);
	put_one("\n-2printf: %####0000 33...12..5#0+0f$\n", d);
	put_one("\n-1printf: %####0000 33...12..5.#0+0f$\n", d);
	put_one("\n00printf: %####000033...12..5.#00f$\n", d);
	put_one("\n01printf: %###-#0000 33...12..#0+0f$\n", d);
	put_one("\n02printf: %###-#0000 33...12..5#0+0f$\n", d);
	put_one("\n03printf: %###-#0000 33...12..5.#0+0f$\n", d);
	put_one("\n04printf: %###-#0000 10..33...12..#0+0f$\n", d);
	put_one("\n05printf: %###-#0000 33...10  7..#0+0f$\n", d);
	put_one("\n06printf: %###-#0000 33...12..#0+0f$\n", d);
	put_one("\n07printf: %###-#0000 10..5..2.f$\n", d);
	put_one("\n08printf: %###-#0000 10+5#3.f$\n", d);
	put_one("\n09printf: %###-#0000 10+5#4f$\n", d);
	put_one("\n10printf: %###-#0000 33...12..#0+0Lf$\n", d);
	put_one("\n11printf: %###-#0000 33...12..#0+0lf$\n", d);
	put_one("\n12printf: %###-#0000 33...12..5#0+hlh0f$\n", d);
	put_one("\n13printf: %###-#0000 33...12..5.#0llhll+0f$\n", d);
	put_one("\n14printf: %###-#0000 10..33...12..#0+lll0f$\n", d);
	put_one("\n15printf: %###-#0000 33...10  7..#0+0Lf$\n", d);
	put_one("\n16printf: %###-#0000 33...10  7..2#0+0Lf$\n", d);
	put_one("\n17printf: %###-#0000 33...10  7..2#0+0f$\n", d);
	put_one("\n18printf: %Lf$\n", d);
}

int			main(void)
{
	put_set(06016341.620652);
	ft_printf("*****\n******\n******\n******\n******\n");
	put_set(0.0);
	ft_printf("*****\n******\n******\n******\n******\n");
	put_set(-0.0);
	ft_printf("*****\n******\n******\n******\n******\n");
	put_set(0.125);
	ft_printf("*****\n******\n******\n******\n******\n");
	put_set(0.165);
	ft_printf("*****\n******\n******\n******\n******\n");
	put_set(0.185);
	ft_printf("*****\n******\n******\n******\n******\n");
	put_set(-696.798);
	ft_printf("*****\n******\n******\n******\n******\n");
	put_set(-2147483648);
	ft_printf("*****\n******\n******\n******\n******\n");
	put_set(2147483648);
	ft_printf("*****\n******\n******\n******\n******\n");
	put_set(2147483647);
	ft_printf("*****\n******\n******\n******\n******\n");
	put_set(12345678987654322.99002);
	return (0);
}
