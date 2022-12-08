/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:26:32 by saeby             #+#    #+#             */
/*   Updated: 2022/12/05 18:37:31 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# define WIN_W 501
# define WIN_H 501
# define WIN_NAME "so_long"
# define SIZE 50
# include "MLX42/MLX42.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_point {
	size_t	x;
	size_t	y;
}				t_point;

typedef struct s_texture {
	int				width;
	int				height;
	char			*path;
	xpm_t			*xpm_texture;
	mlx_image_t		*mlx_img;
}				t_texture;

typedef struct	s_player {
	t_point		position;
	int			color;
	t_texture	*texture;
}				t_player;

typedef struct	s_map {
	char		*path;
	size_t		height;
	size_t		width;
}				t_map;

typedef struct	s_vars {
	mlx_image_t		*img;
	char			*addr;
	mlx_t			*mlx;
	void			*win;
	t_player		player;
	t_map			map;
	int				bg_color;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_vars;

// draw.c
void	draw_background(t_vars *vars, t_point start, t_point end);

// render.c
void	render(void *param);

// input.c
void	key_hook(mlx_key_data_t keydata, void *param);
void	close_prog(t_vars *vars);

#endif // SO_LONG_H