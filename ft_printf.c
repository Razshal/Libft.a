/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:04:32 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/11 17:31:29 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <unistd.h>

static int	chars_printer(t_plist *list)
{
	if (list->type == 'c' && !check_lconv(list))
		return (write(1, &(list->arg), 1));
	else if ((list->type == 'C') || (list->type == 'c' && check_lconv(list)))
		return (ft_putwchar((wchar_t)(list->arg)));
	else if (list->type == 's' && !check_lconv(list))
	{
		ft_putstr((char*)(list->arg));
		return (ft_strlen(list->arg));
	}
	else if ((list->type == 'S') ||
			(list->type == 's' && check_lconv(list)))
	{
		ft_putwstr((wchar_t*)(list->arg));
		return (ft_strlen(list->arg));
	}
	return (-1);
}

static t_plist	*number_controller(t_plist *list)
{
	if (ft_isupper(list->type) && list->type != 'X')
	{
		list->type = ft_tolower(list->type);
		list->length[0] = 'l';
		list->length[1] = '\0';
	}
	if (list->type == 'i' || list->type == 'd' || list->type == 'D')
		list->arg = (void*)printf_type_d(list);
	if (list->type == 'o' || list->type == 'u' || list->type == 'x')
		list->arg = (void*)printf_type_unsigned(list);
	list->type = 's';
	return (list);
}

static int	flags_precision(t_plist *list)
{
	if (!ischartype(list->type))
	{
		printf_flags_num(list);
		list->type = 's';
	}
	else
		printf_flags_chars(list);
	return (chars_printer(list));
}

static int	print_controller(t_plist *list)
{
	char type;
	int written;

	type = list->type;
	written = 0;
	while (list)
	{
		if (type == 'd' || type == 'D' || type == 'i' || type == 'o' ||
				 type == 'O' || type == 'u' || type == 'U' || type == 'x' ||
				 type == 'X' || type == 'p')
			number_controller(list);
		written += flags_precision(list);
		list = list->next;
	}
	return (written);
}

int			ft_printf(const char *format, ...)
{
	int written;
	t_plist *instructions_list;
	va_list ap;

	written = 0;
	va_start(ap, format);
	instructions_list = parse_input(format, ap);
	written = print_controller(instructions_list);
	va_end(ap);
	return (written);
}
