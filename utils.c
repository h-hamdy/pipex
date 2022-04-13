/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 09:48:16 by hhamdy            #+#    #+#             */
/*   Updated: 2022/04/12 14:30:20 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	raise_error(char *str)
{
	write (2, str, ft_strlen(str));
	exit (1);
}

char	*find_line(char **envp)
{
	int i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (&envp[i][5]);
		i++;
	}
	return (NULL);
}

void	ft_free(char **str)
{
	int i;

	i = 0;
	while (str[i])
	{
		free(str);
		str = 0;
		i++;
	}
}

char	*find_path(char *cmd, char **envp)
{
	int i;
	char *line;
	char *join;
	// char *tmp;
	char **paths;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	line = find_line(envp);
	paths = ft_split(line, ':');
	while (paths[i])
	{
		join = ft_strjoin(paths[i], "/");
		if (access(ft_strjoin(join, cmd), X_OK) == 0)
			return (ft_strjoin(join, cmd));
		i++;
	}
	ft_free(paths);
	return (NULL);
}