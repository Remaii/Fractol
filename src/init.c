/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 20:24:58 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/26 20:48:56 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		ini_img(t_mlx *f)
{
	if (f->crt_img == 0)
	{
		f->img = mlx_new_image(f->mlx, f->wid, f->hig);
		f->data = mlx_get_data_addr(f->img, &(f->bpp), &(f->size), &(f->end));
		f->crt_img = 1;
	}
	else
	{
		mlx_destroy_image(f->mlx, f->img);
		f->img = mlx_new_image(f->mlx, f->wid, f->hig);
		f->data = mlx_get_data_addr(f->img, &(f->bpp), &(f->size), &(f->end));
	}
}

void		init_env(t_mlx *f)
{
	f->wid = WID;
	f->hig = HIG;
	FF(r) = 5;
	FF(g) = 10;
	FF(b) = 5;
	FF(zoom) = 0;
	f->crt_img = 0;
	FF(julia) = 1;
	f->motion = 0;
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, f->wid, f->hig, f->name);
	ini_img(f);
}

void		re_init_frac(t_mlx *f)
{
	FF(coef) = 0.78;
	FF(zoom) = 0;
	FF(r) = 5;
	FF(g) = 10;
	FF(b) = 5;
	if (ft_strcmp(f->name, "Mandelbrot") == 0)
		ini_mandelbrot(f);
	else if (ft_strcmp(f->name, "Julia") == 0)
		ini_julia(f);
	else if (ft_strcmp(f->name, "Burning-Ship") == 0)
		ini_burning(f);
}
