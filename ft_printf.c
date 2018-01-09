/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:04:32 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/09 17:21:06 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdarg.h>

static int	chars_controller(t_plist *list)
{
	if (list->type == 'c' && (!(list->length[0] == 'l') || (list->length[1])))
	{
		ft_putchar((char)(list->arg));
		return (1);
	}
	else if ((list->type == 'C') || (list->type == 'c'
			&& list->length[0] == 'l' && !(list->length[1])))
	{
		ft_putwchar((unsigned char)(list->arg));
		return (1);
	}
	else if (list->type == 's'
			&& (!(list->length[0] == 'l') || (list->length[1])))
	{
		ft_putstr((char*)(list->arg));
		return (ft_strlen(list->arg));
	}
	else if ((list->type == 'S') || (list->type == 's'
			&& list->length[0] == 'l' && !(list->length[1])))
	{
		ft_putwstr((unsigned char*)(list->arg));
		return (ft_strlen(list->arg));
	}
	return (-1);
}

static int	number_controller(t_plist *list)
{
	char *basestr;
	if ((list->type == 'i' && ! || list->type == 'd')
		basestr = ft_max_itoabase(10, (int)(list->arg), 0);
	if (list->type = 'D' || list
	return (chars_controller(list));
}

static int	print_controller(t_plist *list)
{
	char type;
	int written;

	type = list->type;
	written = 0;
	while (list)
	{
		if (type == 'c' || type == 'C' || type == 's' || type == 'S')
		{
			prepare_print(list);
			written += chars_controller(list);
		}
		else if (type == 'd' || type == 'D' || type == 'i' || type == 'o' ||
			type == 'O' || type == 'u' || type == 'U' || type == 'x' ||
			type == 'X')
			written += number_controller(list);
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
