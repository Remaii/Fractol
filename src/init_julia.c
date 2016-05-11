/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:43:20 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/01 19:00:24 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		set_julia1(t_mlx *f)
{
	f->cr2 = -0.8;
	f->ci2 = 0;
	f->zoom_x = f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->img_y / (f->y2 - f->y1);
}

void		set_julia2(t_mlx *f)
{
	f->cr2 = -0.8;
	f->ci2 = 0.2;
	f->zoom_x = f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->img_y / (f->y2 - f->y1);
}

void		set_julia3(t_mlx *f)
{
	f->cr2 = 0.39;
	f->ci2 = 0.2;
	f->zoom_x = f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->img_y / (f->y2 - f->y1);
}

void		set_julia4(t_mlx *f)
{
	f->cr2 = 0.39;
	f->ci2 = 0.6;
	f->zoom_x = f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->img_y / (f->y2 - f->y1);
}

void		set_julia5(t_mlx *f)
{
	f->cr2 = -0.6;
	f->ci2 = 0.6;
	f->zoom_x = f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->img_y / (f->y2 - f->y1);
}
