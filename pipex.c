/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:11:57 by daspring          #+#    #+#             */
/*   Updated: 2024/07/30 18:40:48 by daspring         ###   ########.fr       */
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
		// int filedes = open("./input_file", O_RDONLY);
		dup2(fd[1], STDOUT_FILENO);
		// dup2(filedes, STDIN_FILENO);
		// run_first_command(argv, fd, envp);

		execve("./helloWorld", NULL, envp);
	}
	else
	{
		wait(NULL);
		int filedes = open("./output_file", O_WRONLY | O_CREAT | O_TRUNC, 0777);
		dup2(filedes, STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);
		close(fd[1]);
		close(filedes);
		// run_second_command(argv, fd, envp);
		// execve("./helloWorld", NULL, envp);
		char	*argv2[] = {"cat", NULL};
		execv("/bin/cat", argv2);
	}
	return (EXIT_SUCCESS);
}

void	run_second_command(char *argv[], int fd[], char *envp[])
{
	int	filedes;

	filedes = open("./output_file", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (filedes == -1)
		exit(EXIT_FAILURE);
	dup2(filedes, STDOUT_FILENO);
	// dup2(fd[0], STDIN_FILENO);
	// close(fd[1]);
	// close(filedes);
	// execve("/bin/cat", NULL, envp);
	execve("./helloWorld", NULL, envp);
}

void	run_first_command(char *argv[], int fd[], char *envp[])
{
	int	filedes;

	filedes = open("./input_file", O_RDONLY);
	if (filedes == -1)
		exit (EXIT_FAILURE);
	dup2(fd[1], STDOUT_FILENO);
	dup2(filedes, STDIN_FILENO);
	close(fd[0]);
	close(filedes);
	execve("/bin/cat", NULL, envp);
}
