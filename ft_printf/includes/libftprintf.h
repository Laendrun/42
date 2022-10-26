/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 19:07:53 by saeby             #+#    #+#             */
/*   Updated: 2022/10/26 21:56:29 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TEST

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# ifdef TEST
#  include <stdio.h>
# endif

typedef struct s_flag
{
	int		s_index;
	int		f_index;
	int		f_type;
}	t_flag;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

// main.c
int	ft_printf(const char *, ...);

void	ft_putstr_fd(const char *s, int fd);
char	*ft_strstr(const char *haystack, const char *needle);
size_t	ft_strlen(const char *s);
t_list	*ft_lstnew(void *content);
int	ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **alst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_get_flags(const char *s);
int	ft_isflag(char c);

#endif