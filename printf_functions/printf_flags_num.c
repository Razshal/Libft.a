/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:30:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/12 17:55:49 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	is_signed(char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (1);
	return (0);
}

static char	*ft_straddchar(char *s1, int totheright, char c, size_t toadd)
{
	char	*newstr;
	size_t	count;

	newstr = NULL;
	count = 0;
	if (s1)
	{
		if (!(newstr = (ft_strnew(ft_strlen(s1) + toadd))))
			return (NULL);
		if (!totheright)
			ft_strcat(newstr, s1);
		count = ft_strlen(newstr);
		while (toadd > (count + ft_strlen(s1) - 1))
			newstr[count++] = c;
		if (totheright)
			ft_strcat(newstr, s1);
		free(s1);
	}
	return (newstr);
}

void		printf_flags_num(t_plist *list)
{
	int rightalign;
	char *str;
	char zeroorspace;

	str = list->arg;
	rightalign = (ft_strchr(list->flag, '-') ? 0 : 1);
	zeroorspace = list->precision == -1 && list->width ? '0' : ' ';
	if (list->precision > -1 && (ft_strlen(str) < (size_t)list->precision))
		str = ft_straddchar(str, 1, '0', (size_t)list->precision);
	if (list->width != 0 && (size_t)list->width > ft_strlen(str))
		str = ft_straddchar(str, rightalign, zeroorspace, (size_t)list->width);
	if ((ft_strchr(list->flag, ' ') || ft_strchr(list->flag, '+'))
				&& is_signed(list->type))
		str = ft_straddchar(str, 1,
				(ft_strchr(list->flag, '+') ? '+' : ' '), 1);
	list->arg = str;
	printf_flag_hash(list);
}
