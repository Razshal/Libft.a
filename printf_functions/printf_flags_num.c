/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:30:25 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/11 15:50:14 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_straddspace(char *s1, int totheright, int spacesorzeroes)
{
	char	*newstr;
	size_t	alloc_length;
	char	filler[2];

	newstr = NULL;
	filler[0] = (spacesorzeroes ? ' ' : '0');
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

void	printf_flags_num(t_plist *list)
{
	int spaces;
	int zeroes;
	char *str;

	str = list->arg;
//	spaces = (list->precision != 1 ? list->precision : list->width);
	
	if (ft_strchr(list->flag, '0') && list->width != 1 && )
	ft_printf_hash_flag(list);

	if (str[ft_strlen(str) - 1] == '0')
		return;

}
