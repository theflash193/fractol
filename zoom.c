/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 18:29:51 by grass-kw          #+#    #+#             */
/*   Updated: 2015/10/27 18:58:55 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	zoom(t_env *e, int x, int y)
{
	(void)x;
	(void)y;
	e->zoom += e->inc;
	e->maxrecursion += e->inc_recurs;
	algorithm(e);
}

void	dezoom(t_env *e, int x, int y)
{
	(void)x;
	(void)y;
	e->zoom -= (e->maxrecursion - e->inc > 0) ? e->inc : 0;
	e->maxrecursion -= (e->maxrecursion - e->inc_recurs > 0)
		? e->inc_recurs : 0;
	algorithm(e);
}
