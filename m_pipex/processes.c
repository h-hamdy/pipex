/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:55:55 by hhamdy            #+#    #+#             */
/*   Updated: 2022/05/14 03:58:34 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*check_acc(char *cmd, char **envp)
{
	char	*path;
	char	*line;

	line = find_line(envp);
	if (access(cmd, X_OK) == 0)
		path = cmd;
	else if (ft_strchr(cmd, '/'))
		path = cmd;
	else
		path = find_path(cmd, line);
	return (path);
}

void	first_procces(int *fd, char **av, char **envp)
{
	int		infile;
	char	**cmd;
	char	*path;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		raise_error("pipex: no such file or directory: ", av[1]);
	cmd = ft_split(av[2], ' ');
	path = check_acc(cmd[0], envp);
	dup2(infile, 0);
	dup2(fd[1], 1);
	close(infile);
	close(fd[0]);
	close(fd[1]);
	if (execve(path, cmd, envp))
		raise_error("pipex: no such file or directory: ", cmd[0]);
}

void	second_procces(int *fd, char **av, char **envp)
{
	int		outfile;
	char	**cmd;
	char	*path;

	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		raise_error("Error while trying to open the outfile.", "");
	cmd = ft_split(av[3], ' ');
	path = check_acc(cmd[0], envp);
	dup2(outfile, 1);
	dup2(fd[0], 0);
	close(outfile);
	close(fd[0]);
	close(fd[1]);
	if (execve(path, cmd, envp))
		raise_error("pipex: no such file or directory: ", cmd[0]);
}
