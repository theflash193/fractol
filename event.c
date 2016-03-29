/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 17:32:56 by grass-kw          #+#    #+#             */
/*   Updated: 2015/12/04 17:08:11 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int		expose(t_env *e)
{
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		mouse(int button, int x, int y, t_env *e)
{
	if (e->algorithm == JULIA || e->algorithm == MANDELBROT)
	{
		if (button == MOUSE_WHEEL_UP)
			zoom(e, x, y);
		if (button == MOUSE_WHEEL_DOWN)
			dezoom(e, x, y);
	}
	return (0);
}

int		key(int key, t_env *e)
{
	if (key == 53)
	{
		mlx_destroy_image(e->mlx, e->img);
		exit(0);
	}
	if (key == KEY_UP)
		up(e);
	if (key == KEY_DOWN)
		down(e);
	if (key == KEY_LEFT && e->algorithm != SIERPINSKI)
		left(e);
	if (key == KEY_RIGHT && e->algorithm != SIERPINSKI)
		right(e);
	if (key == KEY_PAVNUM_MINUS)
		decrement(e);
	if (key == KEY_PAVNUM_PLUS)
		increment(e);
	return (0);
}
