/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:03:29 by saeby             #+#    #+#             */
/*   Updated: 2022/12/17 16:37:21 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_handler(int keycode, t_env *env)
{
	if (keycode == 53)
		close_window(env);
	else if (keycode == 0 || keycode == 123)
		env->offset.x -= 10;
	else if (keycode == 2 || keycode == 124)
		env->offset.x += 10;
	else if (keycode == 1 || keycode == 125)
		env->offset.y += 10;
	else if (keycode == 13 || keycode == 126)
		env->offset.y -= 10;
	else
		ft_printf("%d\n", keycode);
	return (0);
}

int	mouse_handler(int mousecode, int x, int y, t_env *env)
{
	(void) x;
	(void) y;
	if (mousecode == 4 && env->scale - 1 > 0)
		env->scale--;
	if (mousecode == 5)
		env->scale++;
	return (0);
}
