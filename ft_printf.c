/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 16:04:32 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/08 17:38:13 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include <stdarg.h>

static void	fillarglist(t_plist *list, va_list ap)
{
	t_plist *current;

	current = list;
	while (current)
	{
		if (current->isrealarg)
			current->arg = va_arg(ap, void*);
		current = current->next;
	}
}

static void	chars_controller(t_plist *list)
{
	if (list->type == 'c' && (!(list->length[0] == 'l') || (list->length[1])))
		ft_putchar((char)(list->arg));
	if ((list->type == 'C') || (list->type == 'c'
				&& list->length[0] == 'l' && !(list->length[1])))
		ft_putwchar((unsigned char)(list->arg));
	if (list->type == 's' && (!(list->length[0] == 'l') || (list->length[1])))
		ft_putstr((char*)(list->arg));
	if ((list->type == 'S') || (list->type == 's'
				&& list->length[0] == 'l' && !(list->length[1])))
		ft_putwstr((unsigned char*)(list->arg));



}

static void	print_controller(t_plist *list)
{
	char type;

	type = list->type;
	if (list)
	{
		if (type == 'c' || type == 'C' || type == 's' || type == 'S')
			chars_controller(list);
	}
}

int			ft_printf(const char *format, ...)
{
	int written;
	t_plist *instructions_list;
	va_list ap;

	written = 0;
	instructions_list = parse_input(format);
	va_start(ap, format);
	fillarglist(instructions_list, ap);
	print_controller(instructions_list);
	va_end(ap);
	return (written);
}
