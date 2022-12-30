/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:28:01 by saeby             #+#    #+#             */
/*   Updated: 2022/12/30 12:32:10 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *envp[])
{
	// char *const args1[] = {"/usr/bin/grep", "o", NULL};
	// char *const args2[] = {"/bin/cat", NULL};
	char	**args1;
	char	**args2;
	char	**paths;

	int	fd[2];
	int	fd_in;
	int	fd_out;
	int	pid1;
	int	pid2;

	if (ac != 5)
		pip_error("Wrong number of argument.");
	if (access("infile", R_OK) != 0)
		pip_error("infile not accessible in read mode.");
	if (access("outfile", W_OK) != 0)
		pip_error("outfile not accessible in write mode.");

	fd_in = open("infile", O_RDONLY);
	fd_out = open("outfile", O_WRONLY);
	paths = pip_get_path(envp);
	if (pipe(fd) == -1)
		pip_error("Error creating the pipe (1).");
	pid1 = fork();
	if (pid1 < 0)
		pip_error("Error when forking (2).");
	if (pid1 == 0)
	{
		// first child process handling cmd1
		args1 = ft_split(av[2], ' ');
		args1[0] = pip_get_exec(args1[0], paths);
		// replace standard input with input file fd
		dup2(fd_in, STDIN_FILENO);
		// replace standard output with output part of pipe
		dup2(fd[1], STDOUT_FILENO);
		// close the unused fds
		close(fd[0]);
		close(fd_out);
		//free(paths);
		execve(args1[0], args1, envp);
	}
	
	pid2 = fork();
	if (pid2 < 0)
		pip_error("Error when forking (3).");
	if (pid2 == 0)
	{
		// second child process handling cmd2
		args2 = ft_split(av[3], ' ');
		args2[0] = pip_get_exec(args2[0], paths);
		// replace standard input with input part of the pipe
		dup2(fd[0], STDIN_FILENO);
		// replace standard output with output file fd
		dup2(fd_out, STDOUT_FILENO);
		close(fd[1]);
		close(fd_out);
		execve(args2[0], args2, envp);
	}

	close(fd[0]);
	close(fd[1]);
	close(fd_in);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	//ft_printf("fd_in: %d\nfd_out: %d\n", fd_in, fd_out);
	return (0);
}

/* 
1. put the content of the infile into the stdin
2. the first command read from the stdin
3. redirect the output of the first command into the input of the second command via the pipe
4. second command reads from the input coming from the pipe
5. second command output is written in the outfile
*/