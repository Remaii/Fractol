/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:56:38 by rthidet           #+#    #+#             */
/*   Updated: 2016/04/26 17:45:24 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void		make_fractal(t_mlx *f)
{
	if (ft_strcmp(f->name, "Mandelbrot") == 0)
		mandelbrot(f);
	else if (ft_strcmp(f->name, "Julia") == 0)
		julia(f);
	else if (ft_strcmp(f->name, "Autre") == 0)
		buddhabrot(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, f->pos_x, f->pos_y);
}

int			main(int ac, char **av)
{
	t_mlx	f;

	init_frac(&f, ac, av[1]);
	make_fractal(&f);
	mlx_hook(f.win, 2, 1, ft_key, &f);
	mlx_mouse_hook(f.win, ft_mouse, &f);
	mlx_hook(f.win, 6, (1L << 6), mouse_move, &f);
	mlx_loop(f.mlx);
	return (0);
}
