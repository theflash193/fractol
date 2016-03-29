/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 18:15:20 by grass-kw          #+#    #+#             */
/*   Updated: 2015/12/04 17:11:16 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	bresenham(t_env *e, t_ipoint x1, t_ipoint x2)
{
	int		dx;
	int		dy;

	dx = x2.x - x1.x;
	dy = x2.y - x1.y;
	dx = abs(dx);
	dy = abs(dy);
	if (dx > dy)
		draw_line(e, x1, x2);
	else
		draw_vertical(e, x1, x2);
}

void	ft_init(t_draw *a, t_ipoint x1, t_ipoint x2)
{
	a->x = x1.x;
	a->y = x1.y;
	a->dx = x2.x - x1.x;
	a->dy = x2.y - x1.y;
	a->xinc = (a->dx > 0) ? 1 : -1;
	a->yinc = (a->dy > 0) ? 1 : -1;
	a->dx = abs(a->dx);
	a->dy = abs(a->dy);
}

void	draw_line(t_env *e, t_ipoint x1, t_ipoint x2)
{
	int		i;
	t_draw	a;

	ft_init(&a, x1, x2);
	i = 1;
	mlx_put_pixel_to_img(e, e->color, a.x, a.y);
	a.cumul = a.dx / 2;
	while (i <= a.dx)
	{
		a.x += a.xinc;
		a.cumul += a.dy;
		if (a.cumul >= a.dx)
		{
			a.cumul -= a.dx;
			a.y += a.yinc;
		}
		mlx_put_pixel_to_img(e, e->color, a.x, a.y);
		i++;
	}
}

void	draw_vertical(t_env *e, t_ipoint x1, t_ipoint x2)
{
	int		i;
	t_draw	a;

	ft_init(&a, x1, x2);
	i = 1;
	mlx_put_pixel_to_img(e, e->color, a.x, a.y);
	a.cumul = a.dy / 2;
	while (a.y <= a.dy)
	{
		a.y += a.yinc;
		a.cumul += a.dx;
		if (a.cumul >= a.dy)
		{
			a.cumul -= a.dy;
			a.x += a.xinc;
		}
		mlx_put_pixel_to_img(e, e->color, a.x, a.y);
		i++;
	}
}
