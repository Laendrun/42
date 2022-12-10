/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 20:17:56 by saeby             #+#    #+#             */
/*   Updated: 2022/12/10 22:00:21 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	int_len(long nbr);
static char	*pre_conv(int len);

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
		vars->moves++;
		update_player_position(vars, new_pos);
	}
	else if (keycode == 0 || keycode == 123 || keycode == 97)
	{
		new_pos.px_x = vars->player.pos.px_x - 1;
		vars->moves++;
		update_player_position(vars, new_pos);
	}
	else if (keycode == 13 || keycode == 126 || keycode == 119)
	{
		new_pos.px_y = vars->player.pos.px_y - 1;
		vars->moves++;
		update_player_position(vars, new_pos);
	}
	else if (keycode == 1 || keycode == 125 || keycode == 115)
	{
		new_pos.px_y = vars->player.pos.px_y + 1;
		vars->moves++;
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
		if (vars->map.grid[np.px_y][np.px_x] == COLLECTIBLE)
		{
			vars->collected++;
			vars->map.grid[np.px_y][np.px_x] = FLOOR;
			if (vars->collected == vars->collectibles)
				vars->exitUnlocked = 1;
			vars->player.pos = np;
		}
		else if (vars->map.grid[np.px_y][np.px_x] == WALL)
			ft_printf("You're not a ghost!\n");
		else if (vars->map.grid[np.px_y][np.px_x] == EXIT && vars->exitUnlocked)
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

/**
 * @fn char *ft_itoa(int n)
 * Converts an int to a string (char *)
 * @brief Converts an int to a string
 * @param n number to convert to string
 * @return char* 
 * @retval NULL If the memory allocation failed
 * @retval char* Number converted to string
 */
char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*result;
	long	nbr;

	nbr = n;
	len = int_len(nbr);
	result = pre_conv(len);
	if (!result)
		return (NULL);
	if (nbr < 0)
		nbr = -nbr;
	i = len - 1;
	while (nbr != 0)
	{
		result[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	if (n < 0)
		result[0] = '-';
	result[len] = '\0';
	return (result);
}

/**
 * @fn static char *pre_conv(int len)
 * @param len length of the number that will be converted
 * @param len this length is the number of chars
 * @return char* allocated string in memory
 */
static char	*pre_conv(int len)
{
	char	*tmp;

	tmp = malloc((len + 1) * sizeof(char));
	if (!tmp)
		return (0);
	else
	{
		tmp[0] = '0';
		return (tmp);
	}
}

/**
 * @fn static int int_len(long nbr)
 * @param nbr the number for which we want to count the 
 * @param nbr number of characters
 * @return int
 * @retval int The number of characters needed to write nbr
 */
static int	int_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}