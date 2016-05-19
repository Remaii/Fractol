/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:56:22 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/19 00:36:43 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <math.h>

void		make_buddha(t_mlx *f, int **img)
{
	int x;
	int y;
	int index;

	y = 0;
	while (y < f->img_y)
	{
		x = 0;
		while (x < f->img_x)
		{
			index = x * (f->bpp / 8) + y * f->size;
			f->data[index] = abs(img[y][x]);
			f->data[index + 1] = abs(img[y][x]);
			f->data[index + 2] = abs(img[y][x]);
			x++;
		}
		y++;
	}
}

void		buddhabrot(t_mlx *f)
{
	int **img;
	int tx;
	int ty;

	f->x = 0;
	img = (int **)ft_memalloc(sizeof(int *) * f->img_y);
	while (f->x < f->img_y)
	{
		img[f->x] = (int *)ft_memalloc(sizeof(int *) * f->img_x);
		f->x++;
	}
	f->x = 0;
	while (f->x < f->img_x)
	{
		f->y = 0;
		while (f->y < f->img_y)
		{
			f->cr = ((double)f->x / f->img_x) + f->x1;
			f->ci = ((double)f->y / f->img_y) + f->y1;
			f->cr2 = f->cr;
			f->ci2 = f->ci;
			f->i = 0;
printf("x= %d, y= %d, cr = %f, ci = %f , pow = %f\n", f->x, f->y, f->cr, f->ci, pow(f->cr, 2) * pow(f->ci, 2));
			while (pow(f->cr, 2) * pow(f->ci, 2) < 10 && f->i < f->it)
			{
				f->tmp = (f->cr * f->cr) - (f->ci * f->ci) + f->cr2;
				f->ci = 2 * f->cr * f->ci + f->ci2;
				f->cr = f->tmp;
//				if ((f->cr * f->cr) + (f->ci * f->ci) < 4)
//				{
					tx = (int)((f->cr + 2) * f->zoom_x) / 2;
					ty = (int)((f->ci + 1.5) * f->zoom_y) / 2;
					if (tx < f->img_x && tx > 0 && ty < f->img_y && ty > 0)
					{
						img[ty][tx]++;
						make_buddha(f, img);
					}
//				}
				f->i++;
printf("-----cr = %f, ci = %f, zr = %f, zi = %f i = %d pow= %f\n", f->cr, f->ci, f->zr, f->zi, f->i, (f->cr * f->cr) + (f->ci * f->ci));
			}
			f->y++;
		}
		f->x++;
	}
}

