/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflstadd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:13:53 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/11 17:20:20 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	printflstadd(t_plist **alst, t_plist *new)
{
	t_plist *current;

	current = *alst;
	if (!new)
		return;
	if (!*alst)
		*alst = new;
	else
	{
		while (current->next)
			current = current->next;
		current->next = new;
	}
}
