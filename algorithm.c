/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/15 14:31:15 by grass-kw          #+#    #+#             */
/*   Updated: 2015/12/04 16:48:31 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void		algorithm(t_env *e)
{
	if (e->algorithm == JULIA)
		julia_rs(e);
	if (e->algorithm == MANDELBROT)
		mandelbrot_rs(e);
	if (e->algorithm == SIERPINSKI)
		sierpinski(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
