/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 11:57:59 by igarg             #+#    #+#             */
/*   Updated: 2021/11/24 14:43:37 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <sys/types.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>

# define STDIN 0
# define STDOUT 1
# define STDERR 2

# define OPEN_RID 1
# define OPEN_WR 0

int		str_i_chr(char *str, char c);
char	*parsing_path(char **env, char *cmd);
void	start_exe(char *argv, char **env);

#endif