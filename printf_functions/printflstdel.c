/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflstdel.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 12:44:04 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/22 14:36:29 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	printflstdel(t_plist *list)
{
	t_plist *current;
	t_plist *next;

	if (!list)
		return ;
	current = list;
	while (current)
	{
		if (current)
			next = current->next;
		if (current->isrealarg == 0 || !ischartype(current->type))
			ft_memdel((void*)&current->arg);
		ft_memdel((void*)&current->flag);
		ft_memdel((void*)&current->length);
		ft_memdel((void*)&current);
		current = next;
	}
}
