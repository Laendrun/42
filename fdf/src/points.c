/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:54:37 by saeby             #+#    #+#             */
/*   Updated: 2022/12/16 20:58:14 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_points(t_env *env)
{
	size_t	i;
	
	i = 0;
	//env->p_matrices = malloc (env->map.h * env->map.w * sizeof(float **));
	env->rotated = malloc(env->map.h * env->map.w * sizeof(float **));
	while (i < env->map.h * env->map.w)
	{
		//env->p_matrices[i] = ft_vec3_to_matrix(env->points[i]);
		//env->rotated[i] = ft_matmul(env->rot_matrix_y, env->p_matrices[i], &(t_vector3){3, 3, 1});
		env->points[i].x = env->points[i].x * cosf(env->alpha) + env->points[i].y * cosf(env->alpha + 2) + env->points[i].z * cosf(env->alpha - 2);
		env->points[i].y = env->points[i].x * sinf(env->alpha) + env->points[i].y * sinf(env->alpha + 2) + env->points[i].z * sinf(env->alpha - 2);
		env->rotated[i] = ft_vec3_to_matrix(env->points[i]);
		//ft_print_matrix(env->rotated[i], &(t_vector2){3,1});
		//env->rotated[i] = ft_matmul(env->rot_matrix_x, env->rotated[i], &(t_vector3){3, 3, 1});
		//env->rotated[i] = ft_matmul(env->rot_matrix_z, env->rotated[i], &(t_vector3){3, 3, 1});
		i++;
	}
	//free_p_matrices(env);
}

void	project_points(t_env *env)
{
	size_t	i;

	i = 0;
	//env->projected = malloc(env->map.h * env->map.w * sizeof(float **));
	env->final_points = malloc(env->map.h * env->map.w * sizeof(t_vector2));
	while (i < env->map.h * env->map.w)
	{
		//env->projected[i] = ft_matmul(env->projection, env->rotated[i], &(t_vector3){3, 3, 1});
		//printf("i: %zu - ",i);
		//ft_print_matrix(env->rotated[i], &(t_vector2){3,1});
		env->final_points[i] = ft_matrix_to_vec2(env->rotated[i]);
		i++;
	}
}

void	translate_points(t_env *env)
{
	size_t	i;

	i = 0;
	while (i < env->map.h * env->map.w)
	{
		env->final_points[i].x += (WIN_W - env->map.w * env->scale) / 2;
		env->final_points[i].y += (WIN_H - env->map.h * env->scale) / 2;
		i++;
	}
}

void	scale_points(t_env *env, int s)
{
	size_t	i;

	i = 0;
	while (i < env->map.h * env->map.w)
	{
		env->final_points[i].x *= s;
		env->final_points[i].y *= s;
		i++;
	}
}