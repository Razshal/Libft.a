/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:40:51 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/12 19:47:09 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*printf_flags_chars(t_plist *list)
{
	int precision;
	size_t spaces;
	char temp;

	if (list->type == 'C' || list->type == 'c')
	{
		temp = (char)list->arg;
		list->arg = ft_strnew(1);
		((char*)list->arg)[0] = temp;
		list->type += 16;
	}
	precision = (list->precision != -1 && list->type != 'c'
			&& list->type != 'C' ? list->precision : -1);
	spaces = (precision > -1 ? list->width - precision : list->width);
	if (precision > -1 && (size_t)precision < ft_strlen(list->arg))
		((char*)list->arg)[precision] = '\0';
	if (ft_strlen(list->arg) < spaces)
		ft_straddchar(list, (ft_strchr(list->flag, '-') ? 1 : 0), ' ', spaces);
	return (list->arg);
}
