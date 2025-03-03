/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emilgarc <emilgarc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/02 09:54:02 by gcollet           #+#    #+#             */
/*   Updated: 2025/02/10 19:14:19 by emilgarc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/* Child process that run inside a fork, take the filein, put the output inside
 a pipe and then close with the exec function */
void	child_process(char **argv, char **envp, int *fd)
{
	int		filein;

	filein = open(argv[1], O_RDONLY, 0777); //abrimos el primer archivo en formato lectura y con todos los permisos.
	if (filein == -1)
		error();
	dup2(fd[1], STDOUT_FILENO); //declaramos que la salida de la tubería es la salida estandar 1 (terminal)
	dup2(filein, STDIN_FILENO); //declaramos que la salida del archivo es el fd 0 es decir lo "metemos en la tuberia"
	close(fd[0]);// cerramos la entrada
	execute(argv[2], envp); //ejecutamos el programa que queramos ejecutar sobre e archivo que tenemos dentro
}

/* Parent process that take the data from the pipe, change the output for the
 fileout and also close with the exec function */
void	parent_process(char **argv, char **envp, int *fd)
{
	int		fileout; //creamos el file donde vamos a almacenar el resultado

	fileout = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777); //lo abrimos, el que hemos pasado por argumentos, si existe lo borramos, lo truncamos o lo creamos si esta vacio
	if (fileout == -1)
		error();
	dup2(fd[0], STDIN_FILENO); // decimos que la entrada de la tuberia es 0, la salida del anterior archivo, que trae los resultados del proceso sobre el que ejecutaremos el nuevo prceso
	dup2(fileout, STDOUT_FILENO); //y ahora le decimos que la salida por donde queremos que imprima el resultado es 1 para que nos lo escriba en fileout
	close(fd[1]); //cerramos la salida
	execute(argv[3], envp); //ejecutamos el programa que queramos ejecutar sobre e archivo (los resultados del anterior) que tenemos dentro
}

/* Main function that run the child and parent process or display an error
 message if arguments are wrong */
int	main(int argc, char **argv, char **envp) 
//por argumentos normales y **envp, que es una variable de entorno, que por defecto nos declara los comandos y cosas de shell que debemos usar
{
	int		fd[2]; // creamos la tuberia fd[2] por que tiene dos valores 0 de entrada y uno de salida. 
	pid_t	pid1; // numero de serie del proceso donde guardaremos el id proceso "hijo" (es decir el primero)

	if (argc == 5)
	{
		if (pipe(fd) == -1) // pipe crea en fd la tubería con entrada en cero y salida en uno, donde se almacenan los datos en un buffer hasta que sean sacados 
			error();
		pid1 = fork(); //crea el proceso hijo y guarda el id en pid1
		if (pid1 == -1)
			error();
		if (pid1 == 0)
			child_process(argv, envp, fd); // ejecutamos el proceso child primero.
		waitpid(pid1, NULL, 0); // esperamos a que el child se ejecute antes de ejecutar el segundo proceso, 
		parent_process(argv, envp, fd); //ejecutramos el segundo proceso 
	}
	else //gestion de error de argumentos.
	{
		ft_putstr_fd("\033[31mError: Bad arguments\n\e[0m", 2);
		ft_putstr_fd("Ex: ./pipex <file1> <cmd1> <cmd2> <file2>\n", 1);
	}
	return (0);
}
