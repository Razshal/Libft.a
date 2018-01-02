/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:26:34 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/02 13:42:26 by mfonteni         ###   ########.fr       */
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
		if (format[count] == "%")
		{
			if (format[count + 1] == "%" && ++count)
				ft_putchar('%');
			else if (ft_isdigit(format[count + 1]))

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
