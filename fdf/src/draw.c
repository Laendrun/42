/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:07:33 by saeby             #+#    #+#             */
/*   Updated: 2022/12/16 00:23:49 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_put_pixel(t_env *env, t_vector2 v, int color)
{
	char	*dst;

	dst = env->addr + ((int)v.y * env->line_length + (int)v.x * (env->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	ft_draw_line(t_env *env, t_vector2 s, t_vector2 e, int col)
{
	float	delta_x, delta_y, step, x, y;
	int		i;

	delta_x = e.x - s.x;
	delta_y = e.y - s.y;
	if (fabsf(delta_x) >= fabsf(delta_y))
		step = fabsf(delta_x);
	else
		step = fabsf(delta_y);
	delta_x = delta_x / step;
	delta_y = delta_y / step;
	x = s.x;
	y = s.y;
	i = 0;
	while (i < step)
	{
		ft_put_pixel(env, (t_vector2){x, y}, col);
		x = x + delta_x;
		y = y + delta_y;
		i++;
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
