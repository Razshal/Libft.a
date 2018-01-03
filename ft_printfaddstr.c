/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfaddstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:18:42 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/03 17:25:14 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void ft_printfaddstr(t_plist *list, const char *str, int start, int end)
{
	t_plist *current;
	char	*text_part;

	text_part = ft_strnew(end - start);
	text_part = ft_strncpy(text_part, &str[start], end - start);
	current = ft_printflistnew((void*)text_part);
	current->type = 's';
	if (list)
	{
		list->next = current;
		list = list->next;
	}
	else
		list = current;
}
