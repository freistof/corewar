/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 07:58:41 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/03/31 15:39:07 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			clean_result(t_printf *conv)
{
	int i;
	int	r;

	i = 0;
	r = conv->ret;
	while (i < r)
	{
		ft_putchar(conv->result[i]);
		i++;
	}
	free(conv->result);
	free(conv);
	return (r);
}

int			ft_add_result(char c, t_printf *conv, int p)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = (char*)ft_memalloc(sizeof(char) * conv->ret + 2);
	while (i < conv->ret)
	{
		tmp[i] = conv->result[i];
		i++;
	}
	tmp[i] = c;
	tmp[i + 1] = '\0';
	free(conv->result);
	conv->result = tmp;
	conv->ret++;
	return (p);
}

t_printf	*init_conv(void)
{
	t_printf	*conv;

	conv = (t_printf*)ft_memalloc(sizeof(t_printf));
	conv->result = ft_strnew(0);
	conv->ret = 0;
	return (conv);
}

int			ft_printf(const char *restrict format, ...)
{
	int			i;
	t_printf	*conv;
	va_list		args;

	i = 0;
	conv = init_conv();
	va_start(args, format);
	while (format[i] != '\0')
	{
		if ((format[i] == '\\' && format[i + 1] == '%') || \
			(format[i] == '%' && format[i + 1] == '%'))
			i += ft_add_result('%', conv, 1);
		else if (format[i] == '%')
			i = conversionist((char*)format, i + 1, conv, args);
		else
			ft_add_result(format[i], conv, 0);
		i++;
	}
	return (clean_result(conv));
}
