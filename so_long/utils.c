/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:17:56 by saeby             #+#    #+#             */
/*   Updated: 2022/12/09 13:17:11 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

int	keyHandler(int keycode, t_vars *vars)
{
	t_point	new_pos;

	new_pos.px_x = 0;
	new_pos.px_y = 0;
	if (keycode == 53)
		close_window(vars);
	else if (keycode == 49)
		switch_color(vars);
	else if (keycode == 2 || keycode == 124)
	{
		new_pos.px_x = SIZE;
		update_player_position(vars, new_pos);
	}
	else if (keycode == 0 || keycode == 123)
	{
		new_pos.px_x = -SIZE;
		update_player_position(vars, new_pos);
	}
	else if (keycode == 13 || keycode == 126)
	{
		new_pos.px_y = -SIZE;
		update_player_position(vars, new_pos);
	}
	else if (keycode == 1 || keycode == 125)
	{
		new_pos.px_y = SIZE;
		update_player_position(vars, new_pos);
	}
	else
		ft_printf("Keycode: %d\n", keycode);
	return(0);
}

void	switch_color(t_vars *vars)
{
	if (vars->bg_color == 0x00FF00)
		vars->bg_color = 0x0000FF;
	else if (vars->bg_color == 0x0000FF)
		vars->bg_color = 0xFF0000;
	else if (vars->bg_color == 0xFF0000)
		vars->bg_color = 0x00FF00;
	else
		vars->bg_color = 0x00FF00;
}

void	update_player_position(t_vars *vars, t_point np)
{
	if (vars->player.pos.px_x + np.px_x >= 0 && vars->player.pos.px_x + np.px_x <= vars->map.g_w*SIZE - SIZE)
		vars->player.pos.px_x += np.px_x;
	if (vars->player.pos.px_y + np.px_y >= 0 && vars->player.pos.px_y + np.px_y <= vars->map.g_h*SIZE - SIZE)
		vars->player.pos.px_y += np.px_y;
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}