
/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 14:13:32 by rthidet           #+#    #+#             */
/*   Updated: 2016/04/29 14:13:32 by rthidet          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "../inc/buddhabrot.h"
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
//	int comp;
//	char div = 0;

	a = x;
	b = y;
//	printf("\tx= %f y= %f\n", x, y);
	iter = f->it.min[i];
	while (iter <= f->it.max[i] && pow(x, 2) * pow(y, 2) < 1)
	{
	//	printf("%d\n", iter);
		tmp_x = pow(x, 2) - pow(y, 2) + a;
		y = 2 * x * y + b;
		x = tmp_x;
		if (pow(x, 2) + pow(y, 2) < 4)
		{
			tx = (int)((x + f->frac.xpos) * f->frac.zoom) / 2.0;//x + position * zoom / 2
			ty = (int)((y + f->frac.ypos) * f->frac.zoom) / 2.0;// y + position * zoom / 2
			if (tx > 0 && tx < WINX && ty > 0 && ty < WINY)
			{
				if (iter > f->it.min[i] && iter < f->it.max[i])
					img[ty][tx] += i;
			}
		}
		iter++;
	}
}

void	draw(t_mlx *f)
{
	int h;
	int w;
	double imag;
	int i;
//	int pr = 0;

	h = 0;
	while (h < WINY)
	{
		imag = ((double)(h * (-3)) / WINY) + 1.5;
		w = 0;
		while (w < WINX)
		{
			i = 0;
			while (i < 3)
			{
				buddha(((double)(w * 3) / WINX) - 2, imag, f->map[i], i, f);
				i++;
			}
			w++;
		}
//		if (h * 100 / WINY != pr)
//		{
//			pr = h * 100 / WINY;
//			printf("%d%%\n", pr);
//		}
		h++;
	}
//	printf("100%%\n");
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
	while (y < WINY)
	{
		x = 0;
		while (x < WINX)
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

void	move(t_mlx *f, int k)
{
	if (k == 124)
		f->frac.ypos += 0.25;
	else if (k == 125)
		f->frac.xpos += 0.25;
	else if (k == 123)
		f->frac.ypos -= 0.25;
	else if (k == 126)
		f->frac.xpos -= 0.25;
}

void	init_img(t_mlx *f)
{
	if (f->img)
	{
		printf("Image set !\n");
		f->img = mlx_new_image(f->mlx, WINX, WINY);
		f->data = mlx_get_data_addr(f->img, &f->bpp, &f->size, &f->end);
	}
	else if (f->size > 1)
	{
		printf("Image destroy !\n");
		mlx_destroy_image(f->mlx, f->img);
		printf("Image re-set !\n");
		f->img = mlx_new_image(f->mlx, WINX, WINY);
		f->data = mlx_get_data_addr(f->img, &f->bpp, &f->size, &f->end);
	}
	free(f->map);
	f->map = initimg();
}

void		re_draw(t_mlx *f)
{
	mlx_destroy_image(f->mlx, f->img);
	init_img(f);
	draw(f);
	color(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
}

int		ft_key(int k, t_mlx *f)
{
	if (k == 53)
	{
		mlx_destroy_window(f->mlx, f->win);
		exit(0);
	}
	else if (k == 123 || k == 124 || k == 125 || k == 126)
		move(f, k);
	else if (k == 24)
		f->frac.zoom += 20;
	else if (k == 27)
		f->frac.zoom -= 20;
	else
		ft_putendl(ft_itoa(k));
	printf("x= %f y= %f\n", f->frac.xpos, f->frac.ypos);
	re_draw(f);
	return (0);
}

void	init_mlx(t_mlx *f)
{
	f->mlx = mlx_init();
	f->win = mlx_new_window(f->mlx, WINX, WINY, "Test: BuddhaBrot");
	f->size = 0;
	init_img(f);
	f->frac.xpos = 2.0;
	f->frac.ypos = 1.5;
	f->frac.zoom = 550;
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
		img[x] = (int **)ft_memalloc(sizeof(int *) * WINY);
		while (y < WINY)
		{
			img[x][y] = (int *)ft_memalloc(sizeof(int *) * WINX);
			y++;
		}
		x++;
	}
	return (img);
}

int main()
{
	t_mlx f;

	f.it.min[0] = 0;
	f.it.max[0] = 100;
	f.it.min[1] = 101;
	f.it.max[1] = 500;
	f.it.min[2] = 501;
	f.it.max[2] = 1000;
	f.i_set = 0;
	f.map = initimg();
	init_mlx(&f);
//	draw(img, &f);
//	color(&f, img);
//	mlx_expose_hook(f.mlx, re_draw, &f);
	mlx_key_hook(f.win, ft_key, &f);
	re_draw(&f);
	mlx_loop(f.mlx);
	return (0);
}
