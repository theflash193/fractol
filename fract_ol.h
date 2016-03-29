/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fract_ol.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grass-kw <grass-kw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/14 11:03:05 by grass-kw          #+#    #+#             */
/*   Updated: 2015/12/07 18:46:41 by grass-kw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_OL_H
# define FRACT_OL_H
# include "libft.h"
# include "mlx.h"
# include "ft_keycode.h"
# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <time.h>
# define LENGHT 480
# define WIDTH 360
# define JULIA 1
# define MANDELBROT 2
# define SIERPINSKI 3
# define LEFT 123
# define RIGHT 124
# define DOWN 125
# define UP 126
# define MOTION_NOTIFY 6
# define POINTER_MOTION_MASK (1L << 6)

typedef struct			s_color_rgb
{
	float				r;
	float				g;
	float				b;
}						t_color_rgb;

typedef struct			s_color_hsv
{
	float				h;
	float				s;
	float				v;
}						t_color_hsv;

typedef struct			s_conv
{
	float				r;
	float				g;
	float				b;
	float				h;
	float				s;
	float				v;
	float				max_color;
	float				min_color;
	float				f;
	float				p;
	float				q;
	float				t;
	int					i;
	struct s_color_rgb	color;
	struct s_color_hsv	new_hsv;
	struct s_color_rgb	new_color;
}						t_conv;

typedef struct			s_fpoint
{
	float				x;
	float				y;
}						t_fpoint;

typedef struct			s_ipoint
{
	int					x;
	int					y;
}						t_ipoint;

typedef struct			s_params
{
	struct s_fpoint		p1;
	struct s_fpoint		p2;
	struct s_fpoint		p3;
}						t_params;

typedef struct			s_draw
{
	int					cumul;
	int					xinc;
	int					yinc;
	int					x;
	int					y;
	int					dx;
	int					dy;
}						t_draw;

typedef	struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*data;
	int					bits_per_pixel;
	int					size_line;
	int					endian;
	double				c_re;
	double				c_im;
	double				new_re;
	double				new_im;
	double				old_re;
	double				old_im;
	double				zoom;
	double				move_x;
	double				move_y;
	int					algorithm;
	int					maxrecursion;
	int					color;
	struct s_draw		bres;
	int					depth;
	double				inc;
	double				inc_recurs;
}						t_env;

/*
*** event.c
*/
int						expose(t_env *e);
int						mouse(int keycode, int x, int y, t_env *e);
int						key(int button, t_env *e);
void					mlx_put_pixel_to_img(t_env *e, int color, int x, int y);

/*
*** algorithm.c
*/
void					algorithm(t_env *e);

/*
*** key.c
*/
void					left(t_env *e);
void					right(t_env *e);
void					up(t_env *e);
void					down(t_env *e);

/*
*** move.c
*/
void					zoom(t_env *e, int x, int y);
void					dezoom(t_env *e, int x, int y);
void					increment(t_env *e);
void					decrement(t_env *e);

/*
***
*/
int						new_color(int r, int g, int b);
void					parser(t_env *e, int ac, char **av);
void					ft_error(char const *message);

/*
*** mandelbrot.c
*/
t_color_rgb				mandelbrot(t_env *e, int x, int y);
void					mandelbrot_rs(t_env *e);
void					init_mandelbrot(t_env *e);

/*
*** julia.c
*/
void					julia_rs(t_env *e);
void					init_julia(t_env *e);
t_color_rgb				julia(t_env *e, int x, int y);

/*
*** sierpinski
*/
void					init_sierpinski(t_env *e);
void					sierpinski(t_env *e);
void					draw_sierpinski(t_env *e, t_params params);
void					sub_triangle(t_env *e, int n, t_params params);
void					white_screen(t_env *e);

/*
*** bresenham.c
*/
void					bresenham(t_env *e, t_ipoint x1, t_ipoint x2);
void					ft_init(t_draw *a, t_ipoint x1, t_ipoint x2);
void					draw_line(t_env *e, t_ipoint x1, t_ipoint x2);
void					draw_vertical(t_env *e, t_ipoint x1, t_ipoint x2);

/*
*** motion.c
*/
int						motion_mouse(int x, int y, t_env *e);

/*
*** color_utils.c
*/
t_color_rgb				hsv_to_rgb(t_color_hsv fmt_hsv);
t_color_hsv				rgb_to_hsv(t_color_rgb rgb);

/*
*** utils.c
*/
t_ipoint				initilize_ipoint(float x, float y);
t_color_rgb				init_rgb(float r, float g, float b);
float					ft_min(float a, float b, float c);
float					ft_max(float a, float b, float c);
t_fpoint				initilize_fpoint(float x, float y);

/*
*** white_screen.c
*/
void					white_screen(t_env *e);

/*
*** draw_recursive_sub_triangle.c
*/
void					draw_recursive_sub_triangle(t_env *e, int n
	, t_params params, t_params tmp);

#endif
