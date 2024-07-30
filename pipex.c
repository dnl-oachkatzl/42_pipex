/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:11:57 by daspring          #+#    #+#             */
/*   Updated: 2024/07/30 18:52:59 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/fcntl.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

void	run_second_command(char *argv[], int fd[], char *envp[]);
void	run_first_command(char *argv[], int fd[], char *envp[]);

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		return (EXIT_FAILURE);
	pid = fork();
	if (pid == 0)
	{
		run_first_command(argv, fd, envp);
	}
	else
	{
		// wait(NULL);
		run_second_command(argv, fd, envp);
	}
	return (EXIT_SUCCESS);
}

void	run_second_command(char *argv[], int fd[], char *envp[])
{
	int	filedes;

	filedes = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (filedes == -1)
		exit(EXIT_FAILURE);
	dup2(filedes, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(filedes);
	char	*argv2[] = {"cat", NULL};
	execve("/bin/cat", argv2, envp);
}

void	run_first_command(char *argv[], int fd[], char *envp[])
{
	int	filedes;

	filedes = open(argv[1], O_RDONLY, 0777);
	if (filedes == -1)
		exit (EXIT_FAILURE);
	dup2(fd[1], STDOUT_FILENO);
	dup2(filedes, STDIN_FILENO);
	close(fd[0]);
	close(filedes);
	char	*argv2[] = {"cat", NULL};
	execve("/bin/cat", argv2, envp);
}
