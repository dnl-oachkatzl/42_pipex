/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:11:57 by daspring          #+#    #+#             */
/*   Updated: 2024/07/30 15:47:50 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

void	run_first_command(char *envp[]);

int	main(int argc, char *argv[], char *envp[])
{
	// int		fd[2];
	pid_t	pid;

	pid = fork();
	if (pid == 0)
		run_first_command(envp);
	else
	{
		wait(NULL);
		write(1, "back to parent\n", 15);
	}
	return (EXIT_SUCCESS);
}

void	run_first_command(char *envp[])
{
	int filedes = open("./output_file", O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (filedes == -1)
		exit(EXIT_FAILURE);
	dup2(filedes, STDOUT_FILENO);
	close(filedes);
	execve("/Users/daspring/c-programming/my_projects/git_home/pipex/helloWorld", NULL, envp);
}
