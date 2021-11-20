/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igarg <igarg@student.21-school.ru>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 10:15:57 by igarg             #+#    #+#             */
/*   Updated: 2021/11/19 15:39:36 by igarg            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		cod_color;

}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;

}	t_mlx;

typedef struct s_pixel_cord
{
	float	x;
	float	y;
	float	center_x;
	float	center_y;
	float	max_x;
	float	max_y;
	float	zoom;

}	t_pixel_cord;

typedef struct s_tmp
{
	float	p;
	float	pc;
	float	x_0;
	float	y_0;
	float	x_tmp;
	float	y_tmp;
	float	x;
	float	y;
	float	c;
	float	z;
	float	z_tmp;
	int		iter;
	int		i;

}	t_tmp;

typedef struct s_point
{
	t_img			*img;
	t_mlx			*mlx;
	t_pixel_cord	*cord;
	int				fractal;
	float			c_a;
	float			c_b;

}	t_point;

int		set_color_center(t_img *img);
int		set_color(t_img *img, t_tmp *tmp);

int		create_trgb(int t, int r, int g, int b);

int		mouse_hook(int mouse, int x, int y, t_point *p);
int		key_hook(int keycode, t_point *p);

float	my_atof(char *s);
float	after_dot(char c, int dot);

void	set_param_pixel(t_pixel_cord *pixel_cord, int max_x, int max_y);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

void	set_tmp(t_point *p, t_tmp *tmp);
void	set_arg(t_point *p, char **argv, int argc);

void	burning_ship_img(t_point *p, int cor_x, int cor_y, float cor_z);
void	mandelbrot_img(t_point *p, int cor_x, int cor_y, float cor_z);
void	julia_img(t_point *p, int cor_x, int cor_y, float cor_z);
void	pain_f(t_point *p, int corr_x, int cor_y, float corr_z);

#endif
