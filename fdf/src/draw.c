/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:07:33 by saeby             #+#    #+#             */
/*   Updated: 2022/12/17 14:04:10 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_env *env, t_vector2 v, int color)
{
	char	*dst;

	if (v.x >= 0 && v.x < WIN_W && v.y >= 0 && v.y < WIN_H)
	{	
		dst = env->addr + ((int)v.y * env->line_length \
									+ (int)v.x * (env->bits_per_pixel / 8));
		*(unsigned int *)dst = color;
	}
}

void	ft_draw_line(t_env *env, t_vector2 s, t_vector2 e, int col)
{
	float		step;
	t_vector3	v;
	t_vector2	delta;

	delta.x = e.x - s.x;
	delta.y = e.y - s.y;
	if (fabsf(delta.x) >= fabsf(delta.y))
		step = fabsf(delta.x);
	else
		step = fabsf(delta.y);
	delta.x = delta.x / step;
	delta.y = delta.y / step;
	v.x = s.x;
	v.y = s.y;
	v.z = 0;
	while (v.z < step)
	{
		ft_put_pixel(env, (t_vector2){v.x, v.y}, col);
		v.x = v.x + delta.x;
		v.y = v.y + delta.y;
		v.z++;
	}
}

void	ft_draw_point(t_env *env, t_vector2 p, int col, int sw)
{
	size_t	y;
	size_t	x;

	y = p.y - sw;
	x = p.x - sw;
	while (y <= p.y + sw)
	{
		while (++x <= p.x + sw)
			ft_put_pixel(env, (t_vector2){x, y}, col);
		x = p.x - sw;
		y++;
	}
}

void	draw_background(t_env *env)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= WIN_H)
	{
		while (j <= WIN_W)
		{
			ft_put_pixel(env, (t_vector2){j, i}, 0x000000);
			j++;
		}
		j = 0;
		i++;
	}
}

void	connect(t_env *env, int i, int j, t_vector2 *points)
{
	ft_draw_line(env, points[i], points[j], 0xFFFFFFFF);
}
