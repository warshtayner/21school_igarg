/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 14:16:27 by igarg             #+#    #+#             */
/*   Updated: 2021/10/21 16:04:03 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

void	ft_put_0x(unsigned long long int n, int *count, char c)
{
	if (n >= 16)
	{
		ft_put_0x(n / 16, count, c);
		n %= 16;
	}
	if (n > 9 && n < 16)
	{
		if (c == 'x')
			ft_putchar_fd((n % 10) + 97, 1);
		else
			ft_putchar_fd((n % 10) + 65, 1);
	}
	else
		ft_putchar_fd(n + 48, 1);
	(*count)++;
}

void	put_x(int *count, va_list ap, char c)
{
	unsigned int	dig;

	dig = va_arg(ap, unsigned int);
	ft_put_0x(dig, count, c);
}
