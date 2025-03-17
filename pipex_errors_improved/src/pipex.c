/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 13:20:44 by emilgarc          #+#    #+#             */
/*   Updated: 2025/03/13 12:03:09 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child(char **argv, char **envp, int *fd)
{
	int	filein;

	filein = open(argv[1], O_RDONLY, 0777);
	if (filein == -1)
		ft_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	execute (argv[2], envp);
}

void	parent(char **argv, char **envp, int *fd)
{
	int	fileout;
	
	if (access(argv[1], F_OK) == -1)
		exit(EXIT_FAILURE);
	fileout = open (argv[4], O_RDONLY | O_WRONLY | O_TRUNC | O_CREAT, 0777);
	if (fileout == -1)
		ft_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	execute (argv[3], envp);
}

int	main(int argc, char **argv, char **envp)
{
	int		fd[2];
	pid_t	pid1;

	if (!envp[0])
		return (envpexit());
	if (argc == 5)
	{
		if (pipe (fd) == -1)
			ft_error();
		pid1 = fork();
		if (pid1 == -1)
			ft_error();
		if (pid1 == 0)
			child(argv, envp, fd);
		waitpid(pid1, NULL, 0);
		parent(argv, envp, fd);
	}
	else
	{
		ft_putstr_fd("Error: Bad arguments\n", 2);
		ft_error();
	}
	return (0);
}
