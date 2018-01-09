/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:03:28 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/09 15:39:10 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*base_table(int base, int isupper)
{
	char *tab;
	int count;

	tab = ft_strnew(base + 1);
	count = 0;
	tab[0] = count++ + '0';
	while (count < 10 && count <= base)
	{
		tab[count] = count + '0';
		count++;
	}
	while (count >= 10 && count < base)
	{
		tab[count] = count - 10 + (isupper ? 'A' : 'a');
		count++;
	}
	return (tab);
}

char	*ft_max_itoabase(int base, intmax_t n, int isupper)
{
	char	*str;
	int		size;
	int		checkneg;
	char	*tab;

	checkneg = 0;
	size = ft_max_countdigit_base(n, base) - 1;
	tab = base_table(base, isupper);
	if (n < 0)
	{
		checkneg = 1;
		n = -n;
		size++;
	}
	str = ft_strnew(size);
	if (str && checkneg)
		str[0] = '-';
	while (str && n)
	{
		str[--size] = tab[n % base];
		n = n / base;
	}
	return (str);
}
