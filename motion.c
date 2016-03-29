/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   motion.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/27 17:02:26 by grass-kw          #+#    #+#             */
/*   Updated: 2015/12/04 16:28:18 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

int			motion_mouse(int x, int y, t_env *e)
{
	if ((x > 0 && x < LENGHT) && (y > 0 && y < WIDTH))
	{
		e->c_re += (x > LENGHT / 4) ? 0.0005 : -0.0005;
		e->c_im += (y > WIDTH / 4) ? 0.0000005 : -0.000005;
	}
	algorithm(e);
	return (0);
}

void		increment(t_env *e)
{
	e->inc += 5;
	e->inc_recurs += 6;
}

void		decrement(t_env *e)
{
	e->inc -= 5;
	e->inc_recurs += 6;
}
