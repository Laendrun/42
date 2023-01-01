/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby>                              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:37:43 by saeby             #+#    #+#             */
/*   Updated: 2023/01/01 16:55:48 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "libft.h"

// pipex_utils.c
void	pip_exec(char *bin_path, int fd_in, int fd_out, char **env);
void	pip_new_f_process(char *cmd, int (*p1)[2], int (*p2)[2], char **env);
void	pip_new_s_process(char *cmd, int (*p1)[2], int (*p2)[2], char **env);
char	**pip_get_path(char **env);
char	*pip_get_exec(char *cmd, char **paths);

// pipex_utils2.c
void	pip_error(char *s);
void	pip_write(char *name, int in_fd, int hd);
void	pip_close_fd(int fd1, int fd2);
void	pip_renew_pipe(int (*p)[2]);
void	pip_wait_children(int i);

// pipex_utils3.c
void	pip_write_result(int ac, char **av, int (*p1)[2], int (*p2)[2]);
void	pip_no_exec(char *s);

// checks.c
void	pip_check_ac(int ac);
int		pip_check_here_doc(char **av, int (*p)[2]);
void	pip_read_here_d(char *limiter, int fd_in, int fd_out);

#endif