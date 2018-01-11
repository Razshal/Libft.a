/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:40:51 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/11 12:56:19 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*printf_flags_chars(t_plist *list)
{
	int precision;
	int spaces;
	char *str;

	precision = (list->precision != 1 ? -1 : list->precision);
	spaces = (precision > -1 ? list->width - precision : list->width);
	str = list->arg;
	if (precision > -1 && precision < ft_strlen(str))
		str[precision] = '\0';
	while (ft_strlen(str) < width)
	{
		str = ft_noleaksstrjoin(str, " ");
	}
}
