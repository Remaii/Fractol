/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 16:34:53 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/26 16:28:11 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"


void		display(t_mlx *f)
{
	mlx_string_put(f->mlx, f->win, 5, 1, BLANC, "Fractal :");
	mlx_string_put(f->mlx, f->win, 100, 1, BLANC, f->name);
	if (ft_strcmp(f->name, "Julia") == 0)
		mlx_string_put(f->mlx, f->win, 160, 1, BLANC, ft_itoa(FF(julia)));
	mlx_string_put(f->mlx, f->win, 5, 26, BLANC, "Iterate (</>):");
	mlx_string_put(f->mlx, f->win, 160, 26, BLANC, ft_itoa(FF(it)));
	mlx_string_put(f->mlx, f->win, 5, 46, BLANC, "Zoom (-/+):");
	mlx_string_put(f->mlx, f->win, 130, 46, BLANC, ft_itoa(FF(zoom)));
	mlx_string_put(f->mlx, f->win, 5, 66, BLANC, "Rouge (E-/R+):");
	mlx_string_put(f->mlx, f->win, 160, 66, BLANC, ft_itoa(FF(r)));
	mlx_string_put(f->mlx, f->win, 5, 86, BLANC, "Vert (F-/G+):");
	mlx_string_put(f->mlx, f->win, 160, 86, BLANC, ft_itoa(FF(g)));
	mlx_string_put(f->mlx, f->win, 5, 106, BLANC, "Bleu (V-/B+):");
	mlx_string_put(f->mlx, f->win, 160, 106, BLANC, ft_itoa(FF(b)));
}
