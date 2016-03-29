/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_recursive_sub_triangle.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 18:10:20 by grass-kw          #+#    #+#             */
/*   Updated: 2015/12/07 18:58:09 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

static void		last_sub_triangle(t_env *e, int n, t_params params
	, t_params tmp)
{
	params.p1 = initilize_fpoint((tmp.p1.x + tmp.p3.x) / 2
		+ (tmp.p3.x - tmp.p2.x) / 2, (tmp.p1.y + tmp.p3.y) / 2
		+ (tmp.p3.y - tmp.p2.y) / 2);
	params.p2 = initilize_fpoint((tmp.p1.x + tmp.p3.x) / 2
		+ (tmp.p1.x - tmp.p2.x) / 2
		, (tmp.p1.y + tmp.p3.y) / 2 + (tmp.p1.y - tmp.p2.y) / 2);
	params.p3 = initilize_fpoint((tmp.p1.x + tmp.p3.x) / 2
		, (tmp.p1.y + tmp.p3.y) / 2);
	sub_triangle(e, n + 1, params);
}

void			draw_recursive_sub_triangle(t_env *e, int n, t_params params
	, t_params tmp)
{
	if (n < e->depth)
	{
		params.p1 = initilize_fpoint((tmp.p1.x + tmp.p2.x) /
			2 + (tmp.p2.x - tmp.p3.x) / 2,
			(tmp.p1.y + tmp.p2.y) / 2 + (params.p2.y - params.p3.y) / 2);
		params.p2 = initilize_fpoint((tmp.p1.x + tmp.p2.x) / 2 +
			(tmp.p1.x - tmp.p3.x) / 2
			, (tmp.p1.y + tmp.p2.y) / 2 + (tmp.p1.y - tmp.p3.y) / 2);
		params.p3 = initilize_fpoint((tmp.p1.x + tmp.p2.x) / 2
			, (tmp.p1.y + tmp.p2.y) / 2);
		sub_triangle(e, n + 1, params);
		params.p1 = initilize_fpoint((tmp.p3.x + tmp.p2.x) / 2 +
			(tmp.p2.x - tmp.p1.x) / 2, (tmp.p3.y + tmp.p2.y) / 2 +
			(tmp.p2.y - tmp.p1.y) / 2);
		params.p2 = initilize_fpoint((tmp.p3.x + tmp.p2.x) / 2 +
			(tmp.p3.x - tmp.p1.x) / 2,
			(tmp.p3.y + tmp.p2.y) / 2 + (tmp.p3.y - tmp.p1.y) / 2);
		params.p3 = initilize_fpoint((tmp.p3.x + tmp.p2.x) / 2
			, (tmp.p3.y + tmp.p2.y) / 2);
		sub_triangle(e, n + 1, params);
		last_sub_triangle(e, n, params, tmp);
	}
}
