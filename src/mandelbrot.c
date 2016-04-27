/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:56:22 by rthidet           #+#    #+#             */
/*   Updated: 2016/04/26 17:14:51 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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
			f->zr = 0 + f->mouse_x;
			f->zi = 0 + f->mouse_y;
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
