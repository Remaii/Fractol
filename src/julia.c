/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:56:22 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/01 18:58:46 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void			julia(t_mlx *f)
{
	f->x = 0;
	while (f->x < f->img_x)
	{
		f->y = 0;
		while (f->y < f->img_y)
		{
			f->zr = f->x / f->zoom_x + f->x1;
			f->zi = f->y / f->zoom_y + f->y1;
			f->cr = f->cr2 + f->mouse_x;
			f->ci = f->ci2 + f->mouse_y;
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
