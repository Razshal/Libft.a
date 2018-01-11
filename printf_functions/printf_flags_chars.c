/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flags_chars.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 12:40:51 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/11 13:18:49 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_straddspace(char *s1, int totheright)
{
	char	*newstr;
	size_t	alloc_length;

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

	precision = (list->precision != 1 && list->type != 'c'
			&& list->type != 'C' ? list->precision : -1);
	spaces = (precision > -1 ? list->width - precision : list->width);
	str = list->arg;
	if (precision > -1 && precision < ft_strlen(str))
		str[precision] = '\0';
	while (ft_strlen(str) < list->width)
		str = ft_straddspace(str, (ft_strchr(list->flag, '-') ? 1 : 0));
	return (str);
}
