/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 13:56:22 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/17 18:38:29 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"
#include <math.h>

void		buddhabrot(t_mlx *f)
{
	mlx_string_put(f->mlx, f->win, f->img_x / 2, f->img_y / 2, 0x00FFFFFF, "LOOOOOOOOL");
	ft_stop(f);
}

