/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:30:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/13 18:40:38 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	is_signed(char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (1);
	return (0);
}

static int	is_octal_or_hex(char c)
{
	if (c == 'x' || c == 'X' || c == 'o')
		return (1);
	return (0);
}

void	ft_straddchar(t_plist *list, int totheright, char c, size_t toadd)
{
	char	*newstr;
	size_t	count;

	newstr = NULL;
	count = 0;
	if (list->arg)
	{
		if (!(newstr = (ft_strnew(ft_strlen(list->arg) + toadd + 1))))
			return;
		if (!totheright)
			ft_strcat(newstr, list->arg);
		count = ft_strlen(newstr);
		while (toadd > (count + ft_strlen(list->arg)))
			newstr[count++] = c;
		if (totheright)
			ft_strcat(newstr, list->arg);
		ft_memdel((void*)&list->arg);
		list->arg = newstr;
	}
}

void		printf_flags_num(t_plist *list)
{
	int rightalign;
	char zeroorspace;

	rightalign = (ft_strchr(list->flag, '-') ? 0 : 1);
	zeroorspace = (list->precision == -1 && list->width ? '0' : ' ');
	if (list->precision > -1 &&
			(ft_strlen(list->arg) < (size_t)list->precision))
		ft_straddchar(list, 1, '0', (size_t)list->precision);
	if (is_octal_or_hex(list->type) && zeroorspace == ' ')
		printf_flag_hash(list);
	if (list->width != 0 && (size_t)list->width > ft_strlen(list->arg))
		ft_straddchar(list, rightalign, zeroorspace,
				(size_t)list->width);
	if (is_octal_or_hex(list->type) && zeroorspace == '0')
		printf_flag_hash(list);
	if ((ft_strchr(list->flag, ' ') || ft_strchr(list->flag, '+'))
									&& is_signed(list->type))
		ft_straddchar(list, 1,
				(ft_strchr(list->flag, '+') ? '+' : ' '), 1);
}
