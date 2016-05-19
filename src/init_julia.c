/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:43:20 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/18 15:08:04 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		set_julia1(t_mlx *f)
{
	f->mouse_x = -0.8;
	f->mouse_y = 0;
	f->zoom_x = f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->img_y / (f->y2 - f->y1);
}

void		set_julia2(t_mlx *f)
{
	f->mouse_x = -0.8;
	f->mouse_y = 0.2;
	f->zoom_x = f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->img_y / (f->y2 - f->y1);
}

void		set_julia3(t_mlx *f)
{
	f->mouse_x = 0.39;
	f->mouse_y = 0.2;
	f->zoom_x = f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->img_y / (f->y2 - f->y1);
}

void		set_julia4(t_mlx *f)
{
	f->mouse_x = 0.39;
	f->mouse_y = 0.6;
	f->zoom_x = f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->img_y / (f->y2 - f->y1);
}

void		set_julia5(t_mlx *f)
{
	f->mouse_x = -0.6;
	f->mouse_y = 0.6;
	f->zoom_x = f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->img_y / (f->y2 - f->y1);
}
