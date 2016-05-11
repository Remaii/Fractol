/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:24:31 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/01 19:01:06 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		zoomin(t_mlx *f, int x, int y)
{
	double tx;
	double ty;
	double tmp[4];

	if (!x && !y)
		error(9);
	tx = f->x1 + x * (f->x2 - f->x1) / f->img_x;
	ty = f->y1 + y * (f->y2 - f->y1) / f->img_y;
	tmp[0] = f->x1;
	tmp[1] = f->x2;
	tmp[2] = f->y1;
	tmp[3] = f->y2;
	f->x1 = tx - (tmp[1] - tmp[0]) / 4;
	f->x2 = tx + (tmp[1] - tmp[0]) / 4;
	f->y1 = ty - (tmp[3] - tmp[2]) / 4;
	f->y2 = ty + (tmp[3] - tmp[2]) / 4;
	f->it *= 2;
	f->zoom_x *= 2;
	f->zoom_y *= 2;
}

void		zoomout(t_mlx *f, int x, int y)
{
	double tx;
	double ty;
	double tmp[4];

	if (!x && !y)
		error(9);
	tx = f->x1 - x * (f->x2 - f->x1) / f->img_x;
	ty = f->y1 - y * (f->y2 - f->y1) / f->img_y;
	tmp[0] = f->x1;
	tmp[1] = f->x2;
	tmp[2] = f->y1;
	tmp[3] = f->y2;
	f->x1 = tx + (tmp[1] - tmp[0]) / 4;
	f->x2 = tx - (tmp[1] - tmp[0]) / 4;
	f->y1 = ty + (tmp[3] - tmp[2]) / 4;
	f->y2 = ty - (tmp[3] - tmp[2]) / 4;
	f->it /= 2;
	f->zoom_x /= 2;
	f->zoom_y /= 2;
}

void		zoom(int but, int x, int y, t_mlx *f)
{
	if (but == 5 || but == 24)
		zoomin(f, x, y);
	else
		zoomout(f, x, y);
}
