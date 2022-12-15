/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_structures.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:52:47 by saeby             #+#    #+#             */
/*   Updated: 2022/12/16 00:10:16 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_STRUCTURES_H
# define FDF_STRUCTURES_H

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
	t_map		map;
	t_vector3	*points;
	float		***rotated;
	float		***projected;
	float		***p_matrices;
	float		angle;
	float		**rot_matrix_x;
	float		**rot_matrix_y;
	float		**rot_matrix_z;
	float		**projection;
	t_vector2	*final_points;
}				t_env;

#endif
