/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   full_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:32:07 by igarg             #+#    #+#             */
/*   Updated: 2021/11/05 15:11:32 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"
#include "../push_swap.h"

static int	*sorting_arr_int(int *arr, int count)
{
	int	tmp;
	int	i;
	int	k;

	i = -1;
	while (++i < count)
	{
		k = 1;
		while ((i + k) < count)
		{
			if (arr[i] > arr[i + k])
			{
				tmp = arr[i];
				arr[i] = arr[i + k];
				arr[i + k] = tmp;
			}
			k++;
		}
	}
	return (arr);
}

int	*full_int(char **str, int count)
{
	int	*ret;
	int	i;

	ret = malloc(sizeof(int) * count + 1);
	if (!ret)
		return (0);
	i = 0;
	while (i < count)
	{
		ret[i] = atoi_swap(str[i]);
		i++;
	}
	ret[i] = '\0';
	ret = sorting_arr_int(ret, count);
	return (ret);
}
