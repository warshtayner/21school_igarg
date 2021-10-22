/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_str.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 19:18:00 by igarg             #+#    #+#             */
/*   Updated: 2021/10/21 18:46:56 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

void	put_str(int *count, va_list ap)
{
	char	*s;
	int		len;

	len = 0;
	s = va_arg(ap, char *);
	if (!s)
		s = "(null)\0";
	while (s[len])
		len++;
	write(1, s, len);
	*count += len;
}
