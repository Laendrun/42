/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/16 22:24:27 by saeby             #+#    #+#             */
/*   Updated: 2022/12/18 11:25:51 by saeby            ###   ########.fr       */
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

void	limits(t_env *env)
{
	env->bg_x = env->final_points[(env->map.w - 1) + 0 * env->map.w].x;
	env->sm_x = env->final_points[0 + (env->map.h - 1) * env->map.w].x;
	env->bg_y = env->final_points[(env->map.w - 1) + (env->map.h - 1) * env->map.w].y;
	env->sm_y = env->final_points[0].y;

	if (env->sm_x > WIN_W)
		draw_arrow_right(env);
	if (env->bg_x < 0)
		draw_arrow_left(env);
	if (env->bg_y < 0)
		draw_arrow_up(env);
	if (env->sm_y > WIN_H)
		draw_arrow_down(env);
}
