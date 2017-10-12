/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:56:22 by rthidet           #+#    #+#             */
/*   Updated: 2017/03/17 21:29:56 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void			julia(t_mlx *f)
{
	FF(x) = 0;
	while (FF(x) < f->wid)
	{
		FF(y) = 0;
		while (FF(y) < f->hig)
		{
			FF(z).r = FF(x) / FF(zoom_x) + FF(x1);
			FF(z).i = FF(y) / FF(zoom_y) + FF(y1);
			FF(c).r = FF(c2).r + FF(mouse_x);
			FF(c).i = FF(c2).i + FF(mouse_y);
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
