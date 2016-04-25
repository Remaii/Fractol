/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:56:38 by rthidet           #+#    #+#             */
/*   Updated: 2016/04/25 16:41:41 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		make_fractal(t_mlx *f)
{
	if (ft_strcmp(f->name, "Mandelbrot") == 0)
		mandelbrot(f);
	else if (ft_strcmp(f->name, "Julia") == 0)
		mandelbrot(f);
	else if (ft_strcmp(f->name, "Autre") == 0)
		printf("Autre\n");
	mlx_put_image_to_window(f->mlx, f->win, f->img, f->pos_x, f->pos_y);
}

int			main(int ac, char **av)
{
	t_mlx	f;

	init_frac(&f, ac, av);
	make_fractal(&f);
	mlx_key_hook(f.win, ft_key, &f);
	mlx_loop(f.mlx);
	return (0);
}
