/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftmatrices.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 18:20:53 by saeby             #+#    #+#             */
/*   Updated: 2022/12/15 18:50:56 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTMATRICES_H
# define LIBFTMATRICES_H
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

// STRUCTURES
typedef struct s_vector3 {
	float	x;
	float	y;
	float	z;
}				t_vector3;

typedef struct s_vector2 {
	float	x;
	float	y;
}				t_vector2;

// PROTOTYPES
float		**ft_matmul(float **a, float **b, t_vector3 *v);
float		**ft_create_matrix(t_vector2 *v);
void		ft_print_matrix(float **a, t_vector2 *v);
void		ft_free_matrix(float **m, int rows);
float		**ft_vec3_to_matrix(t_vector3 v);
float		**ft_vec2_to_matrix(t_vector2 v);
t_vector3	ft_matrix_to_vec3(float **m);
t_vector2	ft_matrix_to_vec2(float **m);
void		ft_print_vector2(t_vector2 v);
void		ft_print_vector3(t_vector3 v);
void		ft_scale_vector2(t_vector2 *v, int s);
void		ft_scale_vector3(t_vector3 *v, int s);

#endif