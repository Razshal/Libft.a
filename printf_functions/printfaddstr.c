/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfaddstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 18:05:45 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/13 18:06:07 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_plist *printfaddstr(const char *str, int start, int end)
{
	t_plist *current;
	char *cutted;

	cutted = ft_strsub(str, start, end - start);
	if (!ft_strlen(cutted))
	{
		ft_memdel((void*)&cutted);
		return (NULL);
	}
	current = printflstnew((void*)cutted);
	current->type = 's';
	return (current);
}
