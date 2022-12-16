/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:24:27 by saeby             #+#    #+#             */
/*   Updated: 2022/12/16 22:38:49 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	connect_points(t_env *env, t_vector3 v)
{
	if (v.x != env->map.w - 1 && v.y != env->map.h - 1)
	{
		connect(env, v.z, (v.x + 1) + v.y * env->map.w, env->final_points);
		connect(env, v.z, v.x + (v.y + 1) * env->map.w, env->final_points);
	}
	if (v.x == env->map.w - 1 && v.y != env->map.h - 1)
		connect(env, v.z, v.x + (v.y + 1) * env->map.w, env->final_points);
	if (v.x != env->map.w - 1 && v.y == env->map.h - 1)
		connect(env, v.z, (v.x + 1) + v.y * env->map.w, env->final_points);
}
