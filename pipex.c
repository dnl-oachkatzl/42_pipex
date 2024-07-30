/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 14:11:57 by daspring          #+#    #+#             */
/*   Updated: 2024/07/31 00:03:53 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <sys/fcntl.h>

#include "libft/libft.h"

static void	run_last_command(char *argv[], int fd[], char *envp[]);
static void	run_first_command(char *argv[], int fd[], char *envp[]);
static char	*find_working_path(char *cmd_name, char *envp[]);

int	main(int argc, char *argv[], char *envp[])
{
	int		fd[2];
	pid_t	pid;

	// int	i = 0;
	// while(envp[i] != NULL)
	// {
	// 	printf("line %d of envp: %s\n", i, envp[i]);
	// 	printf("strnstr searches for PATH: %s\n", ft_strnstr(envp[i], "PATH", 4));
	// 	if (ft_strnstr(envp[i], "PATH", 4) != NULL)
	// 		printf("found it!\n");
	// 	i++;
	// }

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

static void	run_first_command(char *argv[], int fd[], char *envp[])
{
	int		filedes;
	char	**cmd_string;
	char	*path_to_bin;

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
	path_to_bin = find_working_path(cmd_string[0], envp);
	if (execve(path_to_bin, cmd_string, envp) == -1)
	{
		perror("First given command does not exist");
		exit(EXIT_FAILURE);
	}
}

static void	run_last_command(char *argv[], int fd[], char *envp[])
{
	int		filedes;
	char	**cmd_string;
	char	*path_to_bin;

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
	path_to_bin = find_working_path(cmd_string[0], envp);
	// if (execve(path_to_bin, cmd_string, envp) == -1)
	if (execve(NULL, cmd_string, envp) == -1)
	{
		perror("Last given command does not exist");
		exit(EXIT_FAILURE);
	}
}

static char	*find_working_path(char *cmd_name, char *envp[])
{
	int		i;
	char	**all_paths;
	char	*path_to_bin_folder;
	char	*path_to_bin;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strnstr(envp[i], "PATH", 4) != NULL)
			break ;
		i++;
	}
	all_paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (all_paths[i] != NULL)
	{
		path_to_bin_folder = ft_strjoin(all_paths[i], "/");
		path_to_bin = ft_strjoin(path_to_bin_folder, cmd_name);
		free(path_to_bin_folder);
		if (access(path_to_bin, X_OK) == 0)
			return (path_to_bin);
		free(path_to_bin);
		i++;
	}
	return NULL;
}
