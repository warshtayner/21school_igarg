/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 15:15:59 by igarg             #+#    #+#             */
/*   Updated: 2021/11/24 18:23:22 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>
#include "pipex.h"
#include "./libft/libft.h"

void	err_cmd(char *cmd)
{
	write(STDERR, "pipex: command not found: ", 26);
	ft_putstr_fd(cmd, 2);
	write(STDERR, "\n", 1);
	exit(1);
}

char	*parsing_path(char **env, char *cmd)
{
	char	**paths;
	char	*path;
	char	*tmp;
	int		i;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	paths = ft_split(env[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		path = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	if (!paths[i])
		err_cmd(cmd);
	return (0);
}

int	str_i_chr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

void	start_exe(char *argv, char **env)
{
	char	*cmd;
	char	*path;

	cmd = ft_substr(argv, 0, str_i_chr(argv, ' '));
	path = parsing_path(env, cmd);
	execve(path, ft_split(argv, ' '), env);
	free(path);
	exit(127);
}
