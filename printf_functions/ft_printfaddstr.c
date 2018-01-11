/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfaddstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:18:42 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/11 17:20:30 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_plist *ft_printflststr(const char *str, int start, int end)
{
	t_plist *current;
	char *cutted;

	cutted = ft_strsub(str, start, end - start);
	if (!ft_strlen(cutted))
	{
		ft_memdel((void*)&cutted);
		return (NULL);
	}
	current = ft_printflistnew((void*)cutted);
	current->type = 's';
	return (current);
}
