/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 12:17:51 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/17 19:01:56 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		make_point(t_mlx *f, int i, int it)
{
	int		index;

	index = f->x * (f->bpp / 8) + (f->y * f->size);
	if (i == it)
	{
		f->data[index] = 0;
		f->data[index + 1] = 0;
		f->data[index + 2] = 0;
	}
	else
	{
		f->data[index] = f->i * f->b / f->it;
		f->data[index + 1] = f->i * f->g / f->it;
		f->data[index + 2] = f->i * f->r / f->it;
	}
}

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
	exit(0);
}

void		ft_stop(t_mlx *f)
{
	mlx_destroy_image(f->mlx, f->img);
	mlx_destroy_window(f->mlx, f->win);
	ft_putendl("End Of Program");
	exit(0);
}
