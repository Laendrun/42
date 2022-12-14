/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 16:11:39 by saeby             #+#    #+#             */
/*   Updated: 2022/12/14 10:34:14 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(t_vars *vars, char *map_path)
{
	vars->map.path = map_path;
	vars->collected = 0;
	vars->exit_unlocked = FALSE;
	vars->map.exit_accessible = FALSE;
	vars->map.accessible_collectibles = 0;
	vars->collectibles = 0;
	vars->won = FALSE;
	vars->moves = 0;
	vars->exit_found = 0;
	vars->start_found = 0;
}

void	load_sprites(t_vars *vars)
{
	load_map_sprites(vars);
	load_digits_sprites(vars);
}

void	load_map_sprites(t_vars *vars)
{
	vars->p_sp.img = mlx_xpm_file_to_image(vars->mlx, "img/p_sp.xpm", \
									&vars->p_sp.px_w, &vars->p_sp.px_h);
	vars->w_sp.img = mlx_xpm_file_to_image(vars->mlx, "img/w_sp.xpm", \
									&vars->w_sp.px_w, &vars->w_sp.px_h);
	vars->s_sp.img = mlx_xpm_file_to_image(vars->mlx, "img/s_sp.xpm", \
									&vars->s_sp.px_w, &vars->s_sp.px_h);
	vars->c_sp.img = mlx_xpm_file_to_image(vars->mlx, "img/c_sp_3.xpm", \
									&vars->c_sp.px_w, &vars->c_sp.px_h);
	vars->e_sp.img = mlx_xpm_file_to_image(vars->mlx, "img/e_sp.xpm", \
									&vars->e_sp.px_w, &vars->e_sp.px_h);
	vars->f_sp.img = mlx_xpm_file_to_image(vars->mlx, "img/f_sp.xpm", \
									&vars->f_sp.px_w, &vars->f_sp.px_h);
	vars->yw_sp.img = mlx_xpm_file_to_image(vars->mlx, "img/yw_sp.xpm", \
									&vars->yw_sp.px_w, &vars->yw_sp.px_h);
}

void	load_digits_sprites(t_vars *vars)
{
	vars->digits_sp = malloc(10 * sizeof(t_sprite));
	vars->digits_sp[0].img = mlx_xpm_file_to_image(vars->mlx, "img/0_sp.xpm", \
						&vars->digits_sp[0].px_w, &vars->digits_sp[0].px_h);
	vars->digits_sp[1].img = mlx_xpm_file_to_image(vars->mlx, "img/1_sp.xpm", \
						&vars->digits_sp[1].px_w, &vars->digits_sp[1].px_h);
	vars->digits_sp[2].img = mlx_xpm_file_to_image(vars->mlx, "img/2_sp.xpm", \
						&vars->digits_sp[2].px_w, &vars->digits_sp[2].px_h);
	vars->digits_sp[3].img = mlx_xpm_file_to_image(vars->mlx, "img/3_sp.xpm", \
						&vars->digits_sp[3].px_w, &vars->digits_sp[3].px_h);
	vars->digits_sp[4].img = mlx_xpm_file_to_image(vars->mlx, "img/4_sp.xpm", \
						&vars->digits_sp[4].px_w, &vars->digits_sp[4].px_h);
	vars->digits_sp[5].img = mlx_xpm_file_to_image(vars->mlx, "img/5_sp.xpm", \
						&vars->digits_sp[5].px_w, &vars->digits_sp[5].px_h);
	vars->digits_sp[6].img = mlx_xpm_file_to_image(vars->mlx, "img/6_sp.xpm", \
						&vars->digits_sp[6].px_w, &vars->digits_sp[6].px_h);
	vars->digits_sp[7].img = mlx_xpm_file_to_image(vars->mlx, "img/7_sp.xpm", \
						&vars->digits_sp[7].px_w, &vars->digits_sp[7].px_h);
	vars->digits_sp[8].img = mlx_xpm_file_to_image(vars->mlx, "img/8_sp.xpm", \
						&vars->digits_sp[8].px_w, &vars->digits_sp[8].px_h);
	vars->digits_sp[9].img = mlx_xpm_file_to_image(vars->mlx, "img/9_sp.xpm", \
						&vars->digits_sp[9].px_w, &vars->digits_sp[9].px_h);
}

void	update_player_position(t_vars *vars, t_point np)
{
	ft_printf("Total moves: %d\n", ++vars->moves);
	if (np.px_x < vars->map.g_w && np.px_y < vars->map.g_h)
	{
		if (vars->map.grid[np.px_y][np.px_x] == COLLECT)
		{
			vars->collected++;
			vars->map.grid[np.px_y][np.px_x] = FLOOR;
			if (vars->collected == vars->collectibles)
				vars->exit_unlocked = 1;
			vars->player.pos = np;
		}
		else if (vars->map.grid[np.px_y][np.px_x] == EXIT \
									&& vars->exit_unlocked)
		{
			vars->player.pos = np;
			vars->won = 1;
		}
		else if (vars->map.grid[np.px_y][np.px_x] != WALL)
			vars->player.pos = np;
	}
}
