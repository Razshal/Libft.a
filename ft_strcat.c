/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:38:47 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/21 15:21:07 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int count;
	int count2;

	count = 0;
	count2 = 0;
	if (ft_strlen(s1))
	{
		while (s1[count] != '\0')
			count++;
	}
	while (s2[count2] != '\0')
	{
		s1[count] = s2[count2];
		count++;
		count2++;
	}
	s1[count] = '\0';
	return (s1);
}
