/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:34:59 by saeby             #+#    #+#             */
/*   Updated: 2022/12/11 21:51:24 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 15
# endif
# define WIN_W 1280
# define WIN_H 720
# define WIN_NAME "Fil de Fer"
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include "mlx.h"
# include "structures.h"

// GNL
char	*get_next_line(int fd);
char	*ft_strdup(char *s);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strjoin(char *s1, char *s2);
void	fill_str(char *res, char *s1, char *s2);

// FT_PRINTF
int		ft_printf(const char *input_str, ...);
int		ft_print_c(char c);
int		ft_print_s(char *s);
int		ft_print_d(int nbr);
int		ft_print_u(unsigned int nbr);
int		ft_print_p(unsigned int adr);
int		ft_print_x(unsigned int nbr, int format);

// LIBFT
void	*ft_calloc(size_t count, size_t size);
char	**ft_split(char *s, char c);
size_t	ft_strlen(char *s);
int		ft_atoi(const char *str);

// keyboard.c
int		key_handler(int keycode, t_vars *vars);

// utils.c
int		close_window(t_vars *vars);

// map_parser.c
void	map_error(char *s);
void	parse_map(t_vars *vars);

// main.c

#endif