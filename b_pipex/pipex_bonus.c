/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:06:23 by hhamdy            #+#    #+#             */
/*   Updated: 2022/05/14 16:54:28 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

void	exe_child(int *fd, char *av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	path = check_acc(cmd[0], envp);
	dup2(fd[1], 1);
	close(fd[0]);
	close(fd[1]);
	if (execve(path, cmd, envp))
		raise_error("pipex: no such file or directory: ", cmd[0]);
	exit(0);
}

void	exe_pipe(int ac, char **av, char **envp, int *fd)
{
	int		i;
	pid_t	pid;

	i = 2;
	while (i < ac - 1)
	{
		if (pipe(fd) == -1)
			raise_error("Pipe failture.", "");
		pid = ft_fork();
		if (pid == 0)
		{
			if (i == 2)
				first_procces(fd, av, envp);
			else if (i == (ac - 2))
				last_procces(fd, av, ac, envp);
			exe_child(fd, av[i], envp);
		}
		dup2(fd[0], 0);
		close(fd[0]);
		close(fd[1]);
		i++;
	}
}

int	main(int ac, char **av, char **envp)
{
	int		fd[2];

	if (ac < 5)
		raise_error("Invalid arguments.", "");
	exe_pipe(ac, av, envp, fd);
	while (wait(NULL) != -1)
		;
}
