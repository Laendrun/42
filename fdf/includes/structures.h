/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/11 20:51:56 by saeby             #+#    #+#             */
/*   Updated: 2022/12/11 21:51:56 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef struct s_map {
	char		*path;
	size_t		g_h;
	size_t		g_w;
	char		***c_grid;
	int			**i_grid;
}				t_map;

typedef struct s_vars {
	void		*mlx;
	void		*win;
	void		*img;
	char		*addr;
	t_map		map;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
}				t_vars;

#endif