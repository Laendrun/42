/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_flags.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 21:54:53 by saeby             #+#    #+#             */
/*   Updated: 2022/10/26 21:55:01 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list	*ft_get_flags(const char *s)
{
	t_list	*flags_list;
	t_flag	*flag;
	char	*tmp;
	size_t	i;
	int		f_index;

	i = 0;
	f_index = 0;
	flags_list = NULL;
	while (s[i])
	{
		tmp = ft_strstr(s + i, "%");
		if (tmp != 0 && s[i] == '%')
		{
			if (ft_isflag(s[i + 1]))
			{
				flag = malloc(sizeof(t_flag)); 
				flag->s_index = i;
				flag->f_index = f_index++;
				flag->f_type = s[i + 1];
				if (!flags_list)
					flags_list = ft_lstnew(flag);
				else
					ft_lstadd_back(&flags_list, ft_lstnew(flag));
			}
		}
		i++;
	}
	return (flags_list);
}