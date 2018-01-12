/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:30:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/12 12:38:38 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	is_signed(char c)
{
	if (c == 'd' || c == 'i' || c == 'D')
		return (1);
	return (0);
}

static char	*ft_straddchar(char *s1, int totheright, char c)
{
	char	*newstr;
	char	filler[2];

	newstr = NULL;
	filler[0] = c;
	filler[1] = '\0';
	if (s1)
	{
		newstr = (ft_strnew(ft_strlen(s1) + 2));
		if (newstr == NULL)
			return (NULL);
		if (!totheright)
		{
			ft_strcat(newstr, s1);
			ft_strcat(newstr, filler);
		}
		else
		{
			ft_strcat(newstr, filler);
			ft_strcat(newstr, s1);
		}
		free(s1);
	}
	return (newstr);
}

static void replace_space_by_zeroes(char *str)
{
	int count;

	count = -1;
	while (ft_ispace(str[++count]))
		str[count] = '0';
	count = ft_strlen(str);
	while (ft_ispace(str[--count]))
		str[count] = '0';
}

void		printf_flags_num(t_plist *list)
{
	int rightalign;
	char *str;

	str = list->arg;
	rightalign = (ft_strchr(list->flag, '-') ? 1 : 0);
	while (list->precision != -1 && ft_strlen(str) < (size_t)list->precision)
		str = ft_straddchar(str, 1, '0');
	while (list->width != 0 && (size_t)list->width > ft_strlen(str))
		str = ft_straddchar(str, rightalign, ' ');
	if (list->precision == -1 && list->width)
		replace_space_by_zeroes(str);
	if ((ft_strchr(list->flag, ' ') || ft_strchr(list->flag, '+')) &&
			is_signed(list->type))
		str = ft_straddchar(str, 1, (ft_strchr(list->flag, '+') ? '+' : ' '));
	printf_flag_hash(list);
}
