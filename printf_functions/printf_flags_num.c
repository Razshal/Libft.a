/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:30:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/20 12:27:58 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static void	percent_exception(t_plist *list)
{
	if (list->type == '%')
	{
		list->arg = ft_strnew(1);
		((char*)list->arg)[0] = '%';
	}
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

static int	futurespaces(t_plist *list, char zeroorspace)
{
	int future_spaces;

	future_spaces = 0;
	if (ft_strchr(list->flag, '#') &&
			!(is_octal_or_hex(list->type) && zeroorspace == ' '))
	{
		if (list->type == 'o')
			future_spaces++;
		else if (list->type == 'x' || list->type == 'X')
			future_spaces += 2;
	}
	if ((ft_strchr(list->flag, ' ') || ft_strchr(list->flag, '+'))
			&& is_signed(list->type) && !(((char*)list->arg)[0] == '-'))
		future_spaces++;
	return (future_spaces);
}

static void	exceptions(t_plist *list, char zeroorspace, int rightalign)
{
	if (is_octal_or_hex(list->type) && zeroorspace == ' ')
		printf_flag_hash(list);
	if (list->width != 0 && (size_t)list->width > ft_strlen(list->arg))
		ft_straddchar(list, rightalign,
				(ft_strchr(list->flag, '0') ? '0' : ' '), (size_t)list->width
				- ft_strlen(list->arg) - futurespaces(list, zeroorspace));
	if (is_octal_or_hex(list->type) && zeroorspace == '0')
		printf_flag_hash(list);
}

void		printf_flags_num(t_plist *list)
{
	int		rightalign;
	char	zeroorspace;

	percent_exception(list);
	rightalign = (ft_strchr(list->flag, '-') ? 0 : 1);
	zeroorspace = (list->precision == -1 && list->width != 0 &&
			!ft_strchr(list->flag, '0') ? ' ' : '0');

	if (list->precision > -1 &&
			(ft_strlen(list->arg) < (size_t)list->precision))
		ft_straddchar(list, 1, '0',
				(size_t)list->precision - ft_strlen(list->arg));
	exceptions(list, zeroorspace, rightalign);
	if ((ft_strchr(list->flag, ' ') || ft_strchr(list->flag, '+'))
			&& is_signed(list->type) && !(ft_strchr(list->arg, '-')))
		ft_straddchar(list, 1, (ft_strchr(list->flag, '+') ? '+' : ' '), 1);
}
