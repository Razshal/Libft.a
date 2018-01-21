/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:40:51 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/21 18:37:13 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	writespaces(int spaces)
{
	int		count;
	char	space;
	
	count = 0;
	space = ' ';
	if (spaces > 0)
	{
		while (count++ < spaces)
			ft_putchar(' ');
	}
	return (spaces);
}

int		printf_flags_chars(t_plist *list)
{
	int written;
	int towritte;

	written = 0;
	towritte = (list->precision != -1 && ft_strlen(list->arg) > (size_t)list->precision
			? ft_strlen(list->arg) - list->precision : ft_strlen(list->arg));
	if (list->arg == NULL && (list->type == 's' || list->type == 'S'))
		return (ft_putstrn("(null)", 6));
	if (!ft_strchr(list->flag, '-') && ft_strlen(list->arg) < (size_t)list->width)
		written += writespaces(list->width - towritte);
	if (list->precision > -1 && (size_t)list->precision < ft_strlen(list->arg))
		written += (list->type == 's' && !check_lconv(list) ?
				ft_putstrn(list->arg, list->precision) :
				ft_putwstrn(list->arg, list->precision));
	else if (list->type == 's')
	{
		ft_putstr(list->arg);
		written += ft_strlen(list->arg);
	}
	else
		written += ft_putwstr(list->arg);
	if (ft_strchr(list->flag, '-') && ft_strlen(list->arg) < (size_t)list->width)
		written += writespaces(list->width - towritte);
	return (written);
}

int		printf_flags_char(t_plist *list)
{
	int written;

	written = 0;
	if (!ft_strchr(list->flag, '-') && 1 < (size_t)list->width)
		written += writespaces((size_t)list->width - 1);
	if (list->precision == -1 || (size_t)list->precision > 1)
	{
		if (list->type == 'c')
		{
			ft_putchar((char)list->arg);
			written += 1;
		}
		else
			written += ft_putwchar((wchar_t)list->arg);
	}
	if (ft_strchr(list->flag, '-') && 1 < (size_t)list->width)
		written += writespaces((size_t)list->width - 1);
	return (written);
}
