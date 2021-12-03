/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 14:02:05 by igarg             #+#    #+#             */
/*   Updated: 2021/11/26 14:02:05 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "philo_bonus.h"

int	ft_atoi(const char *str)
{
	int			i;
	int			is_neg;
	long int	res;

	i = 0;
	res = 0;
	is_neg = 1;
	while ((str[i] > 8 && str[i] < 14) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + is_neg * (str[i] - 48);
		i++;
		if (is_neg == 1 && res < 0 && i > 18)
			return (-1);
		if (is_neg == -1 && res > 0 && i > 19)
			return (0);
	}
	return (res);
}
