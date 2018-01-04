/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfaddstr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:18:42 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/04 15:36:52 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

t_plist *ft_printflststr(const char *str, int start, int end)
{
	t_plist *current;
	char	*text_part;

	text_part = ft_strsub(str, start, end - start);
	current = ft_printflistnew((void*)text_part);
	current->type = 's';
	return (current);
}
