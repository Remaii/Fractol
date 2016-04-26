/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilis.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 12:17:51 by rthidet           #+#    #+#             */
/*   Updated: 2016/04/26 10:38:08 by rthidet          ###   ########.fr       */
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
