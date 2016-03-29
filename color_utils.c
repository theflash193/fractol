/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:49:40 by grass-kw          #+#    #+#             */
/*   Updated: 2015/12/04 15:35:23 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void		case_init_2(t_conv *e)
{
	if (e->i == 4)
	{
		e->r = e->t;
		e->g = e->p;
		e->b = e->v;
	}
	if (e->i == 5)
	{
		e->r = e->v;
		e->g = e->p;
		e->b = e->q;
	}
}

static void		case_init(t_conv *e)
{
	if (e->i == 0)
	{
		e->r = e->v;
		e->g = e->t;
		e->b = e->p;
	}
	if (e->i == 1)
	{
		e->r = e->q;
		e->g = e->v;
		e->b = e->p;
	}
	if (e->i == 2)
	{
		e->r = e->p;
		e->g = e->v;
		e->b = e->t;
	}
	if (e->i == 3)
	{
		e->r = e->p;
		e->g = e->q;
		e->b = e->v;
	}
	case_init_2(e);
}

t_color_hsv		rgb_to_hsv(t_color_rgb rgb)
{
	t_conv e;

	e.color = init_rgb(rgb.r / 256.0, rgb.g / 256.0, rgb.b / 256.0);
	e.max_color = ft_max(rgb.r, rgb.g, rgb.b);
	e.min_color = ft_min(rgb.r, rgb.g, rgb.b);
	e.v = e.max_color;
	e.s = (e.max_color == 0) ? 0 : ((e.max_color - e.min_color) / e.max_color);
	if (e.s == 0)
		e.h = 0;
	else
	{
		if (e.color.r == e.max_color)
			e.h = (e.color.g - e.b) / (e.max_color - e.min_color);
		else if (e.color.g == e.max_color)
			e.h = 2.0 + (e.color.b - e.color.r) / (e.max_color - e.min_color);
		else
			e.h = (4.0 + (e.color.r - e.color.g) / (e.max_color - e.min_color))
				/ 6.0;
		if (e.h < 0)
			e.h++;
	}
	e.new_hsv.h = (int)(e.h * 255.0);
	e.new_hsv.s = (int)(e.s * 255.0);
	e.new_hsv.v = (int)(e.v * 255.0);
	return (e.new_hsv);
}

t_color_rgb		hsv_to_rgb(t_color_hsv fmt_hsv)
{
	t_conv e;

	e.h = fmt_hsv.h / 256.0;
	e.s = fmt_hsv.s / 256.0;
	e.v = fmt_hsv.v / 256.0;
	if (e.s == 0)
	{
		e.r = e.v;
		e.g = e.v;
		e.b = e.v;
	}
	else
	{
		e.h *= 6;
		e.i = (int)(floor(e.h));
		e.f = e.h - e.i;
		e.p = e.v * (1 - e.s);
		e.q = e.v * (1 - (e.s * e.f));
		e.t = e.v * (1 - (e.s * (1 - e.f)));
		case_init(&e);
	}
	e.new_color.r = e.r;
	e.new_color.g = e.g;
	e.new_color.b = e.b;
	return (e.new_color);
}
