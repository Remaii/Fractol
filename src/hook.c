/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 10:36:40 by rthidet           #+#    #+#             */
/*   Updated: 2016/04/26 17:12:25 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

/*
** 53 = ESC, 123 = fleche gauche, 124 = fleche droite, 125 = fleche haut,
** 126 = fleche bas, 13 = W, 1 = S, 12 = Q, 0 = A, 15 = R, 4 = H, 8 = C
** 5 = G, 11 = B
*/

void		move(t_mlx *f, int key)
{
	if (key == 123)
	{
		f->x1 -= 0.005;
		f->x2 -= 0.005;
	}
	else if (key == 124)
	{
		f->x1 += 0.005;
		f->x2 += 0.005;
	}
	else if (key == 126)
	{
		f->y1 -= 0.005;
		f->y2 -= 0.005;
	}
	else if (key == 125)
	{
		f->y1 += 0.005;
		f->y2 += 0.005;
	}
}

int			ft_key(int key, t_mlx *f)
{
	mlx_clear_window(f->mlx, f->win);
	if (key == 53)
		ft_stop(f);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		move(f, key);
	else if (key == 15)
		re_init_frac(f);
	else if (key == 8)
	{
		f->r = (rand() % (MAX - MIN + 1)) + MIN;
		f->g = (rand() % (MAX - MIN + 1)) + MIN;
		f->b = (rand() % (MAX - MIN + 1)) + MIN;
	}
	else if (key == 24 || key == 27)
		zoom(key, (f->img_x / 2), (f->img_y / 2), f);
	else
		ft_putendl(ft_itoa(key));
	//mlx_destroy_image(f->mlx, f->img);
	//f->img = mlx_new_image(f->mlx, f->img_x, f->img_y);
	make_fractal(f);
	return (0);
}

/*
** 1 = Clic gauche, 2 = Clic droit, 4 = molette avant, 5 = molette arriere
*/

int			mouse_move(int x, int y, t_mlx *f)
{
	if (x <= (int)f->img_x && y <= (int)f->img_y && f->motion == 1)
	{
		f->mouse_x = x * 0.0005;
		f->mouse_y = y * 0.0005;
		mlx_clear_window(f->mlx, f->win);
		make_fractal(f);
	}
	return (0);
}

int			ft_mouse(int but, int x, int y, t_mlx *f)
{
	if (but == 1)
	{
		if (f->motion == 0)
			f->motion = 1;
		else
			f->motion = 0;
	}
	else if (but == 2 && f->motion == 0)
	{
		f->mouse_x = x * 0.0005;
		f->mouse_y = y * 0.0005;
	}
	else if (but == 4 || but == 5)
		zoom(but, (f->img_x / 2), (f->img_y / 2), f);
//	mlx_destroy_image(f->mlx, f->img);
//	f->img = mlx_new_image(f->mlx, f->img_x, f->img_y);
	mlx_clear_window(f->mlx, f->win);
	make_fractal(f);
	return (0);
}
