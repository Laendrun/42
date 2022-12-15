/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:05:34 by saeby             #+#    #+#             */
/*   Updated: 2022/12/16 00:01:48 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_rotation_matrices(t_env *env)
{
	fill_rotation_matrix_x(env);
	fill_rotation_matrix_y(env);
	fill_rotation_matrix_z(env);
}

void	fill_rotation_matrix_x(t_env *env)
{
	env->rot_matrix_x = ft_create_matrix(&(t_vector2){3, 3});
	env->rot_matrix_x[0][0] = 1;
	env->rot_matrix_x[0][1] = 0;
	env->rot_matrix_x[0][2] = 0;
	env->rot_matrix_x[1][0] = 0;
	env->rot_matrix_x[1][1] = cosf(env->angle);
	env->rot_matrix_x[1][2] = -sinf(env->angle);
	env->rot_matrix_x[2][0] = 0;
	env->rot_matrix_x[2][1] = sinf(env->angle);
	env->rot_matrix_x[2][2] = cosf(env->angle);
}

void	fill_rotation_matrix_y(t_env *env)
{
	env->rot_matrix_y = ft_create_matrix(&(t_vector2){3, 3});
	env->rot_matrix_y[0][0] = cosf(env->angle);
	env->rot_matrix_y[0][1] = 0;
	env->rot_matrix_y[0][2] = sinf(env->angle);
	env->rot_matrix_y[1][0] = 0;
	env->rot_matrix_y[1][1] = 1;
	env->rot_matrix_y[1][2] = 0;
	env->rot_matrix_y[2][0] = -sinf(env->angle);
	env->rot_matrix_y[2][1] = 0;
	env->rot_matrix_y[2][2] = cosf(env->angle);
}

void	fill_rotation_matrix_z(t_env *env)
{
	env->rot_matrix_z = ft_create_matrix(&(t_vector2){3, 3});
	env->rot_matrix_z[0][0] = cosf(env->angle);
	env->rot_matrix_z[0][1] = -sinf(env->angle);
	env->rot_matrix_z[0][2] = 0;
	env->rot_matrix_z[1][0] = sinf(env->angle);
	env->rot_matrix_z[1][1] = cosf(env->angle);
	env->rot_matrix_z[1][2] = 0;
	env->rot_matrix_z[2][0] = 0;
	env->rot_matrix_z[2][1] = 0;
	env->rot_matrix_z[2][2] = 1;
}