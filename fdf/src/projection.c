/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 23:38:04 by saeby             #+#    #+#             */
/*   Updated: 2022/12/15 23:51:58 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_projection_matrix(t_env *env)
{
	env->projection = ft_create_matrix(&(t_vector2){2, 3});
	env->projection[0][0] = 1;
	env->projection[0][1] = 0;
	env->projection[0][2] = 0;
	
	env->projection[1][0] = 0;
	env->projection[1][1] = 1;
	env->projection[1][2] = 0;
}