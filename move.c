/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 10:21:28 by grass-kw          #+#    #+#             */
/*   Updated: 2015/10/23 12:02:18 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	left(t_env *e)
{
	e->move_x -= 0.05 / e->zoom;
	algorithm(e);
}

void	right(t_env *e)
{
	e->move_x += 0.05 / e->zoom;
	algorithm(e);
}

void	up(t_env *e)
{
	if (e->algorithm != SIERPINSKI)
		e->move_y -= 0.05 / e->zoom;
	else if (e->algorithm == SIERPINSKI && e->depth != 13)
		e->depth++;
	algorithm(e);
}

void	down(t_env *e)
{
	if (e->algorithm != SIERPINSKI)
		e->move_y += 0.05 / e->zoom;
	else if (e->algorithm == SIERPINSKI)
		e->depth--;
	algorithm(e);
}
