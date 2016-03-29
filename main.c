/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 11:01:50 by grass-kw          #+#    #+#             */
/*   Updated: 2015/12/04 17:21:40 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"
#include "libft.h"

static void		env_setup(t_env *e)
{
	if ((e->mlx = mlx_init()) == NULL)
	{
		ft_putendl("fail to connect with X-server");
		exit(1);
	}
	if ((e->win = mlx_new_window(e->mlx, LENGHT, WIDTH, "fract_ol")) == NULL)
	{
		ft_putendl("fail to created window");
		exit(1);
	}
	if ((e->img = mlx_new_image(e->mlx, LENGHT, WIDTH)) == NULL)
	{
		ft_putendl("fail to created an image");
		exit(1);
	}
	if ((e->data = mlx_get_data_addr(e->img, &(e->bits_per_pixel)
		, &(e->size_line), &(e->endian))) == NULL)
	{
		ft_putendl("fail to obtain information frow image");
		exit(1);
	}
}

int				main(int ac, char **av)
{
	t_env	e;

	parser(&e, ac, av);
	env_setup(&e);
	algorithm(&e);
	mlx_key_hook(e.win, key, &e);
	mlx_mouse_hook(e.win, mouse, &e);
	mlx_expose_hook(e.win, expose, &e);
	mlx_hook(e.win, MOTION_NOTIFY, POINTER_MOTION_MASK, motion_mouse, &e);
	mlx_loop(e.mlx);
	return (0);
}
