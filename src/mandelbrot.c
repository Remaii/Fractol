/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:56:22 by rthidet           #+#    #+#             */
/*   Updated: 2016/06/19 16:31:58 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void			mandelbrot(t_mlx *f)
{
	FF(x) = 0;
	while (FF(x) < f->wid)
	{
		FF(y) = 0;
		while (FF(y) < f->hig)
		{
			FF(c).r = FF(x) / FF(zoom_x) + FF(x1);
			FF(c).i = FF(y) / FF(zoom_y) + FF(y1);
			FF(z).r = 0 + FF(mouse_x);
			FF(z).i = 0 + FF(mouse_y);
			FF(i) = 0;
			while (FF(z).r * FF(z).r + FF(z).i * FF(z).i < 4 && FF(i) < FF(it))
			{
				FF(tmp) = FF(z).r;
				FF(z).r = FF(z).r * FF(z).r - FF(z).i * FF(z).i + FF(c).r;
				FF(z).i = 2 * FF(z).i * FF(tmp) + FF(c).i;
				FF(i)++;
				make_point(f, FF(i), FF(it));
			}
			FF(y)++;
		}
		FF(x)++;
	}
}
