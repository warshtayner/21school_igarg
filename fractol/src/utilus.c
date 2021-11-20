/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilus.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/15 13:06:54 by igarg             #+#    #+#             */
/*   Updated: 2021/11/20 12:09:04 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"
#include "../includes/libft.h"

float	after_dot(char c, int dot)
{
	float	res;
	int		i;

	i = 0;
	res = c - 48;
	while (i++ < dot)
		res = res * 0.1;
	return (res);
}

float	my_atof(char *s)
{
	int		i;
	int		neg;
	int		dot;
	float	res;

	dot = 0;
	res = 0;
	neg = 1;
	i = 0;
	if (s[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (s[i] && ft_isdigit(s[i]))
		res = res * 10 + s[i++] - 48;
	if (s[i] && s[i++] == '.')
		dot++;
	while (s[i] && dot > 0 && ft_isdigit(s[i]))
	{
		res = res + after_dot(s[i], dot);
		dot++;
		i++;
	}
	return (res * neg);
}

void	set_arg(t_point *p, char **argv, int argc)
{
	if (argc == 3)
	{
		p->c_a = my_atof(argv[2]);
		p->c_b = 0.0;
	}
	else if (argc > 3)
	{
		p->c_a = my_atof(argv[2]);
		p->c_b = my_atof(argv[3]);
	}
}

void	set_param_pixel(t_pixel_cord *pixel_cord, int max_x, int max_y)
{
	pixel_cord->max_x = max_x;
	pixel_cord->max_y = max_y;
	pixel_cord->center_x = max_x / 2;
	pixel_cord->center_y = max_y / 2;
	pixel_cord->x = 1;
	pixel_cord->y = 1;
	pixel_cord->zoom = 500;
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
