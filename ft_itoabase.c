/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 11:03:28 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/09 13:06:14 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*base_table(int base, int isupper)
{
	char *tab;

	tab = ft_strnew(base + 1);
	while (base > 10)
	{
		tab[base] = base + (isupper ? 55 : 87);
		base--;
	}
	while (base < 10 && base >= 0)
	{
		tab[base] = base + '0';
		base--;
	}
	printf("itab:%s", tab);
	return (tab);
}

char	*ft_max_itoabase(int base, intmax_t n, int isupper)
{
	char	*str;
	int		size;
	int		checkneg;
	char	*tab;

	size = ft_max_countdigit(n);
	checkneg = 0;
	tab = base_table(base, isupper);
	if (n < 0)
	{
		size++;
		checkneg = 1;
		n = -n;
	}
	str = ft_strnew(size);
	if (str && checkneg)
		str[0] = '-';
	while (str && checkneg ? size > 1 : size >= 0)
	{
		str[--size] = tab[n % base] + '0';
		n = n / base;
	}
	return (str);
}

int main(void)
{
	char *str = base_table(16, 0);
	printf("%s", str);
}
