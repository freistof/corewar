/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   precision_padding.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: lvan-vlo <lvan-vlo@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/31 12:40:53 by fblom          #+#    #+#                */
/*   Updated: 2019/04/07 15:35:04 by lvan-vlo      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_pad_exc(t_printf *conv)
{
	if (!conv->zero || (conv->zero && conv->minus) || \
		(conv->precision < conv->fieldwidth && conv->precision >= 0 && \
		!ft_strchr("fFcCsS", conv->letter)))
		return (1);
	return (0);
}

void		ft_fix_padding(char *new, t_printf *conv)
{
	int		i;
	char	c;

	i = 0;
	if ((ft_strchr(new, 'x') || ft_strchr(new, 'X')) && (conv->zero || \
		(ft_strchr("XxPp", conv->letter) && conv->precision != -1 && \
		conv->fieldwidth < conv->precision)))
	{
		while (new[i] != 'x' && new[i] != 'X')
			i++;
		new[i] = '0';
		if (conv->letter != 'p')
			new[1] = conv->letter;
		else
			new[1] = 'x';
	}
	else if (conv->letter == 'd' && conv->zero && (ft_strchr(new, '+') \
		|| ft_strchr(new, '-') || conv->space == 1))
	{
		while (new[i] != '-' && new[i] != '+' && new[i] != ' ')
			i++;
		c = new[i];
		new[i] = '0';
		new[0] = c;
	}
}

char		*make_padding(char *str, t_printf *conv)
{
	char		*padding;
	char		*new;
	int			width;

	if (conv->fieldwidth < conv->retnew)
		return (str);
	width = conv->fieldwidth - conv->retnew;
	padding = ft_strnew(width);
	if (ft_pad_exc(conv))
		padding = ft_memset(padding, ' ', width);
	else
		padding = ft_memset(padding, '0', width);
	if (!conv->minus)
		new = ft_strnjoin(padding, str, width, conv->retnew);
	else
		new = ft_strnjoin(str, padding, conv->retnew, width);
	conv->retnew += ft_strlen(padding);
	free(str);
	free(padding);
	ft_fix_padding(new, conv);
	return (new);
}

void		ft_fix_precision(char *new, t_printf *conv)
{
	int		i;
	char	c;

	if (ft_strchr(new, '+') || ft_strchr(new, '-') || \
		ft_strchr(new, ' ') || ft_strchr("pPxX", conv->letter))
	{
		if (ft_strchr("pPxX", conv->letter))
		{
			ft_fix_padding(new, conv);
			return ;
		}
		i = 0;
		while (new[i] != '+' && new[i] != ' ' && new[i] != '-')
			i++;
		c = new[i];
		new[i] = '0';
		new[0] = c;
	}
}

char		*make_precision(char *str, t_printf *conv)
{
	int		prec;
	int		len;
	char	*zeroes;
	char	*new;

	if (conv->precision == 0)
		conv->retnew = 0;
	if (conv->alternate && conv->precision == 0 && \
		ft_strchr("oO", conv->letter))
		conv->retnew++;
	if (prec_exception(conv))
		return (str);
	len = conv->retnew;
	if (ft_strchr(str, '+') || ft_strchr(str, '-') || ft_strchr(str, ' '))
		len -= 1;
	prec = conv->precision - len;
	zeroes = ft_strnew(prec + 1);
	zeroes = ft_memset(zeroes, '0', prec);
	new = ft_strnjoin(zeroes, str, prec, conv->retnew);
	ft_fix_precision(new, conv);
	ft_del_two(zeroes, str);
	conv->retnew = ft_strlen(new);
	return (new);
}
