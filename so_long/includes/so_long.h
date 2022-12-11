/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:15:40 by saeby             #+#    #+#             */
/*   Updated: 2022/12/11 20:11:57 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIN_W 500
# define WIN_H 500
# define WIN_NAME "so_long"
# define WALL '1'
# define FLOOR '0'
# define START 'P'
# define EXIT 'E'
# define COLLECT 'C'
# ifndef SIZE
#  define SIZE 50
# endif
# define BOOL short int
# define TRUE 1
# define FALSE 0
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
int		key_handler(int keycode, t_vars *vars);
int		close_window(t_vars *vars);
size_t	ft_strlen(char *s);
void	free_tiles(t_vars *vars);
int		check_map_name(char *s);
size_t	ft_linelen(char *s);

// draw.c
void	put_mlx_pixel(t_vars *vars, int x, int y, int color);
void	draw_rect(t_vars *vars, t_point start, t_point end, int color);
void	draw_map(t_vars *vars);
void	draw_moves(t_vars *vars);
void	put_sp(t_vars *vars, t_point p, char t);

//void	draw_background(t_vars *vars, t_point start, t_point end);
void	draw_background(t_vars *vars);
void	draw_player(t_vars *vars);

// map_parser.c
int		parse_map(t_map *map);
int		fill_grid(t_vars *vars);
void	map_error(char *s);
void	fill_tiles(t_vars *vars, char *line, t_point g_pos);
void	allocate_line(t_vars *vars, t_point g_pos);

// map_parser_utils.c
void	count_grid(t_vars *vars, char c, t_point p);
void	check_map(t_vars *vars);
int		unknown_character(int c);
int		walls_error(t_vars *vars);
void	initiate_map_filling(t_vars *vars, t_point *p);

// path_checker.c
void	check_path(t_point p, t_vars *vars);

// game_utils.c
void	init_game(t_vars *vars, char *map_path);
void	load_sprites(t_vars *vars);
void	load_map_sprites(t_vars *vars);
void	load_digits_sprites(t_vars *vars);
void	update_player_position(t_vars *vars, t_point new_pos);

// free.c
void	free_tiles(t_vars *vars);

#endif