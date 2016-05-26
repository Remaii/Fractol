/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 13:24:31 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/26 20:57:05 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		zoomin(t_mlx *f, int x, int y)
{
	double tx;
	double ty;

	tx = x / FF(zoom_x) + FF(x1);
	ty = y / FF(zoom_y) + FF(y1);
	FF(x1) = tx - FF(coef);
	FF(x2) = tx + FF(coef);
	FF(y1) = ty - FF(coef);
	FF(y2) = ty + FF(coef);
	FF(it) -= 5;
	FF(zoom_x) = f->wid / (FF(x2) - FF(x1));
	FF(zoom_y) = f->hig / (FF(y2) - FF(y1));
}

void		zoomout(t_mlx *f, int x, int y)
{
	double tx;
	double ty;

	tx = x / FF(zoom_x) + FF(x1);
	ty = y / FF(zoom_y) + FF(y1);
	FF(x1) = tx - FF(coef);
	FF(x2) = tx + FF(coef);
	FF(y1) = ty - FF(coef);
	FF(y2) = ty + FF(coef);
	FF(it) += 5;
	FF(zoom_x) = f->wid / (FF(x2) - FF(x1));
	FF(zoom_y) = f->hig / (FF(y2) - FF(y1));
}

void		zoom(int but, int x, int y, t_mlx *f)
{
	if (but == 5 || but == 27)
	{
		FF(zoom)--;
		FF(coef) /= 0.50;
		zoomin(f, x, y);
	}
	else
	{
		FF(zoom)++;
		FF(coef) *= 0.50;
		zoomout(f, x, y);
	}
}
