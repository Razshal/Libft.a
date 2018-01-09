/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_umax_itoabase.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 18:52:42 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/09 18:58:31 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_umax_itoabase(int base, uintmax_t n, int isupper)
{
	char	*str;
	int		size;
	int		checkneg;
	char	*tab;

	checkneg = 0;
	size = ft_max_countdigit_base(n, base) - 1;
	tab = base_table(base, isupper);
	str = ft_strnew(size);
	while (str && n)
	{
		str[--size] = tab[n % base];
		n = n / base;
	}
	return (str);
}
