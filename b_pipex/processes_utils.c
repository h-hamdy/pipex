/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processes_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 16:55:55 by hhamdy            #+#    #+#             */
/*   Updated: 2022/05/14 15:33:49 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		raise_error("Error while trying to fork.", "");
	return (pid);
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

void	last_procces(int *fd, char **av, int ac, char **envp)
{
	int		outfile;
	char	**cmd;
	char	*path;

	outfile = open(av[ac - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		raise_error("Error while trying to open the outfile.", "");
	cmd = ft_split(av[ac - 2], ' ');
	path = check_acc(cmd[0], envp);
	dup2(outfile, 1);
	close(outfile);
	close(fd[0]);
	close(fd[1]);
	if (execve(path, cmd, envp))
		raise_error("pipex: no such file or directory: ", cmd[0]);
}
