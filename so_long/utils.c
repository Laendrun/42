/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:17:56 by saeby             #+#    #+#             */
/*   Updated: 2022/12/10 02:41:10 by saeby            ###   ########.fr       */
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
	if (keycode == 53 || keycode == 65307)
		close_window(vars);
	else if (keycode == 2 || keycode == 124 || keycode == 100)
	{
		new_pos.px_x = SIZE;
		update_player_position(vars, new_pos);
	}
	else if (keycode == 0 || keycode == 123 || keycode == 97)
	{
		new_pos.px_x = -SIZE;
		update_player_position(vars, new_pos);
	}
	else if (keycode == 13 || keycode == 126 || keycode == 119)
	{
		new_pos.px_y = -SIZE;
		update_player_position(vars, new_pos);
	}
	else if (keycode == 1 || keycode == 125 || keycode == 115)
	{
		new_pos.px_y = SIZE;
		update_player_position(vars, new_pos);
	}
	else
		ft_printf("Keycode: %d\n", keycode);
	return(0);
}

void	update_player_position(t_vars *vars, t_point np)
{
	if (vars->player.pos.px_x + np.px_x <= vars->map.g_w * (SIZE + 1) - SIZE)
		vars->player.pos.px_x += np.px_x;
	if (vars->player.pos.px_y + np.px_y <= vars->map.g_h * (SIZE + 1) - SIZE)
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