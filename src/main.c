/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:56:38 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/22 00:29:56 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

void			choose_julia(t_mlx *f)
{
	if (f->julia == 1)
		set_julia1(f);
	else if (f->julia == 2)
		set_julia2(f);
	else if (f->julia == 3)
		set_julia3(f);
	else if (f->julia == 4)
		set_julia4(f);
	else if (f->julia == 5)
		set_julia5(f);
}

void		make_fractal(t_mlx *f)
{
	if (ft_strcmp(f->name, "Mandelbrot") == 0)
		mandelbrot(f);
	else if (ft_strcmp(f->name, "Julia") == 0)
		julia(f);
	else if (ft_strcmp(f->name, "Buddhabrot") == 0)
		buddhabrot(f);
	else if (f->ocl == 1)
		set_arg(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, f->pos_x, f->pos_y);
	mlx_string_put(f->mlx, f->win, 5, 1, 0x00FFFFFF, ft_itoa(f->it));
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
