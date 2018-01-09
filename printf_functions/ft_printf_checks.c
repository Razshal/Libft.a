/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_checks.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:36:04 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/09 17:36:15 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int ft_is_printf_flag(char c)
{
	if (c == '-' || c == '+' || c == ' ' || c == '0' || c == '#' || c == '\'')
		return (1);
	return (0);
}

int ft_is_printf_length(char c)
{
	if (c == 'l' || c == 'h' || c == 'z' || c == 'j')
		return (1);
	return (0);
}

int	ft_is_printf_type(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i'
			|| c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x'
			|| c == 'X' || c == 'c' || c == 'C')
		return (1);
	return (0);
}

int ft_check_lconv (t_plist *list)
{
	if ((list->length[0] == 'l') && !(list->length[1]))
		return (1);
	return (0);
}
