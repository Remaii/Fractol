/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:53:26 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/11 10:23:26 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../inc/libft.h"
# include "../inc/mlx.h"
# include <stdlib.h>

# include <stdio.h>

# define USAGE "./fractol Mandelbrot | Julia | Autre"
# define MIN 100
# define MAX 4000
# define WIN_X 1000
# define WIN_Y 1000

typedef struct		s_comp
{
	double		r;
	double		i;
}									t_comp;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				size;
	int				end;
	int				pos_x;
	int				pos_y;
	int				motion;
	char			*name;

	int				img_x;
	int				img_y;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				it;
	int				i;
	int				x;
	int				y;
	double			zoom_x;
	double			zoom_y;
	double			zr;
	double			zi;
	double			cr;
	double			ci;
	double			cr2;
	double			ci2;
	double			tmp;
	int				r;
	int				g;
	int				b;
	double			mouse_x;
	double			mouse_y;
	int				julia;
}					t_mlx;

/*
** mandelbrot.c
*/

void				mandelbrot(t_mlx *f);

/*
** buddhabrot.c
*/

void				buddhabrot(t_mlx *f);

/*
** julia.c
*/

void				julia(t_mlx *f);

/*
** ini_julia.c
*/

void 				set_julia1(t_mlx *f);
void 				set_julia2(t_mlx *f);
void 				set_julia3(t_mlx *f);
void 				set_julia4(t_mlx *f);
void 				set_julia5(t_mlx *f);

/*
** utilis.c
*/

void				make_point(t_mlx *f, int i, int it);
void				ft_stop(t_mlx *f);
void				error(int nb);

/*
** hook.c
*/

int					ft_key(int keycode, t_mlx *f);
int					ft_mouse(int but, int x, int y, t_mlx *f);
int					mouse_move(int x, int y, t_mlx *f);

/*
** zoom.c
*/

void				zoom(int but, int x, int y, t_mlx *f);

/*
** init_frac.c
*/

void				ini_mandelbrot(t_mlx *f);
void				ini_julia(t_mlx *f);
void				ini_buddha(t_mlx *f);
void				init_frac(t_mlx *f, int ac, char *av);
void				choose_julia(t_mlx *f);

/*
** init.c
*/

void				ini_img(t_mlx *f);
void				init_env(t_mlx *f);
void				re_init_frac(t_mlx *f);

/*
** main.c
*/

void				make_fractal(t_mlx *f);

#endif
