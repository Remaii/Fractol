/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 13:43:20 by rthidet           #+#    #+#             */
/*   Updated: 2016/04/27 13:43:22 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void			set_julia1(t_mlx *f)
{
	f->cr2 = -0.6;
  f->ci2 = 0.6;
	f->zoom_x = f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->img_y / (f->y2 - f->y1);
}

void			set_julia2(t_mlx *f)
{
  f->cr2 = 0;
  f->ci2 = 0.8;
	f->zoom_x = f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->img_y / (f->y2 - f->y1);
}

void			set_julia3(t_mlx *f)
{
  f->cr2 = 0.59;
  f->ci2 = 0.2;
	f->zoom_x = f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->img_y / (f->y2 - f->y1);
}

void			set_julia4(t_mlx *f)
{
  f->cr2 = 0.39;
  f->ci2 = 0.4;
	f->zoom_x = f->img_x / (f->x2 - f->x1);
	f->zoom_y = f->img_y / (f->y2 - f->y1);
}

void choose_julia(t_mlx *f)
{
  if (f->julia == 1)
    set_julia1(f);
  else if (f->julia == 2)
    set_julia2(f);
  else if (f->julia == 3)
    set_julia3(f);
  else if (f->julia == 4)
    set_julia4(f);
}
