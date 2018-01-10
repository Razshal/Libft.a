/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:30:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/10 18:07:57 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	printf_flag_zero(t_plist *link, int leftalign)
{
	int toprint;

	toprint = 0;
	if (link->width && (link->width - ft_strlen(link->arg) > 0))
		toprint = link->width - ft_strlen((char*)(link->arg));
	if (!link->width && (link->precision - ft_strlen(link->arg) > 0))
		toprint = link->precision - ft_strlen(link->arg);
	if (
}
