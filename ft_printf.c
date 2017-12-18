/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:26:34 by mfonteni          #+#    #+#             */
/*   Updated: 2017/12/18 17:53:40 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdarg.h>



t_printflist	parse_input(t_printflist list, const char *format, ...)
{
	int count;

	count = -1;
	while (format[++count])
	{
		if (format[count] == "%" && !format[count] == "%")
		{
			if (format[0] != "%")

		}

	}
}

int ft_printf(const char *format, ...)
{
	int written;
	t_printflist instructions_list;

	written = 0;
	parse_input(instructions_list, format, args[...]);

}
