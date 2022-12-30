/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:37:43 by saeby             #+#    #+#             */
/*   Updated: 2022/12/30 16:39:54 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include "libft.h"

// utils.c
void	pip_error(char *s);
char	**pip_get_path(char **env);
char	*pip_get_exec(char *cmd, char **paths);

// main_bonus.c
void	pip_exec(char *bin_path, int fd_in, int fd_out, char **env);
void	pip_new_first_process(char *cmd, int (*op)[2], int (*ip)[2], char **env);
void	pip_new_second_process(char *cmd, int (*op)[2], int (*ip)[2], char **env);
void	pip_write(char *name, int in_fd);

#endif