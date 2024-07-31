/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:53:13 by daspring          #+#    #+#             */
/*   Updated: 2024/07/31 13:55:48 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
// #include <fcntl.h>
// #include <sys/wait.h>
// #include <sys/fcntl.h>

#include "libft/libft.h"
#include "pipex.h"

void	execute_command(char *arg, char **envp)
{
	char	**cmd_string;
	char	*path_to_bin;

	cmd_string = ft_split(arg, ' ');
	if (cmd_string == NULL)
	{
		perror("path to bin could not be extracted");
		exit(EXIT_FAILURE);
	}
	path_to_bin = find_working_path(cmd_string[0], envp);
	if (path_to_bin == NULL)
	{
		perror("path to bin could not be extracted");
		exit(EXIT_FAILURE);
	}
	if (execve(path_to_bin, cmd_string, envp) == -1)
	{
		free_mem(cmd_string, path_to_bin, NULL);
		perror("First given command does not exist");
		exit(EXIT_FAILURE);
	}
}

char	*find_working_path(char *cmd_name, char *envp[])
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
			return (free_mem(NULL, NULL, all_paths), path_to_bin);
		free(path_to_bin);
		i++;
	}
	return (free_mem(NULL, NULL, all_paths), NULL);
}

void	free_mem(char **cmd_string, char *path, char **paths)
{
	int	i;

	i = 0;
	if (cmd_string != NULL)
	{
		while (cmd_string[i] != NULL)
			free(cmd_string[i++]);
		free(cmd_string);
	}
	if (path != NULL)
		free(path);
	if (paths != NULL)
	{
		while (paths[i] != NULL)
			free(paths[i++]);
		free(paths);
	}
}
