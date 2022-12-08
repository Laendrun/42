/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:09:58 by saeby             #+#    #+#             */
/*   Updated: 2022/12/05 18:18:57 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	key_hook(mlx_key_data_t keydata, void *param)
{
		t_vars	*vars;

		vars = param;
		if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_PRESS)
			vars->bg_color = 0xFF0000FF;
		if (keydata.key == MLX_KEY_SPACE && keydata.action == MLX_RELEASE)
			vars->bg_color = 0x000000FF;
		if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
			close_prog(vars);
}

void	close_prog(t_vars *vars)
{
	mlx_terminate(vars->mlx);
	exit(0);
}