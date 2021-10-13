/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:40:03 by                   #+#    #+#             */
/*   Updated: 2021/10/12 12:41:01 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	i;
	size_t	j;

	if (!s)
		return (0);
	i = ft_strlen(s);
	if (i < len)
		len = i;
	res = malloc(len + 1);
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (i >= start && j < len)
		{
			res[j] = s[i];
			j++;
		}
		i++;
	}
	res[j] = '\0';
	return (res);
}
