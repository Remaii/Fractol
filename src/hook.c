/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 10:36:40 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/26 16:26:25 by rthidet          ###   ########.fr       */
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
	if (key == 124)
	{
		FF(x1) -= 0.05;
		FF(x2) -= 0.05;
	}
	else if (key == 123)
	{
		FF(x1) += 0.05;
		FF(x2) += 0.05;
	}
	else if (key == 125)
	{
		FF(y1) -= 0.05;
		FF(y2) -= 0.05;
	}
	else if (key == 126)
	{
		FF(y1) += 0.05;
		FF(y2) += 0.05;
	}
}
void		ft_color(int key, t_mlx *f)
{
	if (key == 8)
	{
		FF(r) = (rand() % (MAX - MIN + 1)) + MIN;
		FF(g) = (rand() % (MAX - MIN + 1)) + MIN;
		FF(b) = (rand() % (MAX - MIN + 1)) + MIN;
	}
	else if (key == 15)
		(FF(r) < MAX ? FF(r)++ : MAX);
	else if (key == 5)
		(FF(g) < MAX ? FF(g)++ : MAX);
	else if (key == 11)
		(FF(b) < MAX ? FF(b)++ : MAX);
	else if (key == 14)
		(FF(r) >= MIN ? FF(r)-- : MIN);
	else if (key == 3)
		(FF(g) >= MIN ? FF(g)-- : MIN);
	else if (key == 9)
		(FF(b) >= MIN ? FF(b)-- : MIN);
}

int			ft_key(int key, t_mlx *f)
{
	if (key == 53)
		ft_stop(f);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		move(f, key);
	else if (key == 31)
		re_init_frac(f);
	else if (key == 8 || key == 15 || key == 5 || key == 11 || key == 14 || \
			key == 3 || key == 9)
		ft_color(key, f);
	else if (key == 24 || key == 27)
		zoom(key, (f->wid / 2), (f->hig / 2), f);
	else if (key == 43)
		FF(it) -= 5;
	else if (key == 47)
		FF(it) += 5;
	else if (key == 38)
	{
		if (FF(julia) > 4)
			FF(julia) = 1;
		else
			FF(julia)++;
		choose_julia(f);
	}
	ini_img(f);
	make_fractal(f);
	return (0);
}

/*
** 1 = Clic gauche, 2 = Clic droit, 4 = molette avant, 5 = molette arriere
*/

int			mouse_move(int x, int y, t_mlx *f)
{
	if (x <= (int)f->wid && y <= (int)f->hig && f->motion == 1)
	{
		FF(mouse_x) = ((double)x - 500) / 500;
		FF(mouse_y) = ((double)y - 500) / 500;
		ini_img(f);
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
		FF(mouse_x) = ((double)x - 500) / 500;
		FF(mouse_y) = ((double)y - 500) / 500;
	}
	else if (but == 4 || but == 5)
		zoom(but, x, y, f);
	ini_img(f);
	make_fractal(f);
	return (0);
}
