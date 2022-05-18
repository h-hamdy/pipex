/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 11:10:51 by hhamdy            #+#    #+#             */
/*   Updated: 2022/05/10 10:13:46 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <err.h>
# include <fcntl.h>

# include "../libft/libft.h"

/****************FREE*********************/
void	d_free(char **str);
void	s_free(char *str);

/****************PIPE*********************/
void	first_procces(int *fd, char **av, char **envp);
void	second_procces(int *fd, char **av, char **envp);

/**************ERROR_HANDLIING************/
void	raise_error(char *cmd, char *str);

/****************UTILS*******************/
char	*find_path(char *str, char *line);
char	*check_acc(char *cmd, char **envp);
char	*find_line(char **envp);

#endif