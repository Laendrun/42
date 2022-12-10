/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:17:56 by saeby             #+#    #+#             */
/*   Updated: 2022/12/10 16:39:24 by saeby            ###   ########.fr       */
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

	new_pos.px_x = vars->player.pos.px_x;
	new_pos.px_y = vars->player.pos.px_y;
	if (keycode == 53 || keycode == 65307)
		close_window(vars);
	else if (keycode == 2 || keycode == 124 || keycode == 100)
	{
		new_pos.px_x = vars->player.pos.px_x + 1;
		update_player_position(vars, new_pos);
	}
	else if (keycode == 0 || keycode == 123 || keycode == 97)
	{
		new_pos.px_x = vars->player.pos.px_x - 1;
		update_player_position(vars, new_pos);
	}
	else if (keycode == 13 || keycode == 126 || keycode == 119)
	{
		new_pos.px_y = vars->player.pos.px_y - 1;
		update_player_position(vars, new_pos);
	}
	else if (keycode == 1 || keycode == 125 || keycode == 115)
	{
		new_pos.px_y = vars->player.pos.px_y + 1;
		update_player_position(vars, new_pos);
	}
	else
		ft_printf("Keycode: %d\n", keycode);
	return(0);
}

void	update_player_position(t_vars *vars, t_point np)
{
	if (np.px_x < vars->map.g_w && np.px_y < vars->map.g_h) // Check if inside window
	{
		if (vars->map.grid[np.px_y][np.px_x] == 'C')
		{
			vars->collected++;
			vars->map.grid[np.px_y][np.px_x] = '0';
			if (vars->collected == vars->collectibles)
				vars->exitUnlocked = 1;
			vars->player.pos = np;
		}
		else if (vars->map.grid[np.px_y][np.px_x] == '1')
			ft_printf("You're not a ghost!\n");
		else if (vars->map.grid[np.px_y][np.px_x] == 'E' && vars->exitUnlocked)
		{
			vars->player.pos = np;
			ft_printf("Congrats! You escaped the room!\n");
		}
		else
			vars->player.pos = np;
	}
}

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}