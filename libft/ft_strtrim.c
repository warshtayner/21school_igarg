/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 11:07:00 by                   #+#    #+#             */
/*   Updated: 2021/10/09 13:41:23 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
удаляет символы с начала и конца строки
*/

#include "libft.h"

int	exist(char const where, char const *what)
{
	int	i;

	i = 0;
	while (what[i])
	{
		if (where == what[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		end;
	int		start;
	int		i;

	if (!s1)
		return (NULL);
	start = 0;
	while (exist(s1[start], set))
		start++;
	end = ft_strlen(s1) - 1;
	while (start <= end && exist(s1[end], set))
		end--;
	res = malloc(sizeof(*res) * (end - start + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (start <= end)
	{
		res[i] = s1[start];
		start++;
		i++;
	}
	res[i] = '\0';
	return (res);
}
