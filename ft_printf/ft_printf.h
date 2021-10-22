/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 09:19:30 by igarg             #+#    #+#             */
/*   Updated: 2021/10/21 16:15:13 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);

void	ft_put_0x(unsigned long long int n, int *count, char c);
void	put_x(int *count, va_list ap, char c);
void	put_char(int *count, va_list ap);
void	put_str(int *count, va_list ap);
void	put_int(int *count, va_list ap);
void	put_uns(int *count, va_list ap);
void	ft_putchar_fd(char c, int fd);
void	put_p(int *count, va_list ap);

#endif