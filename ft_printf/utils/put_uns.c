/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_uns.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 13:21:01 by igarg             #+#    #+#             */
/*   Updated: 2021/10/21 15:16:37 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

void	ft_putnbru_fd(unsigned int n, int fd, int *count)
{
	if (n >= 10)
	{
		ft_putnbru_fd(n / 10, fd, count);
		n %= 10;
	}
	if (n < 10)
	{
		ft_putchar_fd(n + 48, fd);
		(*count)++;
	}
}

void	put_uns(int *count, va_list ap)
{
	unsigned int	u_dig;

	u_dig = va_arg(ap, unsigned int);
	ft_putnbru_fd(u_dig, 1, count);
}
