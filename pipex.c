/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:11:57 by daspring          #+#    #+#             */
/*   Updated: 2024/07/30 21:54:55 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/fcntl.h>

#include "libft/libft.h"

void	run_last_command(char *argv[], int fd[], char *envp[]);
void	run_first_command(char *argv[], int fd[], char *envp[]);

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		ft_printf("Wrong format used.\n");
		ft_printf("Try: ./pipex infile \"ls -l\" \"wc -l\" outfile\n");
		return (EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
	{
		perror("Error opening pipe");
		return (EXIT_FAILURE);
	}
	pid = fork();
	if (pid == 0)
	{
		run_first_command(argv, fd, envp);
	}
	else
	{
		run_last_command(argv, fd, envp);
	}
	return (EXIT_SUCCESS);
}

void	run_first_command(char *argv[], int fd[], char *envp[])
{
	int		filedes;
	char	**cmd_string;

	filedes = open(argv[1], O_RDONLY, 0777);
	if (filedes == -1)
	{
		perror("Failure to open input file");
		exit (EXIT_FAILURE);
	}
	dup2(fd[1], STDOUT_FILENO);
	dup2(filedes, STDIN_FILENO);
	close(fd[0]);
	close(filedes);
	cmd_string = ft_split(argv[2], ' ');
	if (execve("/bin/cat", cmd_string, envp) == -1)
	{
		perror("First given command does not exist");
		exit(EXIT_FAILURE);
	}
	write(2, "something went wrong with the first command\n", 44);
}

void	run_last_command(char *argv[], int fd[], char *envp[])
{
	int		filedes;
	char	**cmd_string;

	filedes = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (filedes == -1)
	{
		perror("Failure to open output file");
		exit(EXIT_FAILURE);
	}
	dup2(filedes, STDOUT_FILENO);
	dup2(fd[0], STDIN_FILENO);
	close(fd[1]);
	close(filedes);
	cmd_string = ft_split(argv[3], ' ');
	if (execve("/bin/cat", cmd_string, envp) == -1)
	{
		perror("Last given command does not exist");
		exit(EXIT_FAILURE);
	}
	write(2, "something went wrong with the second command\n", 45);
}
