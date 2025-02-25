/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:54:47 by emilgarc          #+#    #+#             */
/*   Updated: 2025/02/25 14:48:08 by emilgarc         ###   ########.fr       */
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
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
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
	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
	return (0);
}

void	error(void)
{
	perror("ERRORR");
	exit(EXIT_FAILURE);
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
		error();
	}
	if (execve (path, comands, envp) == -1)
		error();
}

int	envpexit(void)
{
	ft_putstr_fd("Error: Can't find environment variables\n", 2);
	return (0);
}
