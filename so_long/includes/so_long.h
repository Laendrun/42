/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:15:40 by saeby             #+#    #+#             */
/*   Updated: 2022/12/04 23:34:39 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIN_W 501
# define WIN_H 501
# define WIN_NAME "so_long"
# include "mlx.h"
# include "gnl.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

// structures declaration
typedef struct	s_point {
	size_t	x;
	size_t	y;
}				t_point;

typedef struct s_sprite {
	int	width;
	int	height;
	void *src;
	void *addr;
	int	bits_per_pixel;
	int	line_length;
	int endian;
}				t_sprite;

typedef struct	s_player {
	t_point		position;
	size_t		size;
	int			color;
}				t_player;

typedef struct	s_vars {
	void		*img;
	char		*addr;
	void		*mlx;
	void		*win;
	t_player	player;
	int			bg_color;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_vars;

typedef struct	s_map {
	int	height;
	int	width;
	t_point	e;
	t_point p;
}				t_map;

// main.c
int		render(t_vars *vars);

// utils.c
int		keyHandler(int keycode, t_vars *vars);
int		close_window(t_vars *vars);
void	switch_color(t_vars *vars);
void	update_player_position(t_vars *vars, t_point new_pos);

// draw.c
void	put_mlx_pixel(t_vars *vars, int x, int y, int color);
void	draw_rect(t_vars *vars, t_point start, t_point end, int color);
void	draw_background(t_vars *vars, t_point start, t_point end);
void	draw_player(t_vars *vars);

#endif