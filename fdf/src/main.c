/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 17:54:17 by saeby             #+#    #+#             */
/*   Updated: 2022/12/16 00:33:59 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char *av[])
{
	t_env	env;
	if (ac != 2)
	{
		ft_printf("No map specified.\n");
		exit(1);
	}
	env.map.path = av[1];
	parse_map_info(&env);
	parse_map(&env);
	fill_points_vector(&env);
	free_i_grid(&env);
	env.angle = 5.5;
	fill_rotation_matrices(&env);
	rotate_points(&env);
	fill_projection_matrix(&env);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_W, WIN_H, WIN_NAME);
	env.img = mlx_new_image(env.mlx, WIN_W, WIN_H);
	env.addr = mlx_get_data_addr(env.img, &env.bits_per_pixel, \
									&env.line_length, &env.endian);
	mlx_hook(env.win, 2, 1L << 0, key_handler, &env);
	mlx_hook(env.win, 17, 1L << 0, close_window, &env);
	mlx_loop_hook(env.mlx, render, &env);
	mlx_loop(env.mlx);
	return (0);
}

int	render(t_env *env)
{
	//printf("angle: %f\n", env->angle);
	//fill_rotation_matrices(env);
	//rotate_points(env);
	//env->angle += 0.01;
	draw_background(env);
	project_points(env);
	scale_points(env, 10);
	translate_points(env);
	size_t	i;

	i = 0;
	while (i < env->map.h * env->map.w)
	{
		ft_draw_point(env, (t_vector2){env->final_points[i].x, env->final_points[i].y}, 0xFFFFFFFF, 1);
		i++;
	}
	//ft_draw_line(env, (t_vector2){0, WIN_H}, (t_vector2){WIN_W, 0}, 0xFFFF0000);
	//ft_draw_line(env, (t_vector2){0, 0}, (t_vector2){WIN_W, WIN_H}, 0xFF00FF00);
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}