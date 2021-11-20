/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:33:47 by igarg             #+#    #+#             */
/*   Updated: 2021/11/20 12:28:36 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"
#include "../includes/mlx.h"
#include <math.h>

void	iter_xy(t_tmp *tmp)
{
	tmp->x_tmp = tmp->x * tmp->x - tmp->y * tmp->y + tmp->x_0;
	tmp->y_tmp = 2 * tmp->x * tmp->y + tmp->y_0;
	tmp->x = tmp->x_tmp;
	tmp->y = tmp->y_tmp;
	tmp->z = tmp->x * tmp->x + tmp->y * tmp->y;
}

void	set_tmp_m(t_point *p, t_tmp *tmp)
{
	tmp->x_0 = (p->cord->x - p->cord->center_x) / p->cord->zoom;
	tmp->y_0 = (p->cord->y - p->cord->center_y) / p->cord->zoom;
	tmp->x = tmp->x_0;
	tmp->y = tmp->y_0;
	tmp->z = tmp->x * tmp->x + tmp->y * tmp->y;
	tmp->p = sqrt((tmp->x - 0.25) * (tmp->x - 0.25) + tmp->y * tmp->y);
	tmp->pc = 0.5 - (cos(atan2(tmp->y, tmp->x - 0.25)) / 2);
	tmp->i = 0;
	tmp->iter = 35;
}

void	iter_mandelbrot(t_point *p)
{
	t_tmp	tmp;

	set_tmp_m(p, &tmp);
	if (tmp.p <= tmp.pc)
		my_mlx_pixel_put(p->img, p->cord->x, p->cord->y,
			set_color_center(p->img));
	else
	{
		while (tmp.i < tmp.iter && tmp.z < 4)
		{
			iter_xy(&tmp);
			tmp.i++;
		}
		if (tmp.i == tmp.iter)
			my_mlx_pixel_put(p->img, p->cord->x, p->cord->y,
				set_color_center(p->img));
		else
			my_mlx_pixel_put(p->img, p->cord->x, p->cord->y,
				set_color(p->img, &tmp));
	}
}

void	mandelbrot_img(t_point *p, int cor_x, int cor_y, float cor_z)
{
	if (cor_z != 0)
		p->cord->zoom *= cor_z;
	p->cord->center_x += cor_x;
	p->cord->center_y += cor_y;
	p->cord->x = 0;
	while (p->cord->x < p->cord->max_x)
	{
		p->cord->y = 0;
		while (p->cord->y < p->cord->max_y)
		{
			iter_mandelbrot(p);
			p->cord->y++;
		}
		p->cord->x++;
	}
	mlx_put_image_to_window(p->mlx->mlx, p->mlx->win, p->img->img, 0, 0);
}
