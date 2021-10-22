/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 09:05:54 by igarg             #+#    #+#             */
/*   Updated: 2021/10/21 16:16:57 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../ft_printf.h"

void	put_p(int *count, va_list ap)
{
	unsigned long long int	p;

	p = va_arg(ap, unsigned long long int);
	ft_putchar_fd('0', 1);
	ft_putchar_fd('x', 1);
	*count += 2;
	ft_put_0x(p, count, 'x');
}
