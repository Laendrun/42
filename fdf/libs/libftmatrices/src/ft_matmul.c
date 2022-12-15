/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matmul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:19:35 by saeby             #+#    #+#             */
/*   Updated: 2022/12/15 23:22:19 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftmatrices.h"

float	**ft_matmul(float **a, float **b, t_vector3 *v)
{
	/*
	 * v->x : rowsA
	 * v->y : colsA
	 * v->z : colsB
	 */
	float **result = malloc(v->x * sizeof(float *));
	for (int i = 0; i < v->x; i++) 
	{
		result[i] = malloc(v->z * sizeof(float));
		for (int j = 0; j < v->z; j++)
		{
			float	sum = 0;
			for (int k = 0; k < v->y; k++)
				sum += a[i][k] * b[k][j];
			result[i][j] = sum;
		}
	}
	return (result);
}