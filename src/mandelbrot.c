/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:56:22 by rthidet           #+#    #+#             */
/*   Updated: 2016/04/25 15:28:05 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void			make_point(t_mlx *f, int i, int it)
{
	int			index;

	index = f->x * (f->bpp / 8) + (f->y * f->size);
	if (i == it)
	{
		f->data[index] = 255;
		f->data[index + 1] = 255;
		f->data[index + 2] = 255;
	}
	else
	{
		f->data[index] = f->i * f->b / f->it;
		f->data[index + 1] = f->i * f->g / f->it;
		f->data[index + 2] = f->i * f->r / f->it;
	}
}

void			mandelbrot(t_mlx *f)
{
	f->x = 0;
	while (f->x < f->img_x)
	{
		f->y = 0;
		while (f->y < f->img_y)
		{
			f->cr = f->x / f->zoom_x + f->x1;
			f->ci = f->y / f->zoom_y + f->y1;
			f->zr = 0;
			f->zi = 0;
			f->i = 0;
			while (f->zr * f->zr + f->zi * f->zi < 4 && f->i < f->it)
			{
				f->tmp = f->zr;
				f->zr = f->zr * f->zr - f->zi * f->zi + f->cr;
				f->zi = 2 * f->zi * f->tmp + f->ci;
				f->i++;
				make_point(f, f->i, f->it);
			}
			f->y++;
		}
		f->x++;
	}
}
