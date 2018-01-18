/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:40:51 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/18 15:17:04 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*printf_flags_chars(t_plist *list)
{
	char temp;

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
