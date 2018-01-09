/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countdigit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:08:48 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/09 12:14:23 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	ft_max_countdigit(intmax_t n)
{
	int count;

	count = 0;
	while (n > 9 || n < -9)
	{
		n = n / 10;
		count++;
	}
	return (count + 1);
}
