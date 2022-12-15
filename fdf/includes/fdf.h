/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:56:32 by saeby             #+#    #+#             */
/*   Updated: 2022/12/16 00:23:11 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# ifndef WIN_W
#  define WIN_W 1280
# endif
# ifndef WIN_H
#  define WIN_H 720
# endif
# define WIN_NAME "fdf"
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"
# include "libftmatrices.h"
# include "fdf_structures.h"

// main.c
int		render(t_env *env);

// inputs.c
int		key_handler(int keycode, t_env *env);

// utils.c
int		close_window(t_env *env);
void	map_error(char *s);

// draw.c
void	ft_put_pixel(t_env *env, t_vector2 v, int color);
void	ft_draw_line(t_env *env, t_vector2 s, t_vector2 e, int col);
void	ft_draw_point(t_env *env, t_vector2 p, int col, int sw);
void	draw_background(t_env *env);

// map_parser.c
void	parse_map_info(t_env *env);
void	parse_map(t_env *env);
void	fill_points_vector(t_env *env);

// free.c
void	free_i_grid(t_env *env);
void	free_p_matrices(t_env *env);

// rotation.c
void	fill_rotation_matrices(t_env *env);
void	fill_rotation_matrix_x(t_env *env);
void	fill_rotation_matrix_y(t_env *env);
void	fill_rotation_matrix_z(t_env *env);

// points.c
void	rotate_points(t_env *env);
void	project_points(t_env *env);
void	translate_points(t_env *env);
void	scale_points(t_env *env, int s);

// projection.c
void	fill_projection_matrix(t_env *env);

#endif