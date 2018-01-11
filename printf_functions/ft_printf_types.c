/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_type_d.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:26:42 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/11 12:32:20 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

//TODO : do the %p

char *ft_printf_type_d(t_plist *list)
{
	if ((intmax_t)list->arg == 0 && list->precision == 0)
		return (NULL);
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
	int uppercase;
	
	uppercase = (list->type == 'X' ? 1 : 0);
	base = (list->type == 'o' ? 8 : 10);
	base = (list->type == 'x' || list->type == 'X' ? 16 : 10);
	if ((intmax_t)list->arg == 0 && list->precision == 0)
		return (NULL);
	if (!(list->length[0]))
		return (ft_umax_itoabase(base, (unsigned int)list->arg, uppercase));
	if (ft_check_hconv(list))
		return (ft_umax_itoabase(base, (unsigned short)list->arg, uppercase));
	else if (list->length[0] == 'h' && list->length[1] == 'h')
		return (ft_umax_itoabase(base, (unsigned char)list->arg, uppercase));
	else if (ft_check_lconv(list) || list->type == 'D')
		return (ft_umax_itoabase(base, (unsigned long)list->arg, uppercase));
	else if (list->length[0] == 'l' && list->length[1] == 'l')
		return (ft_umax_itoabase(base,
					(unsigned long long)list->arg, uppercase));
	else if (list->length[0] == 'j')
		return (ft_umax_itoabase(base, (uintmax_t)list->arg, uppercase));
	else if (list->length[0] == 'z')
		return (ft_umax_itoabase(base, (size_t)list->arg, uppercase));
	return (NULL);
}
