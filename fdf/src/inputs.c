/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:03:29 by saeby             #+#    #+#             */
/*   Updated: 2022/12/16 20:08:43 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_handler(int keycode, t_env *env)
{
	if (keycode == 53)
		close_window(env);
	else
		printf("%d\n", keycode);
	return (0);
}