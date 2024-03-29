/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 13:30:28 by                   #+#    #+#             */
/*   Updated: 2021/10/08 17:21:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memset(void *arr, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		*(char *)(arr + i) = c;
		i++;
	}
	return (arr);
}
