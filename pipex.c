/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 05:07:07 by hhamdy            #+#    #+#             */
/*   Updated: 2022/04/12 13:42:12 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "pipex.h"

pid_t	ft_fork()
{
	pid_t pid;
	
	pid = fork();
	if (pid == -1)
		raise_error("Error while trying to fork.\n");
	return (pid);
}

void	first_procces(int *fd, char **av, char **envp)
{
	int 	infile;
	char	**cmd;
	char	*path;

	infile = open(av[1], O_RDONLY);
	if (infile == -1)
		raise_error("Error while trying to open the infile.\n");
	cmd = ft_split(av[2], ' ');
	path = find_path(cmd[0], envp);
	dup2(infile, 0);
	dup2(fd[1], 1);
	close(infile);
	close(fd[0]);
	close(fd[1]);
	execve(path, cmd, envp);
}

void	second_procces(int *fd, char **av, char **envp)
{
	int		outfile;
	char	**cmd;
	char	*path;

	cmd = ft_split(av[3], ' ');
	path = find_path(cmd[0], envp);
	outfile = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		raise_error("Error while trying to open the outfile.\n");
	dup2(outfile, 1);
	dup2(fd[0], 0);
	close(outfile);
	close(fd[0]);
	close(fd[1]);
	execve(path, cmd, envp);
		
}

int main(int ac, char **av, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (ac != 5)
		raise_error("Invalid arguments.\n");
	if (pipe(fd) == -1)
		raise_error("Pipe failture.\n");
	pid = ft_fork();
	if (pid == 0)
		first_procces(fd, av, envp);
	pid = ft_fork();
	if (pid == 0)
		second_procces(fd, av, envp);
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
	return (0);
}