/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddha.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 19:21:26 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/20 20:54:41 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

#define NMAX 200
#define TMAX 1000

/*double	**init_map(t_mlx *f)
{
	int x;
	double **map;

	x = 0;
	map = (double **)ft_memalloc(sizeof(double) * f->it + 1);
	while (x < 100)
	{
		map[x] = (double *)ft_memalloc(sizeof(double) * 3);
		x++;
	}
	x = 0;
	while (x < 100)
	{
		map[x][0] = 6 * drand48() - 3;
		map[x][1] = 6 * drand48() - 3;

		printf("map[%d][0]=%4.1f map[%d][1]= %4.1f\n", x, map[x][0], x, map[x][1]);
		x++;
	}
	return (map);
}

void	buddha(t_mlx *f)
{
	double **map;
	int x;
	int y;

	map = init_map(f);
}*/

int	iterate(double x0, double y0, int *n, t_comp *seq)
{
	int i;
	double x, y, xnew, ynew;

	x = 0;
	y = 0;
	*n = 0;
	i = 0;
	while (i < NMAX)
	{
		xnew = x * x - y * y + x0;
		ynew = 2 * x * y + y0;
		seq[i].r = xnew;
		seq[i].i = ynew;
		if (xnew * xnew + ynew * ynew > 10)
		{
			*n = i;
			printf("1\n");
			return (1);
		}
		x = xnew;
		y = ynew;
		i++;
	}
	printf("0\n");
	return (0);
}

int	main()
{
	double x, y;
	int i, n, ix, iy, index;
	long t, tt;
	t_comp *xyseq;
	t_mlx f;

	f.r = 100;
	f.g = 0;
	f.b = 200;
	f.img_x = WIN_X;
	f.img_y = WIN_Y;
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, f.img_x, f.img_y, "test");
	f.img = mlx_new_image(f.win, f.img_x, f.img_y);
	f.data = mlx_get_data_addr(f.img, &f.bpp, &f.size, &f.end);

	if (!(xyseq = (t_comp *)ft_memalloc(NMAX * sizeof(t_comp))))
		return (0);
	tt = 0;
	while (tt < TMAX)
	{
		t = 0;
		while (t < TMAX)
		{
			x = 6 * drand48() - 3;
			y = 6 * drand48() - 3;
			if (iterate(x, y, &n, xyseq))
			{
		//		printf("trouver ! x = %4.1f y = %4.1f n = %d t= %ld tt= %ld\n", x, y, n, t, tt);
				while (i < n)
				{
					ix = 0.3 * f.img_x * (xyseq[i].r + 0.5) + f.img_x / 2;
					iy = 0.3 * f.img_y * (xyseq[i].i + f.img_y / 2);
					if (ix >= 0 && iy >= 0 && ix < f.img_x && iy < f.img_y)
					{
						printf("\t\t\t\t\t\t\tDESSIN!\tix = %d iy = %d\n", ix, iy);
						index = (int)ix * (f.bpp / 8) + (iy * f.size);
						f.data[index] = n * f.b;
						f.data[index + 1] = n * f.g;
						f.data[index + 2] = n * f.r;
					}
					i++;
				}
			}
			t++;
		}
		tt++;
	}
	mlx_put_image_to_window(f.mlx, f.win, f.img, 0, 0);
	mlx_loop(f.win);
//buddha(&f);
	return(0);
}
