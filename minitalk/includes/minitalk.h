/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:03:39 by saeby             #+#    #+#             */
/*   Updated: 2022/12/31 19:04:30 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include "libft.h"

// client.c
void	mt_c_send_message(int pid, char *message);

// server.c
void	mt_s_sighand(int signum);
void	mt_s_receive_message(int signum);

//mt_utils.c
char	*mt_strjoin(char *s, char c);
void	mt_c_send_endmess(int pid);

#endif