/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printflstcount.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 13:50:33 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/06 15:09:30 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_argcount(const char *format)
{
	int count;
	int argcount;

	count = 0;
	argcount = 0;
	while (format[count])
	{
//Not finished, useless for now
		while (format[count] && !ft_is_printf_type(format[count]))
			count++;
		if (ft_is_printf_type(format[count]))
			argcount++;
	}
	return (argcount);
}
