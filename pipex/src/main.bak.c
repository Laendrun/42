/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 15:30:47 by saeby             #+#    #+#             */
/*   Updated: 2022/12/28 18:27:20 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char *av[], char *envp[])
{
	(void) ac;
	(void) av;
	(void) envp;
	int		fd[2];
	int		fd_in;
	int		fd_out;
	int		pid1;
	// char *const args1[] = {"/bin/ls", NULL};
	// char *const args2[] = {"/bin/cat", NULL};
	int		pid2;
	char	**args1;
	char	*line;

	fd_in = open("infile", O_RDONLY);
	fd_out = open("outfile", O_WRONLY);

	//if (ac != 5)
	//	exit(1);
	// if (access(av[1], R_OK) == 0)
		// fd_in = open(av[1], O_RDONLY);
	// else
		// pip_error("No read access on the infile.");
	//if (access(av[4], W_OK) == 0)
	//	fd_out = open(av[4], O_WRONLY);
	// else
		// pip_error("No write access on the outfile.");

	//args1 = ft_split(av[2], ' ');
	// args2 = ft_split(av[3], ' ');

	if (pipe(fd) == -1)
		pip_error("Error creating the pipe.");

	pid1 = fork();
	if (pid1 < 0)
		pip_error("Error when forking (1).");

	if (pid1 == 0)
	{
		// first child process
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/bin/ls", (char *const *)args1, envp);

	}

	pid2 = fork();
	if (pid2 < 0)
		pip_error("Error when forking (2).");

	if (pid2 == 0)
	{
		// second child process
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		//execve("/bin/cat", args2, envp);
	}

	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

/*
./pipex infile "cmd1" "cmd2" outfile
should do the same thing as
< infile cmd1 | cmd2 > outfile

< : takes the content of the infile and put it on the stdin
cmd1 : reads from stdin and outputs on the stdout
| : redirects the output of cmd1 to the input of cmd2
cmd2 : reads from its own input
> : writes the output of cmd2 in the oufile
*/
