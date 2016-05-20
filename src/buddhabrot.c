/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 14:13:32 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/20 19:21:11 by rthidet          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/fractol.h"
#include <math.h>
/*
void	set_color(int iter, int min, int max, int img)
{
	if (min == 0 && max == 1000 && iter < max && iter > min)
		img = 0x00FF0000;
	else if (min == 1001 && max == 5000 && iter > min && iter < max)
		img = 0x0000FF00;
	else if (min == 5001 && max == 10000 && iter > min && iter < max)
		img = 0x000000FF;
}*/
int		***initimg();

void	buddha(double x, double y, int **img, int i, t_mlx *f)
{
	int		iter;
	double tmp_x;
	double a;
	double b;
	int tx;
	int ty;

	a = x;
	b = y;
	iter = f->min[i];
	while (iter <= f->max[i] /*&& pow(x, 2) * pow(y, 2) < 0.5*/)
	{
		tmp_x = pow(x, 2) - pow(y, 2) + f->ci;
		y = 2 * x * y + f->cr;
		x = tmp_x;
		if (pow(x, 2) + pow(y, 2) < 4)
		{
			tx = (int)((x + 1.8) * 500) / 2.0;//x + position * zoom / 2
			ty = (int)((y + 1.7) * 500) / 2.0;// y + position * zoom / 2
			if (tx > 0 && tx < f->img_x && ty > 0 && ty < f->img_y)
			{
				if (iter > f->min[i] && iter < f->max[i])
					img[ty][tx] += i;
			}
		}
		iter++;
	}
}

void	test(t_mlx *f, double ci, double cr)
{
	int tx;
	int ty;
	int index;

	index = f->x * (f->bpp / 8) + f->y * f->size;
	if (pow(f->ci, 2) + pow(f->cr, 2) < 5)
	{
		tx = (int)((cr + 1.8) * 500) / 2.0;//x + position * zoom / 2
		ty = (int)((ci + 1.7) * 500) / 2.0;// y + position * zoom / 2
		if (tx > 0 && tx < f->img_x && ty > 0 && ty < f->img_y)
		{
			f->data[index] = 0;
			f->data[index + 1] = 0;
			f->data[index + 2] = 0;
		}
	}
	else
	{
		f->data[index] = f->b * (f->it + 1);
		f->data[index + 1] = f->g * (f->it + 2);
		f->data[index + 2] = f->r * (f->it + 3);
	}

}
void	draw(t_mlx *f)
{
	int i;
//	int tx;
//	int ty;
//	int index;
	int pr = 0;

	f->x = 0;
	while (f->x < f->img_x)
	{
		f->y = 0;
		while (f->y < f->img_y)
		{
			f->ci = ((double)(f->y * 3) / f->img_y) + f->y1;// - 2;
			f->cr = ((double)(f->x * (-3)) / f->img_x) + f->x1;// + 1.5;
			f->cr2 = f->cr;
			f->ci2 = f->ci;
			i = 0;
			while (i < 3)
			{
				f->it = f->min[i];
				while (f->it < f->max[i] && pow(f->cr, 2) * pow(f->ci, 2) < 2)
				{
//					buddha(f->ci, f->cr, f->map[i], i, f);
					f->tmp = pow(f->ci, 2) - pow(f->cr, 2) + f->ci2;
					f->cr = 2 * f->cr * f->ci + f->cr2;
					f->ci = f->tmp;
					test(f, f->ci, f->cr);/*
					if (pow(f->ci, 2) + pow(f->cr, 2) < 4)
					{
						tx = (int)((f->cr + 1.8) * 500) / 2.0;//x + position * zoom / 2
						ty = (int)((f->ci + 1.7) * 500) / 2.0;// y + position * zoom / 2
						if (tx > 0 && tx < f->img_x && ty > 0 && ty < f->img_y)
						{
							index = f->x * (f->bpp / 8) + f->y * f->size;
							f->data[index] = f->b * (i + 1);
							f->data[index + 1] = f->g * (i + 2);
							f->data[index + 2] = f->r * (i + 3);
						}
					}*/
					f->it++;
				}
				i++;
			}
			f->y++;
		}
		if (f->x * 100 / WIN_X != pr)
		{
			pr = f->x * 100 / WIN_X;
			printf("%d%%\n", pr);
		}
		f->x++;
	}
	printf("100%%\n");
}

int		ft_abs(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

void	color(t_mlx *f)
{
	int x;
	int y;
	int color[3];
	int val;

	y = 0;
	while (y < f->img_y)
	{
		x = 0;
		while (x < f->img_x)
		{
			val = x * (f->bpp / 8) + y * f->size;
			color[0] = ft_abs(f->map[0][x][y]);
			color[1] = ft_abs(f->map[1][x][y]);
			color[2] = ft_abs(f->map[2][x][y]);
			f->data[val] = color[1];
			f->data[val + 1] = color[2];
			f->data[val + 2] = color[0];
			x++;
		}
		y++;
	}
}

int		***initimg()
{
	int x;
	int y;
	int ***img;

	x = 0;
	img = (int ***)ft_memalloc(sizeof(int **) * 3);
	while (x < 3)
	{
		y = 0;
		img[x] = (int **)ft_memalloc(sizeof(int *) * WIN_X);
		while (y < WIN_X)
		{
			img[x][y] = (int *)ft_memalloc(sizeof(int *) * WIN_Y);
			y++;
		}
		x++;
	}
	return (img);
}

void buddhabrot(t_mlx *f)
{
	f->min[0] = 0;
	f->max[0] = 100;
	f->min[1] = 101;
	f->max[1] = 500;
	f->min[2] = 501;
	f->max[2] = 1000;
	f->map = initimg();
	draw(f);
//	color(f);
}
