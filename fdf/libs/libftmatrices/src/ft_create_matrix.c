/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:25:49 by saeby             #+#    #+#             */
/*   Updated: 2022/12/15 18:25:57 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmatrices.h"

float	**ft_create_matrix(t_vector2 *v)
{
	float	**result;

	result = malloc(v->x * sizeof(float *));
	for (int i = 0; i < v->x; i++)
		result[i] = malloc(v->y * sizeof(float));
	return (result);
}