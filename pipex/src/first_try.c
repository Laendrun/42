/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saeby <saeby@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 16:37:06 by saeby             #+#    #+#             */
/*   Updated: 2022/12/28 15:27:12 by saeby            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://tldp.org/LDP/lpg/node11.html
// https://linuxhint.com/c-execve-function-usage/

#include "pipex.h"

int	main(int ac, char *av[], char *envp[])
{
	(void) ac;
	(void) av;
	(void) envp;
	char *const args1[] = {"/bin/ls", NULL};
	char *const args2[] = {"/usr/bin/grep", "Make", NULL};

	int fd[2];
	if (pipe(fd) == -1)
		return (1);

	int pid1 = fork();
	if (pid1 < 0)
		return (2);

	if (pid1 == 0)
	{
		// child process 1 (ls)
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/bin/ls", args1, envp);
	}


	int pid2 = fork();
	if (pid2 < 0)
		return (2);

	if (pid2 == 0)
	{
		// child process 2 (grep)
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		close(fd[1]);
		execve("/usr/bin/grep", args2, envp);
	}


	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

/* this nonsense works
int	main(int ac, char *av[], char *envp[])
{
	(void) ac;
	(void) av;
	//(void) envp;

	//char *binaryPath = "/bin/ls";
	char *const args[] = {"/bin/ls", "-la", NULL};
	//char *const env[] = {"HOSTNAME=www.linuxhint.com", NULL};
	execve("/bin/ls", args, envp);
	return (0);
}
*/