/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:17:56 by saeby             #+#    #+#             */
/*   Updated: 2022/12/05 12:16:15 by saeby            ###   ########.fr       */
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

	new_pos.x = 0;
	new_pos.y = 0;
	if (keycode == 53)
		close_window(vars);
	else if (keycode == 49)
		switch_color(vars);
	else if (keycode == 2 || keycode == 124)
	{
		new_pos.x = SIZE;
		update_player_position(vars, new_pos);
	}
	else if (keycode == 0 || keycode == 123)
	{
		new_pos.x = -SIZE;
		update_player_position(vars, new_pos);
	}
	else if (keycode == 13 || keycode == 126)
	{
		new_pos.y = -SIZE;
		update_player_position(vars, new_pos);
	}
	else if (keycode == 1 || keycode == 125)
	{
		new_pos.y = SIZE;
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
}

void	update_player_position(t_vars *vars, t_point new_pos)
{
	if (vars->player.position.x + new_pos.x >= 0 && vars->player.position.x + new_pos.x <= vars->map.width*SIZE+1 - SIZE)
		vars->player.position.x += new_pos.x;
	if (vars->player.position.y + new_pos.y >= 0 && vars->player.position.y + new_pos.y <= vars->map.height*SIZE+1 - SIZE)
		vars->player.position.y += new_pos.y;
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}