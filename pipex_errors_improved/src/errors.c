/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 15:32:37 by emilgarc          #+#    #+#             */
/*   Updated: 2025/03/11 15:36:03 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	envpexit(void)
{
	ft_putstr_fd("ERROR: Can't find environment variables\n", 2);
	return (0);
}

int	pathexit(void)
{
	ft_putstr_fd("ERROR: Can't find PATH= routes\n", 2);
	exit(EXIT_FAILURE);
	return (0);
}

void	ft_error(void)
{
	perror("ERROR");
	exit(EXIT_FAILURE);
}

void	freepath(char	**paths)
{
	int	i;

	i = -1;
	while (paths[++i])
		free(paths[i]);
	free(paths);
}
