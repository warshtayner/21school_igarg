/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/30 12:51:25 by igarg             #+#    #+#             */
/*   Updated: 2021/11/01 12:01:27 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "../push_swap.h"
#include <stdio.h> // <-----------------------(( ! ))
//printf("----------> debug ret = %s\n", str[i]);

void	error(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(0);
}

void	leaks(char **res)
{
	int	i;

	i = 0;
	while (res[i])
		free(res[i++]);
	free(res);
}

void	check_equal(char **str, int count_arg)
{
	int	i;
	int	k;

	i = -1;
	while (++i < count_arg)
	{
		k = 1;
		while ((i + k) < count_arg)
		{
			if (ft_strncmp(str[i], str[i + k], 10))
				k++;
			else
				error();
		}
	}
}
