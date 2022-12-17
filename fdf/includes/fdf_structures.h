/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:52:47 by saeby             #+#    #+#             */
/*   Updated: 2022/12/17 13:24:59 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTURES_H
# define FDF_STRUCTURES_H

typedef struct s_vector3 {
	float	x;
	float	y;
	float	z;
}				t_vector3;

typedef struct s_stvector2 {
	size_t	x;
	size_t	y;
}				t_stvector2;

typedef struct s_vector2 {
	float	x;
	float	y;
}				t_vector2;

typedef struct s_map {
	char		*path;
	size_t		h;
	size_t		w;
	int			**i_grid;
}				t_map;

typedef struct s_env {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			scale;
	float		alpha;
	float		sm_y;
	float		bg_y;
	float		sm_x;
	float		bg_x;
	t_vector2	offset;
	t_map		map;
	t_vector3	*points;
	t_vector2	*final_points;
	t_vector2	*rotated;
}				t_env;

#endif
