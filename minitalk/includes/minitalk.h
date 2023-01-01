/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/31 16:03:39 by saeby             #+#    #+#             */
/*   Updated: 2023/01/01 19:43:58 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H
# include <limits.h>
# include <signal.h>
# include <stdlib.h>
# include "libft.h"

// client.c
void	mt_c_receive_message(int signum);
void	mt_c_sighand(int signum);

// server.c
void	mt_s_sighand(int signum);
void	mt_s_receive_message(int signum);
char	*mt_s_handle_mess(char **message, int *endmess);
char	*mt_s_handle_rece(char **message, int *endmess);

//mt_utils.c
char	*mt_strjoin(char *s, char c);
void	mt_send_endmess(int pid);
void	mt_send_message(int pid, char *message);
char	mt_s_handle_bit(char c, int signum, int counter);
void	mt_s_send_receipt(int c_pid, char *message);

#endif