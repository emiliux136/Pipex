/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:42:04 by emilgarc          #+#    #+#             */
/*   Updated: 2025/03/11 15:27:34 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "../libft/libft.h"

void	child(char **argv, char **envp, int *fd);
void	parent(char **argv, char **envp, int *fd);
int		main(int argc, char **argv, char **envp);
void	execute(char *argv, char **envp);
void	ft_error(void);
char	*find_path(char *comands, char **envp);
int		envpexit(void);
void	freepath(char	**paths);
int		pathexit(void);
int		ipath(char **envp);

#endif