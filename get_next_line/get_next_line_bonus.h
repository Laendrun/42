/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 08:37:40 by saeby             #+#    #+#             */
/*   Updated: 2022/11/22 21:09:48 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*
 * The MAX_FD macro is defined based on the max number of file descriptors
 * based on my current OS (MacOS Ventura 13.0)
 * On the most recent MacOS versions, the default maximum file descriptors 
 * is 10240
 * this value can be different on the school computers so I'll check this
 * when I'll be back there
*/
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif
# define MAX_FD 10240
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

char	*get_next_line(int fd);

char	*ft_strdup(char *s);
size_t	ft_strlen(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	fill_str(char *res, char *s1, char *s2);

#endif