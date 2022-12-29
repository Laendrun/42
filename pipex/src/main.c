/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 18:28:01 by saeby             #+#    #+#             */
/*   Updated: 2022/12/29 19:35:45 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *envp[])
{
	(void) ac;
	(void) av;
	(void) envp;

	char *const args1[] = {"/usr/bin/grep", "u", NULL};
	char *const args2[] = {"/bin/cat", NULL};

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
	if (pipe(fd) == -1)
		pip_error("Error creating the pipe (1).");
	pid1 = fork();
	if (pid1 < 0)
		pip_error("Error when forking (2).");
	if (pid1 == 0)
	{
		// first child process handling cmd1

		// replace standard input with input file fd
		dup2(fd_in, STDIN_FILENO);
		// replace standard output with output part of pipe
		dup2(fd[1], STDOUT_FILENO);
		// close the unused fds
		close(fd[0]);
		close(fd[1]);
		close(fd_in);
		close(fd_out);
		execve("/usr/bin/grep", args1, envp);
	}
	
	pid2 = fork();
	if (pid2 < 0)
		pip_error("Error when forking (3).");
	if (pid2 == 0)
	{
		// second child process handling cmd2
		
		// replace standard input with input part of the pipe
		dup2(fd[0], STDIN_FILENO);
		// replace standard output with output file fd
		dup2(fd_out, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		close(fd_in);
		close(fd_out);
		execve("/bin/cat", args2, envp);
	}

	close(fd[0]);
	close(fd[1]);
	close(fd_in);
	close(fd_out);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	ft_printf("fd_in: %d\nfd_out: %d\n", fd_in, fd_out);
	return (0);
}

/* 
1. put the content of the infile into the stdin
2. the first command read from the stdin
3. redirect the output of the first command into the input of the second command via the pipe
4. second command reads from the input coming from the pipe
5. second command output is written in the outfile
*/