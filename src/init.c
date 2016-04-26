/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 13:02:30 by rthidet           #+#    #+#             */
/*   Updated: 2016/04/26 19:39:15 by rthidet          ###   ########.fr       */
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
	f->img_x = 720;
	f->img_y = 1040;
	f->zoom_x = (f->x2 - f->x1) / f->img_x;
	f->zoom_y = (f->y2 - f->y1) / f->img_y;
}

void			ini_mandelbrot(t_mlx *f)
{
	f->x1 = -2.1;
	f->y1 = -1.2;
	f->x2 = 0.6;
	f->y2 = 1.2;
	f->it = 100;
	f->mouse_x = 0;
	f->mouse_y = 0;
	f->img_x = 900;
	f->img_y = 900;
	f->zoom_x = f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->img_y / (f->y2 - f->y1);
}

void			ini_julia(t_mlx *f)
{
	f->x1 = -1.5;
	f->y1 = -1.5;
	f->x2 = 1.5;
	f->y2 = 1.5;
	f->it = 200;
	f->mouse_x = 0;
	f->mouse_y = 0;
	f->img_x = 900;
	f->img_y = 900;
	f->zoom_x = f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->img_y / (f->y2 - f->y1);
}

void		init_env(t_mlx *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, f->img_x, f->img_y, f->name);
	f->img = mlx_new_image(f->mlx, f->img_x, f->img_y);
	f->data = mlx_get_data_addr(f->img, &(f->bpp), &(f->size), &(f->end));
	f->pos_x = 0;
	f->pos_y = 0;
	f->r = 0;
	f->g = 0;
	f->b = 4000;
	f->motion = 0;
}

void		re_init_frac(t_mlx *f)
{
	if (ft_strcmp(f->name, "Mandelbrot") == 0)
		ini_mandelbrot(f);
	else if (ft_strcmp(f->name, "Julia") == 0)
		ini_julia(f);
	else if (ft_strcmp(f->name, "Autre") == 0)
		ini_buddha(f);
}

void		init_frac(t_mlx *f, int ac, char *av)
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
			ini_julia(f);
			f->name = "Julia";
		}
		else if (ft_strcmp(av, "Autre") == 0 || ft_strcmp(av, "A") == 0 \
				|| ft_strcmp(av, "a") == 0)
		{
			ini_buddha(f);
			f->name = "Autre";
		}
	}
	else
		error(2);
	init_env(f);
}
