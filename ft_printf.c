/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:04:32 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/13 18:56:23 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <unistd.h>

/*
static void		printf_debug_printlist(t_plist *list)
{
	if (list)
	{
		if (list->type == 's')
			printf("Arg:%s\n", (char*)list->arg);
		else if (list->type == 'c')
			printf("Arg:%c\n", (char)list->arg);
		else
			printf("arg:%d\n", (int)list->arg);
		printf("flags:%s\n", list->flag);
		printf("width:%d\n", list->width);
		printf("precision:%d\n", list->precision);
		printf("length:%s\n", list->length);
		printf("type:%c\n\n", list->type);
	}
	if (list->next)
	{
		list = list->next;
		printf_debug_printlist(list);
	}
}
*/

static int		char_exception(t_plist *list)
{
	char zero;

	zero = 0;
	if (ft_strchr(list->flag, '-'))
		ft_putstr((char*)(list->arg));
	write(1, &zero, 1);
	if (!ft_strchr(list->flag, '-'))
		ft_putstr((char*)(list->arg));
	return (ft_strlen(list->arg) + 1);
}

static int		chars_printer(t_plist *list)
{
	char percent;

	percent = '%';
	if (list->type == '%')
		return (write(1, &percent, 1));
	else if (list->ischarexception)
		return (char_exception(list));
	else if (list->type == 's' && !check_lconv(list))
	{
		ft_putstr(list->arg);
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

static void		number_controller(t_plist *list)
{
	if (ft_isupper(list->type) && list->type != 'X')
	{
		list->type = ft_tolower(list->type);
		list->length[0] = 'l';
		list->length[1] = '\0';
	}
	if (list->type == 'i' || list->type == 'd' || list->type == 'D')
		list->arg = (void*)printf_type_d(list);
	else if (list->type == 'o' || list->type == 'u' || list->type == 'x'
			|| list->type == 'X' || list->type == 'p')
		list->arg = (void*)printf_type_unsigned(list);
}

static int		print_controller(t_plist *list)
{
	int written;

	written = 0;
	while (list)
	{
		if (ischartype(list->type))
		{
			if (list->isrealarg)
			{
				if (list->type == 'S' || list->type == 's')
					list->arg = ft_strdup(list->arg);
				printf_flags_chars(list);
			}
		}
		else if (!(list->type == '%'))
		{
			number_controller(list);
			printf_flags_num(list);
			list->type = 's';
			list->length[0] = '\0';
		}
		written += chars_printer(list);
		list = list->next;
	}
	return (written);
}

int				ft_printf(const char *format, ...)
{
	int		written;
	t_plist	*instructions_list;
	va_list	ap;

	written = 0;
	va_start(ap, format);
	instructions_list = parse_input(format, ap);
//	printf_debug_printlist(instructions_list);
	written = print_controller(instructions_list);
	va_end(ap);
	return (written);
}
