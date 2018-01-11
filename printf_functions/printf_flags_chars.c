/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:40:51 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/11 17:36:04 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_straddspace(char *s1, int totheright)
{
	char	*newstr;

	newstr = NULL;
	if (s1)
	{
		newstr = (ft_strnew(ft_strlen(s1) + 2));
		if (newstr == NULL)
			return (NULL);
		if (!totheright)
		{
			ft_strcat(newstr, s1);
			ft_strcat(newstr, " ");
		}
		else
		{
			ft_strcat(newstr, " ");
			ft_strcat(newstr, s1);
		}
		free(s1);
	}
	return (newstr);
}

char	*printf_flags_chars(t_plist *list)
{
	int precision;
	int spaces;
	char *str;
	char temp;

	if (list->type == 'C' || list->type == 'c')
	{
		temp = (char)list->arg;
		list->arg = ft_strnew(1);
		((char*)list->arg)[0] = temp;
		list->type += 16;
	}
	str = list->arg;
	precision = (list->precision != -1 && list->type != 'c'
			&& list->type != 'C' ? list->precision : -1);
	spaces = (precision > -1 ? list->width - precision : list->width);
	if (precision > -1 && precision < (int)ft_strlen(str))
		str[precision] = '\0';
	while ((int)ft_strlen(str) < spaces)
		str = ft_straddspace(str, (ft_strchr(list->flag, '-') ? 1 : 0));
	return (str);
}
