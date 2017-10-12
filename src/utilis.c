/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 12:17:51 by rthidet           #+#    #+#             */
/*   Updated: 2017/08/07 19:49:35 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		make_point(t_mlx *f, int i, int it)
{
	int		index;
	int blanc = 255;

	index = FF(x) * (f->bpp / 8) + (FF(y) * f->size);
	if (i == it)
	{
		f->data[index] = blanc;
		f->data[index + 1] = blanc;
		f->data[index + 2] = blanc;
	}
	else
	{
		f->data[index] = i * FF(b);
		f->data[index + 1] = i * FF(g);
		f->data[index + 2] = i * FF(r);
	}
}

void		error(int nb)
{
	if (nb == 1 || nb == 2)
		ft_putendl(USAGE);
	else
		ft_putnbr(nb);
	exit(0);
}

void		ft_stop(t_mlx *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	ft_putendl("End Of Program");
	exit(0);
}

void		choose_julia(t_mlx *f)
{
	if (FF(julia) == 1)
		set_julia1(f);
	else if (FF(julia) == 2)
		set_julia2(f);
	else if (FF(julia) == 3)
		set_julia3(f);
	else if (FF(julia) == 4)
		set_julia4(f);
	else if (FF(julia) == 5)
		set_julia5(f);
}
