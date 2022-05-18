/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 10:06:58 by hhamdy            #+#    #+#             */
/*   Updated: 2022/05/14 16:53:20 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdio.h>
# include <fcntl.h>

# include "../libft/libft.h"

/***************FREE_MEMORY**************/
void	s_free(char *str);
void	d_free(char **str);

/***************ERROR_HANDLING***************/
void	raise_error(char *cmd, char *str);

/*************procces********************/
void	last_procces(int *fd, char **av, int ac, char **envp);
void	first_procces(int *fd, char **av, char **envp);

pid_t	ft_fork(void);
char	*find_path(char *cmd, char *line);
char	*find_line(char **envp);
char	*check_acc(char *cmd, char **envp);

#endif
