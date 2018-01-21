/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:40:51 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/21 15:16:47 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void		ft_straddchar(t_plist *list, int align, char c, size_t toadd)
{
	char	*newstr;
	size_t	count;

	newstr = NULL;
	count = 0;
	if (list->arg && toadd > 0)
	{
		if (!(newstr = (ft_strnew(ft_strlen(list->arg) + toadd + 1))))
			return ;
		if (!align)
			ft_strcat(newstr, list->arg);
		count = ft_strlen(newstr);
		while (toadd--)
			newstr[count++] = c;
		if (align)
			ft_strcat(newstr, list->arg);
		ft_memdel((void*)&list->arg);
		list->arg = newstr;
	}
}

static void nullexception(t_plist *list)
{
	if (list->arg == NULL && (list->type == 's' || list->type == 'S'))
	{
		list->arg = ft_strnew(6);
		ft_strcat(list->arg, "(null)");
	}
}

char	*printf_flags_chars(t_plist *list)
{
	wchar_t temp;

	nullexception(list);
	if (list->type == 'C' || list->type == 'c')
	{
		if (list->arg == 0 || list->arg == NULL)
			list->ischarexception = 1;
		temp = (wchar_t)list->arg;
		list->arg = ft_strnew(1);
		((wchar_t*)list->arg)[0] = temp;
		list->type += 16;
	}
	if (list->precision > -1 && (size_t)list->precision < ft_strlen(list->arg))
		((wchar_t*)list->arg)[list->precision] = '\0';
	if (ft_strlen(list->arg) < (size_t)list->width)
		ft_straddchar(list, (ft_strchr(list->flag, '-') ? 0 : 1), ' '
				, (size_t)list->width - ft_strlen(list->arg)
				- list->ischarexception);
	return (list->arg);
}
