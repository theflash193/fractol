/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_image_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/04 17:23:25 by grass-kw          #+#    #+#             */
/*   Updated: 2015/12/04 17:23:49 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	mlx_put_pixel_to_img(t_env *e, int color, int x, int y)
{
	unsigned int	color2;

	color2 = mlx_get_color_value(e->mlx, color);
	if ((x < LENGHT && x >= 0) && (y < WIDTH && y >= 0))
		ft_memcpy(&e->data[(x * 4) + (y * e->size_line)],
			&color2, (size_t)sizeof(int));
}
