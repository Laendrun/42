/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 21:48:17 by saeby             #+#    #+#             */
/*   Updated: 2022/12/15 23:34:44 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_i_grid(t_env *env)
{
	size_t	y;

	y = 0;
	while (++y < env->map.h)
		free(env->map.i_grid[y]);
	free(env->map.i_grid);
}

void	free_p_matrices(t_env *env)
{
	size_t	y;

	y = 0;
	while(++y < env->map.h)
		free(env->p_matrices[y]);
	free(env->p_matrices);
}