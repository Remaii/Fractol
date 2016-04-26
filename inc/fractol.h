/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:53:26 by rthidet           #+#    #+#             */
/*   Updated: 2016/04/26 17:45:03 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../inc/libft.h"
# include "../inc/mlx.h"
# include <stdlib.h>

# include <stdio.h>

# define USAGE "./fractol Mandelbrot | Julia | Autre"
# define MIN 0
# define MAX 4000

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
	double			tmp;
	int				r;
	int				g;
	int				b;
	double			mouse_x;
	double			mouse_y;
}					t_mlx;

/*
** mandelbrot.c
*/

void				make_point(t_mlx *f, int i, int it);
void				mandelbrot(t_mlx *f);

/*
** mandelbrot.c
*/

void				julia(t_mlx *f);

void			buddhabrot(t_mlx *f);

/*
** utilis.c
*/

void				ft_stop(t_mlx *f);
void				error(int nb);

/*
** hook.c
*/

int					ft_key(int keycode, t_mlx *f);
int					ft_mouse(int but, int x, int y, t_mlx *f);
int					mouse_move(int x, int y, t_mlx *f);


void				zoom(int but, int x, int y, t_mlx *f);

/*
** init.c
*/

void				ini_mandelbrot(t_mlx *f);
void				init_env(t_mlx *f);
void				re_init_frac(t_mlx *f);
void				init_frac(t_mlx *f, int ac, char *av);

void				make_fractal(t_mlx *f);
#endif
