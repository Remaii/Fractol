/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:53:26 by rthidet           #+#    #+#             */
/*   Updated: 2016/04/25 15:31:17 by rthidet          ###   ########.fr       */
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
# define MAX 400

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
}					t_mlx;

/*
** mandelbrot.c
*/

void				mandelbrot(t_mlx *f);

/*
** utilis.c
*/

void				error(int nb);
int					ft_key(int keycode, t_mlx *f);

/*
** init.c
*/

void				ini_mandelbrot(t_mlx *f);
void				init_env(t_mlx *f);
void				init_frac(t_mlx *f, int ac, char **av);

void				make_fractal(t_mlx *f);
#endif
