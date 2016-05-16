/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 12:31:50 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/16 19:08:58 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void			ini_buddha(t_mlx *f)
{
	f->x1 = -1.125;
	f->y1 = -2;
	f->x2 = 1.125;
	f->y2 = 1;
	f->it = 1000;
	f->mouse_x = 0;
	f->mouse_y = 0;
	f->img_x = WIN_X;
	f->img_y = WIN_Y;
	f->zoom_x = (f->x2 - f->x1) / f->img_x;
	f->zoom_y = (f->y2 - f->y1) / f->img_y;
}

void			ini_mandelbrot(t_mlx *f)
{
	f->x1 = -2.1;
	f->y1 = -1.2;
	f->x2 = 0.6;
	f->y2 = 1.2;
	f->it = 50;
	f->mouse_x = 0;
	f->mouse_y = 0;
	f->img_x = WIN_X;
	f->img_y = WIN_Y;
	f->zoom_x = f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->img_y / (f->y2 - f->y1);
}

void			ini_julia(t_mlx *f)
{
	f->x1 = -2;
	f->y1 = -2;
	f->x2 = 2;
	f->y2 = 2;
	f->it = 50;
	f->mouse_x = 0;
	f->mouse_y = 0;
	f->img_x = WIN_X;
	f->img_y = WIN_Y;
	f->zoom_x = f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->img_y / (f->y2 - f->y1);
	choose_julia(f);
}

void			verif(t_mlx *f, int ac, char **av)
{
	if (ac == 3 && ft_strcmp(av[2], "cl") == 0)
	{
		if (ft_strcmp(av[1], "Mandelbrot") == 0 || ft_strcmp(av[1], "M") == 0 \
				|| ft_strcmp(av[1], "m") == 0)
		{
			ini_mandelbrot(f);
			f->name = "src/mandel.cl";
		}
		else if (ft_strcmp(av[1], "Julia") == 0 || ft_strcmp(av[1], "J") == 0 \
				|| ft_strcmp(av[1], "j") == 0)
		{
			f->julia = 1;
			ini_julia(f);
			f->name = "julia.cl";
		}
		else if (ft_strcmp(av[1], "Buddhabrot") == 0 || ft_strcmp(av[1], "B") == 0 \
				|| ft_strcmp(av[1], "b") == 0)
		{
			ini_buddha(f);
			f->name = "buddhabrot.cl";
		}
		init_env(f);
		set_arg(f);
	}
	else
		error(1);
}

void			init_frac(t_mlx *f, int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_strcmp(av[1], "Mandelbrot") == 0 || ft_strcmp(av[1], "M") == 0 \
				|| ft_strcmp(av[1], "m") == 0)
		{
			ini_mandelbrot(f);
			f->name = "Mandelbrot";
		}
		else if (ft_strcmp(av[1], "Julia") == 0 || ft_strcmp(av[1], "J") == 0 \
				|| ft_strcmp(av[1], "j") == 0)
		{
			f->julia = 1;
			ini_julia(f);
			f->name = "Julia";
		}
		else if (ft_strcmp(av[1], "Buddhabrot") == 0 || ft_strcmp(av[1], "B") == 0 \
				|| ft_strcmp(av[1], "b") == 0)
		{
			ini_buddha(f);
			f->name = "Buddhabrot";
		}
	}
	else
		verif(f, ac, av);
	init_env(f);
}
