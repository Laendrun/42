/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 19:04:12 by saeby             #+#    #+#             */
/*   Updated: 2022/12/11 13:19:16 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

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
	t_point		start_pos;
	t_sprite	sprite;
}				t_player;

typedef struct	s_tile {
	char		t;
	int			v;
}				t_tile;

typedef struct	s_map {
	char		*path;
	size_t		g_h;
	size_t		g_w;
	char		**grid;
	t_tile		**tiles;
	int			exitAccessible;
	int			accessibleCollectibles;
}				t_map;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	t_player	player;
	t_map		map;
	t_sprite	w_sp;
	t_sprite	c_sp;
	t_sprite	s_sp;
	t_sprite	e_sp;
	t_sprite	f_sp;
	t_sprite	p_sp;
	t_sprite	d_sp;
	t_sprite	yw_sp;
	t_sprite	*digits_sp;
	int			won;
	int			moves;
	int			collected;
	int			collectibles;
	int			exitUnlocked;
	int			exitFound;
	int			startFound;
	int			bg_color;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_vars;

#endif