/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 20:27:31 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/26 15:45:56 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		set_julia1(t_mlx *f)
{
	FF(mouse_x) = -0.8;
	FF(mouse_y) = 0.2;
	FF(zoom_x) = f->wid / (FF(x2) - FF(x1));
	FF(zoom_y) = f->hig / (FF(y2) - FF(y1));
}

void		set_julia2(t_mlx *f)
{
	FF(mouse_x) = -0.8;
	FF(mouse_y) = 0;
	FF(zoom_x) = f->wid / (FF(x2) - FF(x1));
	FF(zoom_y) = f->hig / (FF(y2) - FF(y1));
}

void		set_julia3(t_mlx *f)
{
	FF(mouse_x) = 0.39;
	FF(mouse_y) = 0.2;
	FF(zoom_x) = f->wid / (FF(x2) - FF(x1));
	FF(zoom_y) = f->hig / (FF(y2) - FF(y1));
}

void		set_julia4(t_mlx *f)
{
	FF(mouse_x) = 0.39;
	FF(mouse_y) = 0.6;
	FF(zoom_x) = f->wid / (FF(x2) - FF(x1));
	FF(zoom_y) = f->hig / (FF(y2) - FF(y1));
}

void		set_julia5(t_mlx *f)
{
	FF(mouse_x) = -0.6;
	FF(mouse_y) = 0.6;
	FF(zoom_x) = f->wid / (FF(x2) - FF(x1));
	FF(zoom_y) = f->hig / (FF(y2) - FF(y1));
}
