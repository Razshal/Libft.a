/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_flag_hash.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfonteni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 16:29:49 by mfonteni          #+#    #+#             */
/*   Updated: 2018/01/18 16:30:48 by mfonteni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	printf_flag_hash(t_plist *list)
{
	int		leftalign;
	char	*temp;

	temp = NULL;
	leftalign = (ft_strchr(list->flag, '-') ? 1 : 0);
	if (ft_strchr(list->flag, '#'))
	{
		if (ft_strchr(list->flag, '#') && list->type == 'o')
			temp = ft_strjoin("0", list->arg);
		else if (ft_strchr(list->flag, '#') && list->type == 'x')
			temp = ft_strjoin("0x", list->arg);
		else if (ft_strchr(list->flag, '#') && list->type == 'X')
			temp = ft_strjoin("0X", list->arg);
		free(list->arg);
		list->arg = temp;
	}
}
