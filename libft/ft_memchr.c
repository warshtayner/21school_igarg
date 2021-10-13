/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 16:22:43 by                   #+#    #+#             */
/*   Updated: 2021/10/12 11:01:48 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*ss;

	if (n == 0)
		return (NULL);
	i = 0;
	ss = (unsigned char *)s;
	while (i < n && ss)
	{
		if (ss[i] == (unsigned char)c)
			return (&ss[i]);
		i++;
	}
	if (c == '\0' && *ss == '\0')
		return (ss);
	return (NULL);
}
