/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:24:31 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/22 00:21:48 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		zoomin(t_mlx *f, int x, int y)
{
	double tx;
	double ty;

	tx = x / f->zoom_x + f->x1;
	ty = y / f->zoom_y + f->y1;
	f->x1 = tx - f->coef;
	f->x2 = tx + f->coef;
	f->y1 = ty - f->coef;
	f->y2 = ty + f->coef;
	f->it -= 4;
	f->zoom_x = f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->img_y / (f->y2 - f->y1);
}

void		zoomout(t_mlx *f, int x, int y)
{
	double tx;
	double ty;

	tx = x / f->zoom_x + f->x1;
	ty = y / f->zoom_y + f->y1;
	f->x1 = tx - f->coef;
	f->x2 = tx + f->coef;
	f->y1 = ty - f->coef;
	f->y2 = ty + f->coef;
	f->it += 4;
	f->zoom_x = f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->img_y / (f->y2 - f->y1);
}

void		zoom(int but, int x, int y, t_mlx *f)
{
	if (but == 5 || but == 24)
	{
		f->coef /= 0.25;
		zoomin(f, x, y);
	}
	else
	{
		f->coef *= 0.25;
		zoomout(f, x, y);
	}
}
