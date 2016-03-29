/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 14:18:53 by grass-kw          #+#    #+#             */
/*   Updated: 2015/12/04 17:26:21 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	parser(t_env *e, int ac, char **av)
{
	if (ac != 2)
		ft_error("List of Fractal :\n- julia\n- mandelbrot\n- sierpinski");
	if (!ft_strcmp(av[1], "julia") || !ft_strcmp(av[1], "JULIA"))
	{
		init_julia(e);
		e->algorithm = JULIA;
	}
	else if (!ft_strcmp(av[1], "mandelbrot") || !ft_strcmp(av[1], "MANDELBROT"))
	{
		init_mandelbrot(e);
		e->algorithm = MANDELBROT;
	}
	else if (!ft_strcmp(av[1], "sierpinski") || !ft_strcmp(av[1], "SIERPINSKI"))
	{
		init_sierpinski(e);
		e->algorithm = SIERPINSKI;
	}
	else
		ft_error("List of Fractal :\n- julia\n- sierpinski");
}
