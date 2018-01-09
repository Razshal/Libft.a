/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:26:42 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/09 19:18:18 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char *ft_printf_type_d(t_plist *list)
{
	if (!(list->length[0]) && !(list->type == 'D'))
		return (ft_max_itoabase(10, (int)list->arg, 0));
	else if (ft_check_hconv(list))
		return (ft_max_itoabase(10, (short)list->arg, 0));
	else if (list->length[0] == 'h' && list->length[1] == 'h')
		return (ft_max_itoabase(10, (char)list->arg, 0));
	else if (ft_check_lconv(list) || list->type == 'D')
		return (ft_max_itoabase(10, (long)list->arg, 0));
	else if (list->length[0] == 'l' && list->length[1] == 'l')
		return (ft_max_itoabase(10, (long long)list->arg, 0));
	else if (list->length[0] == 'j')
		return (ft_max_itoabase(10, (intmax_t)list->arg, 0));
	else if (list->length[0] == 'z')
		return (ft_max_itoabase(10, (size_t)list->arg, 0));
	return (NULL);
}

char *ft_printf_type_unsigned(t_plist *list)
{
	int base;

	base = (list->type == 'o' ? 8 : 10);
	base = (list->type == 'x' ? 16 : 10);
	if (!(list->length[0]))
		return (ft_umax_itoabase(base, (unsigned int)list->arg, 0));
	if (ft_check_hconv(list))
		return (ft_umax_itoabase(base, (unsigned short)list->arg, 0));
	else if (list->length[0] == 'h' && list->length[1] == 'h')
		return (ft_umax_itoabase(base, (unsigned char)list->arg, 0));
	else if (ft_check_lconv(list) || list->type == 'D')
		return (ft_umax_itoabase(base, (unsigned long)list->arg, 0));
	else if (list->length[0] == 'l' && list->length[1] == 'l')
		return (ft_umax_itoabase(base, (unsigned long long)list->arg, 0));
	else if (list->length[0] == 'j')
		return (ft_umax_itoabase(base, (uintmax_t)list->arg, 0));
	else if (list->length[0] == 'z')
		return (ft_umax_itoabase(base, (size_t)list->arg, 0));
	return (NULL);
}
