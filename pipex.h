/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daspring <daspring@student.42heilbronn.de  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 13:48:35 by daspring          #+#    #+#             */
/*   Updated: 2024/07/31 13:55:10 by daspring         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

void	execute_command(char *arg, char **envp);
char	*find_working_path(char *cmd_name, char *envp[]);
void	free_mem(char **cmd_string, char *path, char **paths);

#endif
