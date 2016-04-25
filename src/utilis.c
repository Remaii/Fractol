/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 12:17:51 by rthidet           #+#    #+#             */
/*   Updated: 2016/04/25 15:33:20 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		error(int nb)
{
	if (nb == 1 || nb == 2)
	{
		ft_putnbr(nb);
		ft_putendl(USAGE);
	}
	else if (nb == 3)
		ft_putendl("error 3");
	else
		ft_putnbr(nb);
	exit (0);
}

void		ft_stop(t_mlx *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	ft_putendl("End Of Program");
	exit(0);
}

/*
** 53 = ESC, 123 = fleche gauche, 124 = fleche droite, 125 = fleche haut,
** 126 = fleche bas, 13 = W, 1 = S, 12 = Q, 0 = A, 15 = R, 4 = H, 8 = C
** 5 = G, 11 = B
*/

void		move(t_mlx *f, int key)
{
	if (key == 124)
	{
		f->x1 -= 0.05;
		f->x2 -= -0.05;
	}
	else if (key == 123)
	{
		f->x1 += 0.05;
		f->x2 += 0.05;
	}
	else if (key == 125)
	{
		f->y1 -= 0.05;
		f->y2 -= 0.05;
	}
	else if (key == 126)
	{
		f->y1 += 0.05;
		f->y2 += 0.05;
	}
}

int			ft_key(int key, t_mlx *f)
{
	mlx_clear_window(f->mlx, f->win);
	if (key == 53)
		ft_stop(f);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		move(f, key);
	else if (key == 4)
	{
		f->r = (rand() % (MAX - MIN + 1)) + MIN;
		f->g = (rand() % (MAX - MIN + 1)) + MIN;
		f->b = (rand() % (MAX - MIN + 1)) + MIN;
	}
	else
		ft_putendl(ft_itoa(key));
	mlx_destroy_image(f->mlx, f->img);
	f->img = mlx_new_image(f->mlx, f->img_x, f->img_y);
	make_fractal(f);
	return (0);
}
