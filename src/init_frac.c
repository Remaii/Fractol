/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_frac.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 12:31:50 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/01 19:00:02 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void			choose_julia(t_mlx *f)
{
	if (f->julia == 1)
		set_julia1(f);
	else if (f->julia == 2)
		set_julia2(f);
	else if (f->julia == 3)
		set_julia3(f);
	else if (f->julia == 4)
		set_julia4(f);
	else if (f->julia == 5)
		set_julia5(f);
}

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

void			init_frac(t_mlx *f, int ac, char *av)
{
	if (ac == 2)
	{
		if (ft_strcmp(av, "Mandelbrot") == 0 || ft_strcmp(av, "M") == 0 \
				|| ft_strcmp(av, "m") == 0)
		{
			ini_mandelbrot(f);
			f->name = "Mandelbrot";
		}
		else if (ft_strcmp(av, "Julia") == 0 || ft_strcmp(av, "J") == 0 \
				|| ft_strcmp(av, "j") == 0)
		{
			f->julia = 1;
			ini_julia(f);
			f->name = "Julia";
		}
		else if (ft_strcmp(av, "Buddhabrot") == 0 || ft_strcmp(av, "B") == 0 \
				|| ft_strcmp(av, "b") == 0)
		{
			ini_buddha(f);
			f->name = "Buddhabrot";
		}
	}
	else
		error(1);
	init_env(f);
}
