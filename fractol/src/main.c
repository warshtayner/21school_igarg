/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:15:49 by igarg             #+#    #+#             */
/*   Updated: 2021/11/20 12:33:59 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/fractol.h"
#include "../includes/mlx.h"
#include <stdio.h>
#include <stdlib.h>

void	error(void)
{
	printf("\n\t*************************\n"
		"\t*--- Argument  ERROR ---*\n"
		"\t*************************");
	printf("\n\t* To start the program  *\n"
		"\t*    Enter the format   *\n"
		"\t*************************\n\n"
		"\t./fraktol [fractal number] *[a] *[b]\n"
		"\n\t[fractal number] - use:\n"
		"\t [1] - Mandelbrot Fractal\n"
		"\t [2] - Julia Fractal\n"
		"\t [3] - Burning Ship Fractal\n\n"
		"\t*[.] - unnecessary argument\n");
	exit(0);
}

void	pain_f(t_point *p, int cor_x, int cor_y, float cor_z)
{
	if (p->fractal == 1)
		mandelbrot_img(p, cor_x, cor_y, cor_z);
	if (p->fractal == 2)
		julia_img(p, cor_x, cor_y, cor_z);
	if (p->fractal == 3)
		burning_ship_img(p, cor_x, cor_y, cor_z);
}

void	input_argv(t_point *p, char **argv, int argc)
{
	if (argv[1][0] == '1')
		p->fractal = 1;
	else if (argv[1][0] == '2')
	{
		p->fractal = 2;
		if (argc > 2)
			set_arg(p, argv, argc);
		else
		{
			p->c_a = -0.7;
			p->c_b = 0.5;
		}
	}
	else if (argv[1][0] == '3')
		p->fractal = 3;
	else
		error();
	pain_f(p, 0, 0, 0);
	mlx_key_hook(p->mlx->win, key_hook, p);
	mlx_hook(p->mlx->win, 4, 1L << 3, mouse_hook, p);
	mlx_hook(p->mlx->win, 5, 1L << 4, mouse_hook, p);
	mlx_loop(p->mlx->mlx);
}

int	main(int argc, char **argv)
{
	t_img			img;
	t_mlx			mlx;
	t_pixel_cord	cord;
	t_point			point;

	if (argc > 1)
	{
		point.img = &img;
		point.mlx = &mlx;
		point.cord = &cord;
		mlx.mlx = mlx_init();
		set_param_pixel(&cord, 1920, 1040);
		mlx.win = mlx_new_window(mlx.mlx, cord.max_x, cord.max_y, "FRAKTOL");
		img.img = mlx_new_image(mlx.mlx, cord.max_x, cord.max_y);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel,
				&img.line_length, &img.endian);
		input_argv(&point, argv, argc);
	}
	else
		error();
	return (0);
}
