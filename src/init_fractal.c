/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_fractal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 20:27:09 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/26 13:01:41 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void			ini_burning(t_mlx *f)
{
	FF(x1) = -2.1;
	FF(y1) = -2.5;
	FF(x2) = 0.39;
	FF(y2) = 0.5;
	if (f->ocl == 1)
		FF(it) = 70;
	else
		FF(it) = 30;
	FF(mouse_x) = 0;
	FF(mouse_y) = 0;
	FF(zoom_x) = f->wid / (FF(x2) - FF(x1));
	FF(zoom_y) = f->hig / (FF(y2) - FF(y1));
}

void			ini_mandelbrot(t_mlx *f)
{
	FF(x1) = -2.1;
	FF(y1) = -1.2;
	FF(x2) = 0.6;
	FF(y2) = 1.2;
	if (f->ocl == 1)
		FF(it) = 100;
	else
		FF(it) = 50;
	FF(mouse_x) = 0;
	FF(mouse_y) = 0;
	FF(zoom_x) = f->wid / (FF(x2) - FF(x1));
	FF(zoom_y) = f->hig / (FF(y2) - FF(y1));
}

void			ini_julia(t_mlx *f)
{
	FF(x1) = -2;
	FF(y1) = -2;
	FF(x2) = 2;
	FF(y2) = 2;
	if (f->ocl == 1)
		FF(it) = 100;
	else
		FF(it) = 50;
	FF(zoom_x) = f->wid / (FF(x2) - FF(x1));
	FF(zoom_y) = f->hig / (FF(y2) - FF(y1));
	choose_julia(f);
}

void			ifocl(t_mlx *f, int ac, char **av)
{
	if (ac == 3)
	{
		if (ft_strcmp(av[2], "cl") == 0)
		{
			f->ocl = 1;
			if (ft_strcmp(f->name, "Mandelbrot") == 0)
				f->path = "Kernel/mandelbrot.cl";
			else if (ft_strcmp(f->name, "Julia") == 0)
				f->path = "Kernel/julia.cl";
			else if (ft_strcmp(f->name, "Burning-Ship") == 0)
				f->path = "Kernel/burningship.cl";
			re_init_frac(f);
		}
	}
}

void			init_frac(t_mlx *f, int ac, char **av)
{
	if (ac >= 2)
	{
		f->f = (t_fra*)ft_memalloc(sizeof(t_fra));
		f->ocl = 0;
		FF(coef) = 0.78;
		if (ft_strcmp(av[1], "Mandelbrot") == 0 || ft_strcmp(av[1], "M") == 0 \
				|| ft_strcmp(av[1], "m") == 0)
			f->name = "Mandelbrot";
		else if (ft_strcmp(av[1], "Julia") == 0 || ft_strcmp(av[1], "J") == 0 \
				|| ft_strcmp(av[1], "j") == 0)
			f->name = "Julia";
		else if (ft_strcmp(av[1], "Burningship") == 0 \
				|| ft_strcmp(av[1], "B") == 0 || ft_strcmp(av[1], "b") == 0)
			f->name = "Burning-Ship";
		init_env(f);
		re_init_frac(f);
		ifocl(f, ac, av);
	}
	else
		error(1);
}
