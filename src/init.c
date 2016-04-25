/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 13:02:30 by rthidet           #+#    #+#             */
/*   Updated: 2016/04/25 15:55:55 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void			ini_mandelbrot(t_mlx *f)
{
	f->x1 = -2.1;
	f->y1 = -1.2;
	f->x2 = 0.6;
	f->y2 = 1.2;
	f->it = 50;
	f->img_x = 900;
	f->img_y = 900;
	f->zoom_x = f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->img_y / (f->y2 - f->y1);
}

void			ini_julia(t_mlx *f)
{
	f->x1 = -1;
	f->y1 = -1.2;
	f->x2 = 1;
	f->y2 = 1.2;
	f->it = 150;
	f->img_x = (f->x2 - f->x1) * 100;
	f->img_y = (f->y2 - f->y1) * 100;
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
	f->b = 400;
}

void		init_frac(t_mlx *f, int ac, char **av)
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
			ini_julia(f);
			f->name = "Julia";
		}
		else if (ft_strcmp(av[1], "Autre") == 0 || ft_strcmp(av[1], "A") == 0 \
				|| ft_strcmp(av[1], "a") == 0)
		{
			f->name = "Autre";
		}
	}
	else
		error(2);
	init_env(f);
}
