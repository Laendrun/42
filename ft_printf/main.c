/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 18:58:18 by saeby             #+#    #+#             */
/*   Updated: 2022/10/26 21:56:32 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_isflag(char c);

int	ft_printf(const char *input_str, ...)
{
	int		flag_count;
	char	*tmp;

	tmp = ft_strstr(input_str, "%");
	if (tmp != 0)
	{
		t_list *flags = ft_get_flags(input_str);
		flag_count = ft_lstsize(flags);
		if (flag_count != 0)
		{
			while (flags)
			{
				t_flag *flag = flags->content;
				printf("s_index: %d\n", flag->s_index);
				printf("f_index: %d\n", flag->f_index);
				printf("f_type: %c\n", flag->f_type);
				flags = flags->next;
			}
		}
	}
	else
		ft_putstr_fd(input_str, 1);
	return (0);
}
