/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:15:40 by saeby             #+#    #+#             */
/*   Updated: 2022/12/10 22:02:49 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIN_W 501
# define WIN_H 501
# define WIN_NAME "so_long"
# define WALL '1'
# define FLOOR '0'
# define START 'P'
# define EXIT 'E'
# define COLLECTIBLE 'C'
# ifndef SIZE
# 	define SIZE 50
# endif
# include "mlx.h"
# include "gnl.h"
# include "ft_printf.h"
# include "structures.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

// main.c
int		render(t_vars *vars);

// utils.c
int		keyHandler(int keycode, t_vars *vars);
int		close_window(t_vars *vars);
void	switch_color(t_vars *vars);
void	update_player_position(t_vars *vars, t_point new_pos);
size_t	ft_strlen(char *s);
char	*ft_itoa(int n);

// draw.c
void	put_mlx_pixel(t_vars *vars, int x, int y, int color);
void	draw_rect(t_vars *vars, t_point start, t_point end, int color);
void	draw_map(t_vars *vars);
void	draw_moves(t_vars *vars);

//void	draw_background(t_vars *vars, t_point start, t_point end);
void	draw_background(t_vars *vars);
void	draw_player(t_vars *vars);

// map_parser.c
int		parse_map(t_map *map);
int		fill_grid(t_vars *vars);
void	map_error(char *s);
int		walls_error(t_vars *vars);
int		unknown_character(int c);

// path_checker.c
void	check_path(t_point p, t_vars *vars);

#endif