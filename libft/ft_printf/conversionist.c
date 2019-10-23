/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   conversionist.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/29 08:37:12 by lvan-vlo       #+#    #+#                */
/*   Updated: 2019/04/07 14:20:56 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_set_flags2(char *flags, t_printf *conv)
{
	if (ft_isdigit(*flags))
	{
		conv->fieldwidth = ft_atoi(flags);
		return (ft_getdigits(conv->fieldwidth) - 1);
	}
	else
	{
		conv->precision = ft_atoi(flags + 1);
		if (ft_isdigit(flags[1]))
			return (ft_getdigits(conv->precision));
		return (0);
	}
}

int			ft_set_flags(char *flags, t_printf *conv, int i)
{
	if (*flags == 'h' && conv->h < 2)
		conv->h++;
	if (*flags == 'l' && conv->l < 2)
		conv->l++;
	if (*flags == 'L')
		conv->big_l = 1;
	if (*flags == 'j')
		conv->j = 1;
	if (*flags == ' ')
		conv->space = 1;
	if (*flags == '+')
		conv->plus = 1;
	if (*flags == '-')
		conv->minus = 1;
	if (*flags == '#')
		conv->alternate = 1;
	if (*flags == 'z')
		conv->z = 1;
	if (*flags == '0')
		conv->zero = 1;
	else if (ft_isdigit(*flags) || *flags == '.')
		i += ft_set_flags2(flags, conv);
	return (i);
}

t_printf	*set_to_zero(t_printf *conv)
{
	conv->z = 0;
	conv->letter = 0;
	conv->fieldwidth = 0;
	conv->zero = 0;
	conv->plus = 0;
	conv->space = 0;
	conv->minus = 0;
	conv->alternate = 0;
	conv->precision = -1;
	conv->l = 0;
	conv->h = 0;
	conv->big_l = 0;
	conv->j = 0;
	conv->retnew = 0;
	return (conv);
}

void		ft_f_conversionist(t_printf *conv, va_list args)
{
	conv->letter = 'f';
	if (!conv->big_l)
		ft_make_f_conversion(conv, va_arg(args, double));
	else
		ft_make_f_conversion(conv, va_arg(args, long double));
}

int			conversionist(char *format, int i, t_printf *conv, va_list args)
{
	conv = set_to_zero(conv);
	while (ft_strchr(FLAGS, format[i]) && format[i] != '\0')
	{
		i = ft_set_flags(&format[i], conv, i);
		i++;
	}
	if (format[i] == '\0')
		return (i - 1);
	if (format[i] == 'f' || format[i] == 'F')
		ft_f_conversionist(conv, args);
	else if (ft_strchr(CONVERSIONS, format[i]) && format[i] != '\0')
	{
		conv->letter = format[i];
		ft_make_conversion(conv, va_arg(args, void *));
	}
	else
	{
		conv->letter = 'c';
		ft_no_conversion(conv, format[i]);
	}
	return (i);
}
