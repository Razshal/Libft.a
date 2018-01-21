/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 18:27:18 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/21 16:56:01 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <string.h>

size_t	ft_strlen(const char *s)
{
	unsigned int count;

	count = 0;
	while (s && s[count] != '\0')
		count++;
	return (count);
}

size_t	ft_wstrlen(const wchar_t *s)
{
	unsigned int count;

	count = 0;
	while (s && s[count] != '\0')
		count++;
	return (count);
}
