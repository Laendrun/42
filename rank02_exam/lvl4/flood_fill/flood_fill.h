/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 16:57:40 by saeby             #+#    #+#             */
/*   Updated: 2023/01/02 17:02:01 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FLOOD_FILL_H
# define FLOOD_FILL_H

	typedef struct	s_point
	{
	int	x;
	int	y;
	}	t_point;

void	flood_fill(char **tab, t_point size, t_point begin);
void	fill(char **tab, t_point size, t_point current, char c);

#endif