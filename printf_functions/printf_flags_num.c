/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:30:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/11 12:27:03 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	printf_flags_num(t_plist *link, int leftalign)
{
	int toprint;
	int zeroes;
	char *str;

	toprint = BIGGER(link->width, link->precision);
	zeroes = (link->precision != 1 ? link->precision : link->width);
	str = link->arg;
	if (str[ft_strlen(str) - 1] == '0')
		return;

}
