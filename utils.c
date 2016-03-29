/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/02 15:48:52 by grass-kw          #+#    #+#             */
/*   Updated: 2015/12/03 17:44:53 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

t_ipoint	initilize_ipoint(float x, float y)
{
	t_ipoint ret;

	ret.x = (float)x;
	ret.y = (float)y;
	return (ret);
}

t_fpoint	initilize_fpoint(float x, float y)
{
	t_fpoint ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

float		ft_max(float a, float b, float c)
{
	int ret;

	ret = (a > b) ? a : b;
	return ((ret > c) ? ret : c);
}

float		ft_min(float a, float b, float c)
{
	int ret;

	ret = (a < b) ? a : b;
	return ((ret < c) ? ret : c);
}

t_color_rgb	init_rgb(float r, float g, float b)
{
	t_color_rgb color;

	color.r = r;
	color.g = g;
	color.b = b;
	return (color);
}
