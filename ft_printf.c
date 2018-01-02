/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:26:34 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/02 16:23:21 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdarg.h>

static int	parse_one (t_plist *list, const char *format)
{
	int count;
	t_plist *current;

	count = 0;
	current = ft_printflistnew(NULL);
	if (format[++count] && ft_isdigit(format[count]))
	{
		current->parameter = ft_atoi(&format[count]);
		while (format[count] && ft_isdigit(format[count]))
			count++;
	}
	if (ft_is_printf_flag(format[count]))
		current->flag = format[count++];
	if (ft_isdigit(format[count]))
	{
		current->width = ft_atoi(&format[count]);
		while (format[count] && ft_isdigit(format[count]))
			count++;
	}
	if (format[count] == '.')


	return (count);
}

t_plist	*parse_input(t_plist *list, const char *format, ...)
{
	int		count;

	count = -1;
	while (format[++count])
	{
		if (format[count] == '%')
			parse_one(list, &format[count]);
	}
	return (list);
}

int		ft_printf(const char *format, ...)
{
	int written;
	t_plist *instructions_list;

	written = 0;
	parse_input(instructions_list, format, args[...]);

}
