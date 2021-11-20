/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 13:22:52 by igarg             #+#    #+#             */
/*   Updated: 2021/11/18 15:13:58 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"

int	create_trgb(int t, int r, int g, int b)
{
	while (r > 255 && g > 255 && b > 255)
	{
		if (r > 255)
			r = r - 255;
		else if (g > 255)
			g = g - 255;
		else if (b > 255)
			b = b - 255;
	}
	return (t << 24 | r << 16 | g << 8 | b);
}

int	set_color(t_img *img, t_tmp *tmp)
{
	if (img->cod_color == 0 || img->cod_color == 10)
		return (create_trgb(0, tmp->i * 2, tmp->i * 3, tmp->i * 5));
	else if (img->cod_color == 1 || img->cod_color == 11)
		return (create_trgb(0, tmp->i * 3, tmp->i * 5, tmp->i * 2));
	else if (img->cod_color == 2 || img->cod_color == 12)
		return (create_trgb(0, tmp->i * 5, tmp->i * 2, tmp->i * 3));
	else if (img->cod_color == 3 || img->cod_color == 13)
		return (create_trgb(0, tmp->i * 5, tmp->i * 2, tmp->i * 5));
	else if (img->cod_color == 4 || img->cod_color == 14)
		return (create_trgb(0, tmp->i * 5, tmp->i * 5, tmp->i * 2));
	else if (img->cod_color == 5 || img->cod_color == 15)
		return (create_trgb(0, tmp->i * 2, tmp->i * 5, tmp->i * 5));
	else if (img->cod_color == 6 || img->cod_color == 16)
		return (create_trgb(0, tmp->i * 5, tmp->i * 8, tmp->i * 13));
	else if (img->cod_color == 7 || img->cod_color == 17)
		return (create_trgb(0, tmp->i * 8, tmp->i * 13, tmp->i * 5));
	else if (img->cod_color == 8 || img->cod_color == 18)
		return (create_trgb(0, tmp->i * 13, tmp->i * 5, tmp->i * 8));
	else if (img->cod_color == 9 || img->cod_color == 19)
		return (create_trgb(0, tmp->i * 89, tmp->i * 144, tmp->i * 233));
	else
		return (0);
}

int	set_color_center(t_img *img)
{
	if (img->cod_color >= 0 && img->cod_color < 10)
		return (create_trgb(0, 255, 255, 255));
	else
		return (create_trgb(0, 0, 0, 0));
}
