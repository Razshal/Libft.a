/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:26:34 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/02 18:34:50 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"
#include <stdarg.h>

static int		assign_digit(const char *format, int count, int assign)
{
	assign = ft_atoi(&format[count]);
	while (format[count] && ft_isdigit(format[count]))
		count++;
	return (count);
}

static int		assign_length(const char *format, int count, char *str)
{
	char c;
	str[0] = format[count];
	if (format[count + 1] && ft_is_printf_length(format[count + 1])
			&& (c = format[count + 1]) && (c == 'l' || c == 'h'))
		{
			str[1] = c;
			count++;
		}
	else
		str[1] = '\0';
	return (count);
}

static int		parse_flags(const char *format, int count, t_plist *list)
{
	while (ft_is_printf_flag(format[count]))
	{
		if (!ft_strchr(list->flag, format[count]))
		{
			list->flag[0] = format[count];
			list->flag++;
		}
		count++;
	}
	return (count);
}

static int		parse_one (t_plist *list, const char *format)
{
	int count;
	t_plist *current;

	count = 0;
	current = ft_printflistnew(NULL);
	if (ft_is_printf_flag(format[count]))
		count = parse_flags(format, count, current);
	if (ft_isdigit(format[count]))
		count = assign_digit(format, count, current->width);
	while (format[count] && format[count] == '.' && format[count + 1]
			&& ft_isdigit(format[++count]))
		count = assign_digit(format, count, current->precision);
	while (ft_is_printf_length(format[count]))
		count = assign_length(format, count, current->length);
	return (count);
}

static t_plist	*parse_input(t_plist *list, const char *format, ...)
{
	int		count;

	count = -1;
	while (format[++count])
	{
		if (format[count] == '%')
			parse_one(list, &format[++count]);
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
