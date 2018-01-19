/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:40:51 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/19 16:40:18 by mfonteni         ###   ########.fr       */
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
	if (list->arg == NULL)
	{
		list->arg = ft_strnew(6);
		ft_strcat(list->arg, "(null)");
	}
}

char	*printf_flags_chars(t_plist *list)
{
	char temp;

	nullexception(list);
	if (list->type == 'C' || list->type == 'c')
	{
		if (list->arg == 0)
			list->ischarexception = 1;
		temp = (char)list->arg;
		list->arg = ft_strnew(1);
		((char*)list->arg)[0] = temp;
		list->type += 16;
	}
	if (list->precision > -1 && (size_t)list->precision < ft_strlen(list->arg))
		((char*)list->arg)[list->precision] = '\0';
	if (ft_strlen(list->arg) < (size_t)list->width)
		ft_straddchar(list, (ft_strchr(list->flag, '-') ? 0 : 1), ' '
				, (size_t)list->width);
	return (list->arg);
}
