/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:15:40 by saeby             #+#    #+#             */
/*   Updated: 2022/12/09 15:24:41 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIN_W 501
# define WIN_H 501
# define WIN_NAME "so_long"
# ifndef SIZE
# 	define SIZE 50
# endif
# include "mlx.h"
# include "gnl.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

// structures declaration
typedef struct	s_wall {
	size_t	g_x;
	size_t	g_y;
}				t_wall;

/* Types
 * c : collectible
 * w : wall
 * s : start
 * e : exit
 */

typedef struct	s_g_list {
	t_wall		*elem;
	char		type;
	void		*next;
}				t_g_list;

typedef struct	s_point {
	size_t	px_x;
	size_t	px_y;
}				t_point;

typedef struct s_sprite {
	int	px_w;
	int	px_h;
	void *img;
}				t_sprite;

typedef struct	s_player {
	t_point		pos;
	t_sprite	sprite;
}				t_player;

typedef struct	s_map {
	char		*path;
	size_t		g_h;
	size_t		g_w;
	char		**grid;
}				t_map;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	t_player	player;
	t_map		map;
	t_sprite	w_sp;
	t_sprite	c_sp;
	t_sprite	s_sp;
	t_sprite	e_sp;
	t_sprite	f_sp;
	int			bg_color;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_vars;

// main.c
int		render(t_vars *vars);

// utils.c
int		keyHandler(int keycode, t_vars *vars);
int		close_window(t_vars *vars);
void	switch_color(t_vars *vars);
void	update_player_position(t_vars *vars, t_point new_pos);
size_t	ft_strlen(char *s);

// draw.c
void	put_mlx_pixel(t_vars *vars, int x, int y, int color);
void	draw_rect(t_vars *vars, t_point start, t_point end, int color);
//void	draw_background(t_vars *vars, t_point start, t_point end);
void	draw_background(t_vars *vars);
void	draw_player(t_vars *vars);

// map_parser.c
int		parse_map(t_map *map);
int		fill_grid(t_map *map);

#endif