/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:54:47 by emilgarc          #+#    #+#             */
/*   Updated: 2025/03/11 15:34:57 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *comands, char **envp)
{
	char	**paths;
	char	*path;
	int		i;
	char	*c_path;

	i = 0;
	i = ipath(envp);
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		c_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(c_path, comands);
		free(c_path);
		if (access (path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	freepath(paths);
	return (0);
}

int	ipath(char **envp)
{
	int	i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
	{
		i++;
		if (envp[i] == NULL)
			return (pathexit());
	}
	return (i);
}

void	execute(char *argv, char **envp)
{
	char	**comands;
	int		i;
	char	*path;

	i = -1;
	comands = ft_split(argv, ' ');
	path = find_path(comands[0], envp);
	if (!path)
	{
		while (comands[i])
		{
			free(comands[i]);
			i++;
		}
		free(comands);
		ft_error();
	}
	if (execve (path, comands, envp) == -1)
		ft_error();
}
