/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/18 18:36:53 by grass-kw          #+#    #+#             */
/*   Updated: 2015/12/04 17:07:22 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void					init_mandelbrot(t_env *e)
{
	e->move_x = 0;
	e->move_y = 0;
	e->zoom = 1;
	e->c_re = -0.6;
	e->c_im = 1.4;
	e->maxrecursion = 20;
	e->inc = 1.1;
	e->inc_recurs = 3;
}

t_color_rgb				mandelbrot(t_env *e, int x, int y)
{
	int					i;
	t_color_rgb			color_rgb;

	e->c_re = 1.5 * (x - LENGHT / 2) / (0.5 * e->zoom * LENGHT) + e->move_x;
	e->c_im = (y - WIDTH / 2) / (0.5 * e->zoom * WIDTH) + e->move_y;
	e->new_re = 0;
	e->new_im = 0;
	e->old_re = 0;
	e->old_im = 0;
	i = 0;
	while (i++ < e->maxrecursion)
	{
		e->old_re = e->new_re;
		e->old_im = e->new_im;
		e->new_re = e->old_re * e->old_re - e->old_im * e->old_im + e->c_re;
		e->new_im = 2 * e->old_re * e->old_im + e->c_im;
		if ((e->new_re * e->new_re + e->new_im * e->new_im) > 4)
			break ;
	}
	color_rgb.r = i * 10;
	color_rgb.g = 255;
	color_rgb.b = 255 * (i < e->maxrecursion);
	color_rgb = hsv_to_rgb(rgb_to_hsv(color_rgb));
	return (color_rgb);
}

void					mandelbrot_rs(t_env *e)
{
	int					color;
	int					x;
	int					y;
	t_color_rgb			color_rgb;

	x = 0;
	while (x++ < LENGHT)
	{
		y = 0;
		while (y++ < WIDTH)
		{
			color_rgb = mandelbrot(e, x, y);
			color = new_color(color_rgb.r, color_rgb.g, color_rgb.b);
			mlx_put_pixel_to_img(e, color, x, y);
		}
	}
}
