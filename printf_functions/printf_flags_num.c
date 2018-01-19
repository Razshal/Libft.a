/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:30:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/19 17:33:54 by mfonteni         ###   ########.fr       */
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

static void		ft_straddchar(t_plist *list, int align, char c, size_t toadd)
{
	char	*newstr;
	size_t	count;
	int		checkneg;

	newstr = NULL;
	count = 0;
	checkneg = 0;
	if (list->arg && ((char*)list->arg)[0] == '-' && c == '0' && (checkneg = 1))
		list->arg = ft_noleaks_strndup(list->arg, 1);
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
	if (checkneg)
		ft_straddchar(list, 1, '-', 1);
}

void		printf_flags_num(t_plist *list)
{
	int		rightalign;
	char	zeroorspace;

	if (list->type == '%')
	{
		list->arg = ft_strnew(1);
		((char*)list->arg)[0] = '%';
	}
	rightalign = (ft_strchr(list->flag, '-') ? 0 : 1);
	zeroorspace = (list->precision == -1 && list->width != 0 &&
			!ft_strchr(list->flag, '0') ? ' ' : '0');
	if (list->precision > -1 &&
			(ft_strlen(list->arg) < (size_t)list->precision))
		ft_straddchar(list, 1, '0',
				(size_t)list->precision - ft_strlen(list->arg));
	if (is_octal_or_hex(list->type) && zeroorspace == ' ')
		printf_flag_hash(list);
	if (list->width != 0 && (size_t)list->width > ft_strlen(list->arg))
		ft_straddchar(list, rightalign, (ft_strchr(list->flag, '0') ? '0' : ' ')		,(size_t)list->width - ft_strlen(list->arg));
	if (is_octal_or_hex(list->type) && zeroorspace == '0')
		printf_flag_hash(list);
	if ((ft_strchr(list->flag, ' ') || ft_strchr(list->flag, '+'))
			&& is_signed(list->type) && !(((char*)list->arg)[0] == '-'))
		ft_straddchar(list, 1,
				(ft_strchr(list->flag, '+') ? '+' : ' '), 1);
}
