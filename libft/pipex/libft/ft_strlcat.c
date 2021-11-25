/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  <>                                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 10:11:21 by                   #+#    #+#             */
/*   Updated: 2021/10/08 17:21:09 by                  ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	len_dst;
	size_t	i;

	len_dst = 0;
	i = 0;
	while (dst[len_dst])
		len_dst++;
	if (len_dst < dstsize - 1 && dstsize > 0)
	{
		while (src[i] && len_dst + i < dstsize - 1)
		{
			dst[len_dst + i] = src[i];
			i++;
		}
		dst[len_dst + i] = '\0';
	}
	while (src[i])
		i++;
	if (len_dst > dstsize)
		len_dst = dstsize;
	return (len_dst + i);
}
