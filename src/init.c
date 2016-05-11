/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 13:02:30 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/01 18:59:33 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		ini_img(t_mlx *f)
{
	if (!f->img)
	{
		f->img = mlx_new_image(f->mlx, f->img_x, f->img_y);
		f->data = mlx_get_data_addr(f->img, &(f->bpp), &(f->size), &(f->end));
	}
	else
	{
		mlx_destroy_image(f->mlx, f->img);
		f->img = mlx_new_image(f->mlx, f->img_x, f->img_y);
		f->data = mlx_get_data_addr(f->img, &(f->bpp), &(f->size), &(f->end));
	}
}

void		init_env(t_mlx *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, f->img_x, f->img_y, f->name);
	ini_img(f);
	f->pos_x = 0;
	f->pos_y = 0;
	f->r = 0;
	f->g = 0;
	f->b = 400;
	f->julia = 1;
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
