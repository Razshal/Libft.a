/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 12:09:51 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/06 12:10:56 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "includes/libft.h"

void	ft_putwstr(char const *s)
{
	int count;

	count = -1;
	if (s)
	{
		while (s[++count] != '\0')
			ft_putwchar(s[count]);
	}
}