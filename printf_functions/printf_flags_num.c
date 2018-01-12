/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:30:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/12 18:24:13 by mfonteni         ###   ########.fr       */
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
		while (toadd > (count + ft_strlen(s1)))
			newstr[count++] = c;
		if (totheright)
			ft_strcat(newstr, s1);
		ft_memdel((void*)&s1);
	}
	return (newstr);
}

void		printf_flags_num(t_plist *list)
{
	int rightalign;
	char zeroorspace;

	rightalign = (ft_strchr(list->flag, '-') ? 0 : 1);
	zeroorspace = list->precision == -1 && list->width ? '0' : ' ';
	if (list->precision > -1 &&
			(ft_strlen(list->arg) < (size_t)list->precision))
		list->arg = ft_straddchar(list->arg, 1, '0', (size_t)list->precision);
	if (zeroorspace == ' ')
		printf_flag_hash(list);
	if (list->width != 0 && (size_t)list->width > ft_strlen(list->arg))
		list->arg = ft_straddchar(list->arg, rightalign, zeroorspace, 
				(size_t)list->width);
	if (zeroorspace == '0')
		printf_flag_hash(list);
	if ((ft_strchr(list->flag, ' ') || ft_strchr(list->flag, '+'))
				&& is_signed(list->type))
		list->arg = ft_straddchar(list->arg, 1,
				(ft_strchr(list->flag, '+') ? '+' : ' '), 1);
}
