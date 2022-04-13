/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hhamdy <hhamdy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 05:07:02 by hhamdy            #+#    #+#             */
/*   Updated: 2022/04/12 14:30:05 by hhamdy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>

# include "libft/libft.h"

void	raise_error(char *str);
char	*find_path(char *str, char **envp);
void	ft_free(char **str);

#endif