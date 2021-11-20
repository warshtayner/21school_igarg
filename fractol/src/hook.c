/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 17:37:52 by igarg             #+#    #+#             */
/*   Updated: 2021/11/20 12:06:08 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

int	key_hook(int keycode, t_point *p)
{
	if (keycode == 53)
		exit(0);
	else if (keycode == 123)
		pain_f(p, -15, 0, 0);
	else if (keycode == 124)
		pain_f(p, 15, 0, 0);
	else if (keycode == 125)
		pain_f(p, 0, 15, 0);
	else if (keycode == 126)
		pain_f(p, 0, -15, 0);
	else if (keycode == 49)
	{
		p->img->cod_color++;
		if (p->img->cod_color == 20)
			p->img->cod_color = 0;
		pain_f(p, 0, 0, 0);
	}
	else if (keycode == 257)
	{
		p->img->cod_color--;
		if (p->img->cod_color == -1)
			p->img->cod_color = 19;
		pain_f(p, 0, 0, 0);
	}
	return (0);
}

int	mouse_hook(int mouse, int x, int y, t_point *p)
{
	if (mouse == 1 && p->fractal == 2)
	{
		p->c_a = ((float )x - p->cord->center_x) / (p->cord->zoom);
		p->c_b = ((float )y - p->cord->center_y) / (p->cord->zoom);
		pain_f(p, 0, 0, 0);
	}
	else if (mouse == 4)
	{
		pain_f(p, ((float )x - p->cord->center_x)
			- ((float )x - p->cord->center_x) * 1.1,
			((float )y - p->cord->center_y)
			- ((float )y - p->cord->center_y) * 1.1, 1.1);
	}
	else if (mouse == 5)
	{
		pain_f(p, ((float )x - p->cord->center_x)
			- ((float )x - p->cord->center_x) * 0.9,
			((float )y - p->cord->center_y)
			- ((float )y - p->cord->center_y) * 0.9, 0.9);
	}
	return (0);
}
