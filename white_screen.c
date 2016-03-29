/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   white_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 17:26:59 by grass-kw          #+#    #+#             */
/*   Updated: 2015/12/07 17:29:29 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	white_screen(t_env *e)
{
	int x;
	int y;

	x = 0;
	while (x++ < LENGHT)
	{
		y = 0;
		while (y++ < WIDTH)
			mlx_put_pixel_to_img(e, 0xFFFFFF, x, y);
	}
}
