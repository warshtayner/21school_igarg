/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 15:35:31 by igarg             #+#    #+#             */
/*   Updated: 2021/11/24 18:17:28 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdio.h>
#include "pipex.h"
#include "./libft/libft.h"

int	file_open(char *file_name, int flag)
{
	if (flag == OPEN_RID)
	{
		if (access(file_name, F_OK))
		{
			write(STDERR, "pipex: No such file or directory: ", 35);
			ft_putstr_fd(file_name, 2);
			write(STDERR, "\n", 1);
			exit(1);
		}
		if (access(file_name, R_OK))
		{
			write(STDERR, "pipex: permission denied: ", 26);
			ft_putstr_fd(file_name, 2);
			write(STDERR, "\n", 1);
			exit(1);
		}
		return (open(file_name, O_RDONLY, 0));
	}
	else
		return (open(file_name, O_CREAT + O_WRONLY + O_TRUNC, 0777));
}

void	exe_cmd(char **argv, char **env, pid_t pid)
{
	if (pid)
		start_exe(argv[3], env);
	else
		start_exe(argv[2], env);
}

pid_t	tube(void)
{
	int		pipe_fd[2];
	pid_t	pid;

	pipe(pipe_fd);
	pid = fork();
	if (pid)
	{
		close(pipe_fd[1]);
		dup2(pipe_fd[0], STDIN);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipe_fd[0]);
		dup2(pipe_fd[1], STDOUT);
	}
	return (pid);
}

int	main(int argc, char **argv, char **env)
{
	int		fd_rid;
	int		fd_wr;
	pid_t	pid;

	if (argc == 5)
	{
		fd_rid = file_open(argv[1], OPEN_RID);
		fd_wr = file_open(argv[4], OPEN_WR);
		dup2(fd_rid, STDIN);
		dup2(fd_wr, STDOUT);
		pid = tube();
		exe_cmd(argv, env, pid);
	}
	else
		exit(1);
	return (0);
}
