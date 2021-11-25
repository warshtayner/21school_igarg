/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:26:58 by                   #+#    #+#             */
/*   Updated: 2021/10/11 11:55:24 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

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
