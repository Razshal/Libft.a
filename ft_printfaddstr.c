/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfaddstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:18:42 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/04 13:36:46 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void ft_printfaddstr(t_plist *list, const char *str, int start, int end)
{
	t_plist *current;
	char	*text_part;

	text_part = ft_strsub(str, start, end - start);
	printf("text_part:%s\n", text_part);
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
