/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 11:53:26 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/20 20:13:46 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "OpenCL/opencl.h"
# include "../inc/libft.h"
# include "../inc/mlx.h"
# include <sys/stat.h>
# include <stdlib.h>
# include <stdio.h>

# define USAGE "./fractol Mandelbrot | Julia | Autre"
# define MIN 0
# define MAX 255
# define WIN_X 1024
# define WIN_Y 1024

# define DEBUG printf("%d - %s - %s\n", __LINE__, __func__, __FILE__);

typedef struct			s_comp
{
	double				r;
	double				i;
}						t_comp;

typedef struct			s_ocl
{
	cl_platform_id		platform;
	cl_program			program;
	cl_kernel			kernel;
	cl_device_id		device;
	cl_uint				num_dev;
	cl_context			context;
	cl_command_queue	cmd_queue;
	cl_int				i;
	cl_int				j;
	cl_int				err;
	cl_mem				out;
	char				*file;
	size_t				size;
	cl_context_properties	propreties[3];
	cl_uint				plat_num;
	size_t				global[3];
}						t_ocl;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				size;
	int				end;
	int				pos_x;
	int				pos_y;
	int				motion;
	char			*name;
	int				ocl;
	int				img_x;
	int				img_y;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	int				it;
	int				i;
	int				x;
	int				y;
	double			zoom_x;
	double			zoom_y;
	double			zr;
	double			zi;
	double			cr;
	double			ci;
	double			cr2;
	double			ci2;
	double			tmp;
	int				r;
	int				g;
	int				b;
	int				max[3];
	int				***map;
	double			mouse_x;
	double			mouse_y;
	int				julia;
}					t_mlx;

/*
** ocl.c
*/

void				set_arg(t_mlx *f);

/*
** mandelbrot.c
*/

void				mandelbrot(t_mlx *f);

/*
** buddhabrot.c
*/

void				buddhabrot(t_mlx *f);

/*
** julia.c
*/

void				julia(t_mlx *f);

/*
** ini_julia.c
*/

void 				set_julia1(t_mlx *f);
void 				set_julia2(t_mlx *f);
void 				set_julia3(t_mlx *f);
void 				set_julia4(t_mlx *f);
void 				set_julia5(t_mlx *f);

/*
** utilis.c
*/

void				make_point(t_mlx *f, int i, int it);
void				ft_stop(t_mlx *f);
void				error(int nb);

/*
** hook.c
*/

int					ft_key(int keycode, t_mlx *f);
int					ft_mouse(int but, int x, int y, t_mlx *f);
int					mouse_move(int x, int y, t_mlx *f);

/*
** zoom.c
*/

void				zoom(int but, int x, int y, t_mlx *f);

/*
** init_frac.c
*/

void				ini_mandelbrot(t_mlx *f);
void				ini_julia(t_mlx *f);
void				ini_buddha(t_mlx *f);
void				init_frac(t_mlx *f, int ac, char **av);
void				choose_julia(t_mlx *f);

/*
** init.c
*/

void				ini_img(t_mlx *f);
void				init_env(t_mlx *f);
void				re_init_frac(t_mlx *f);

/*
** main.c
*/

void				make_fractal(t_mlx *f);

#endif
