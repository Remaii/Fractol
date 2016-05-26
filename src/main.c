/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:00:37 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/26 12:55:29 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

int			make_fractal(t_mlx *f)
{
	if (f->ocl == 1)
		set_arg(f);
	else if (ft_strcmp(f->name, "Mandelbrot") == 0)
		mandelbrot(f);
	else if (ft_strcmp(f->name, "Julia") == 0)
		julia(f);
	else if (ft_strcmp(f->name, "Burning-Ship") == 0)
		burningship(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	display(f);
	return (0);
}

int			main(int ac, char **av)
{
	t_mlx	f;

	init_frac(&f, ac, av);
	make_fractal(&f);
	mlx_hook(f.win, 2, 1, ft_key, &f);
	mlx_mouse_hook(f.win, ft_mouse, &f);
	mlx_hook(f.win, 6, (1L << 6), mouse_move, &f);
	mlx_loop(f.mlx);
	return (0);
}
