/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sierpinski.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 17:22:56 by grass-kw          #+#    #+#             */
/*   Updated: 2015/12/07 18:11:17 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	init_sierpinski(t_env *e)
{
	e->depth = 7;
}

void	sierpinski(t_env *e)
{
	t_params	params;

	white_screen(e);
	e->color = 0x000000;
	params.p1 = initilize_fpoint(10, LENGHT - 10);
	params.p2 = initilize_fpoint(WIDTH - 10, LENGHT - 10);
	params.p3 = initilize_fpoint(WIDTH / 2, 10);
	draw_sierpinski(e, params);
}

void	draw_sierpinski(t_env *e, t_params params)
{
	t_ipoint d1;
	t_ipoint d2;
	t_params tmp;

	tmp = params;
	d1 = initilize_ipoint(tmp.p1.x, tmp.p1.y);
	d2 = initilize_ipoint(tmp.p2.x, tmp.p2.y);
	bresenham(e, d1, d2);
	d1 = initilize_ipoint(tmp.p1.x, tmp.p1.y);
	d2 = initilize_ipoint(tmp.p3.x, tmp.p3.y);
	bresenham(e, d1, d2);
	d1 = initilize_ipoint(tmp.p2.x, tmp.p2.y);
	d2 = initilize_ipoint(tmp.p3.x, tmp.p3.y);
	bresenham(e, d1, d2);
	params.p1 = initilize_fpoint((tmp.p1.x + tmp.p2.x) / 2,
		(tmp.p1.y + tmp.p2.y) / 2);
	params.p2 = initilize_fpoint((tmp.p1.x + tmp.p3.x) / 2,
		(tmp.p1.y + tmp.p3.y) / 2);
	params.p3 = initilize_fpoint((tmp.p2.x + tmp.p3.x) / 2,
		(tmp.p2.y + tmp.p3.y) / 2);
	sub_triangle(e, 1, params);
}

void	sub_triangle(t_env *e, int n, t_params params)
{
	t_ipoint d1;
	t_ipoint d2;
	t_params tmp;

	tmp = params;
	d1 = initilize_ipoint(tmp.p1.x, tmp.p1.y);
	d2 = initilize_ipoint(tmp.p2.x, tmp.p2.y);
	bresenham(e, d1, d2);
	d1 = initilize_ipoint(tmp.p1.x, tmp.p1.y);
	d2 = initilize_ipoint(tmp.p3.x, tmp.p3.y);
	bresenham(e, d1, d2);
	d1 = initilize_ipoint(tmp.p2.x, tmp.p2.y);
	d2 = initilize_ipoint(tmp.p3.x, tmp.p3.y);
	bresenham(e, d1, d2);
	draw_recursive_sub_triangle(e, n, params, tmp);
}
