/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 11:57:40 by hhamdy            #+#    #+#             */
/*   Updated: 2022/05/13 21:34:10 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	raise_error(char *cmd, char *str)
{
	char	*join;

	join = ft_strjoin(cmd, str);
	ft_putstr_fd(join, 2);
	write (2, "\n", 1);
	free(join);
	exit (0);
}

void	s_free(char *str)
{
	free(str);
	str = 0;
}

void	d_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = 0;
		i++;
	}
	free(str);
}

char	*find_path(char *cmd, char *line)
{
	int		i;
	char	*join;
	char	**paths;
	char	*str;

	i = 0;
	if (!line)
		raise_error("pipex: command not found: ", cmd);
	paths = ft_split(line, ':');
	while (paths[i++])
	{
		join = ft_strjoin(paths[i], "/");
		str = ft_strjoin(join, cmd);
		s_free(join);
		if (access(str, X_OK) == 0)
		{
			d_free(paths);
			return (str);
		}
		s_free(str);
	}
	d_free(paths);
	raise_error("pipex: command not found: ", cmd);
	return (NULL);
}

char	*find_line(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (&envp[i][5]);
		i++;
	}
	return (NULL);
}
