/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:04:20 by saeby             #+#    #+#             */
/*   Updated: 2022/12/16 22:38:52 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_env *env)
{
	mlx_destroy_window(env->mlx, env->win);
	exit(0);
}

void	map_error(char *s)
{
	ft_printf("%s\n", s);
	exit(1);
}

void	init_map(t_env *env)
{
	parse_map_info(env);
	parse_map(env);
	fill_points_vector(env);
	free_i_grid(env);
	rotate_points(env);
	scale_points(env, env->scale);
	translate_points(env);
}
