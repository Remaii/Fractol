/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:56:22 by rthidet           #+#    #+#             */
/*   Updated: 2016/04/26 21:02:57 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void			make_buddha(t_mlx *f)
{
	int			index;

	index = f->x * (f->bpp / 8) + (f->y * f->size);
	if (f->i == f->it)
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
/*
void			make2(t_mlx *f, int i)
{
	double	zr;
	double	zi;

	zr = f->zr;
	zi = f->zi;

}
*/
void			buddhabrot(t_mlx *f)
{
	f->x = 0;
	while (f->x < f->img_x)
	{
		f->y = 0;
		while (f->y < f->img_y)
		{
			f->cr = (f->x * 3) / f->img_x - 2;
			f->ci = (f->y * 3) / f->img_y - 1.5;
			f->zr = 0;
			f->zi = 0;
			f->i = 0;
			while (f->i <= f->it && (f->zr * f->zr + f->zi * f->zi) > 4.05)
			{
				f->tmp = f->zr;
				f->zr = (f->zr * f->zr) - (f->zi * f->zi) + f->cr;
				f->zi = (f->tmp * f->zi) + (f->zi * f->tmp) + f->ci;
				make_buddha(f);
				f->i++;
			}
			f->y++;
		}
		f->x++;
	}
}
