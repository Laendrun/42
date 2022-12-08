/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:01:41 by saeby             #+#    #+#             */
/*   Updated: 2022/12/05 18:02:32 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render(void *param)
{
	t_vars	*vars;
	t_point	bg_start;
	t_point	bg_end;

	vars = param;

	bg_start.x = 0;
	bg_start.y = 0;
	bg_end.x = vars->map.width * SIZE;
	bg_end.y = vars->map.height * SIZE;

	draw_background(vars, bg_start, bg_end);
}