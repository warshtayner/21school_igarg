/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:16:44 by igarg             #+#    #+#             */
/*   Updated: 2021/10/21 17:00:05 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

void	process_ap(const char *str, int *count, va_list ap)
{
	if (*str == 'c')
		put_char(count, ap);
	else if (*str == 's')
		put_str(count, ap);
	else if (*str == 'p')
		put_p(count, ap);
	else if (*str == 'd' || *str == 'i')
		put_int(count, ap);
	else if (*str == 'u')
		put_uns(count, ap);
	else if (*str == 'x' || *str == 'X')
		put_x(count, ap, *str);
	else if (*str == '%')
	{
		write(1, "%", 1);
		(*count)++;
	}
	else
	{
		write(1, str, 1);
		(*count)++;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		count;

	va_start(ap, str);
	count = 0;
	while (*str)
	{
		if (*str == '%')
		{
			process_ap(++str, &count, ap);
			str++;
		}
		else
		{
			write(1, str++, 1);
			count++;
		}
	}
	va_end(ap);
	return (count);
}
