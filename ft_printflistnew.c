/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflistnew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 14:12:13 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/02 17:43:48 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "includes/libft.h"

t_plist	*ft_printflistnew(void	*arg)
{
	t_plist	*newlist;

	newlist = NULL;
	if (!(newlist = (t_plist*)malloc(sizeof(t_plist))))
		return (NULL);
	if (arg)
		newlist->arg = arg;
	else
		newlist->arg = NULL;
	newlist->flag = ft_strnew(4);
	newlist->width = -1;
	newlist->precision = -1;
	newlist->length = ft_strnew(2);
	ft_strclr(newlist->length);
	newlist->type = -1;
	newlist->next = NULL;
	return (newlist);
}
