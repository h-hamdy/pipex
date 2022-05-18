/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 05:07:07 by hhamdy            #+#    #+#             */
/*   Updated: 2022/05/09 16:56:18 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	s_free(char *str)
{
	free(str);
	str = 0;
}

pid_t	ft_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		raise_error("Error while trying to fork.", "");
	return (pid);
}

int	main(int ac, char **av, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (ac != 5)
		raise_error("Invalid arguments.", "");
	if (pipe(fd) == -1)
		raise_error("Pipe failture.", "");
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
