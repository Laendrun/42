/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 22:54:37 by saeby             #+#    #+#             */
/*   Updated: 2022/12/17 16:38:40 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_points(t_env *env)
{
	size_t	i;

	i = 0;
	env->rotated = malloc(env->map.h * env->map.w * sizeof(t_vector2));
	env->final_points = malloc(env->map.h * env->map.w * sizeof(t_vector2));
	while (i < env->map.h * env->map.w)
	{
		env->rotated[i].x = env->points[i].x \
							* cosf(env->alpha) + env->points[i].y \
							* cosf(env->alpha + 2) + env->points[i].z \
							* cosf(env->alpha - 2);
		env->rotated[i].y = env->points[i].x \
							* sinf(env->alpha) + env->points[i].y \
							* sinf(env->alpha + 2) + env->points[i].z \
							* sinf(env->alpha - 2);
		env->final_points[i].x = env->rotated[i].x;
		env->final_points[i].y = env->rotated[i].y;
		i++;
	}
}

void	translate_points(t_env *env)
{
	size_t	i;

	i = 0;
	while (i < env->map.h * env->map.w)
	{
		env->final_points[i].x += (WIN_W - (env->map.w / 2) * env->scale) \
														/ 2 + env->offset.x;
		env->final_points[i].y += (WIN_H - (env->map.h / 2) * env->scale) \
														/ 2 + env->offset.y;
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
