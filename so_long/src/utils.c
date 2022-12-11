/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:17:56 by saeby             #+#    #+#             */
/*   Updated: 2022/12/11 17:03:35 by saeby            ###   ########.fr       */
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
	if (keycode == 53 || keycode == 65307)
		close_window(vars);
	else if (keycode == 2 && !vars->won)
		update_player_position(vars, (t_point){vars->player.pos.px_x + 1, vars->player.pos.px_y});
	else if (keycode == 0 && !vars->won)
		update_player_position(vars, (t_point){vars->player.pos.px_x - 1, vars->player.pos.px_y});
	else if (keycode == 13 && !vars->won)
		update_player_position(vars, (t_point){vars->player.pos.px_x, vars->player.pos.px_y - 1});
	else if (keycode == 1 && !vars->won)
		update_player_position(vars, (t_point){vars->player.pos.px_x, vars->player.pos.px_y + 1});
	//else
	//	ft_printf("Keycode: %d\n", keycode);
	return(0);
}

void	update_player_position(t_vars *vars, t_point np)
{
	ft_printf("Total moves: %d\n", ++vars->moves);
	if (np.px_x < vars->map.g_w && np.px_y < vars->map.g_h) // Check if inside window
	{
		if (vars->map.grid[np.px_y][np.px_x] == COLLECT)
		{
			vars->collected++;
			vars->map.grid[np.px_y][np.px_x] = FLOOR;
			if (vars->collected == vars->collectibles)
				vars->exit_unlocked = 1;
			vars->player.pos = np;
		}
		else if (vars->map.grid[np.px_y][np.px_x] == EXIT && vars->exit_unlocked)
		{
			vars->player.pos = np;
			vars->won = 1;
		}
		else if (vars->map.grid[np.px_y][np.px_x] != WALL)
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

size_t	ft_linelen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	return (i);
}

void	free_tiles(t_vars *vars)
{
	size_t	i;

	i = 0;
	while (i < vars->map.g_h)
	{
		free(vars->map.tiles[i]);
		vars->map.tiles[i] = NULL;
		i++;
	}
	free(vars->map.tiles);
	vars->map.tiles = NULL;
}

void	free_grid(t_vars *vars)
{
	size_t	i;

	i = 0;
	while (i < vars->map.g_h)
	{
		free(vars->map.grid[i]);
		vars->map.grid[i] = NULL;
		i++;
	}
	free(vars->map.grid);
	vars->map.tiles = NULL;
}

int	check_map_name(char *s)
{
	size_t	l;

	l = ft_strlen(s) - 1;
	if (s[l] == 'r' && s[l - 1] == 'e' && s[l - 2] == 'b' && s[l - 3] == '.')
		return (0);
	return (1);
}