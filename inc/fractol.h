/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/11 18:06:39 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/26 12:47:21 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# define USAGE "./fractol (Mandelbrot | Julia | Mini_bouddha)"
# define WID 1000
# define HIG 1000
# define MAX 400
# define MIN 1
# define FF(x) f->f->x
# define BLANC 0xfdfdfd

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "OpenCL/opencl.h"
# include <sys/stat.h>
# include <stdio.h>

# define DEBUG printf("%d - %s - %s\n", __LINE__, __func__, __FILE__);

typedef struct				s_ocl
{
	cl_platform_id			platform;
	cl_program				program;
	cl_kernel				kernel;
	cl_device_id			device;
	cl_uint					num_dev;
	cl_context				context;
	cl_command_queue		cmd_queue;
	cl_int					i;
	cl_int					j;
	cl_int					err;
	cl_mem					out;
	char					*file;
	size_t					size;
	cl_context_properties	propreties[3];
	cl_uint					plat_num;
	size_t					global[3];
}							t_ocl;

typedef struct				s_comp
{
	double					r;
	double					i;
}							t_comp;

typedef struct				s_fra
{
	int						i;
	int						it;
	int						x;
	int						y;
	int						r;
	int						g;
	int						b;
	int						julia;
	int						zoom;
	double					mouse_x;
	double					mouse_y;
	double					x1;
	double					x2;
	double					y1;
	double					y2;
	double					coef;
	double					zoom_x;
	double					zoom_y;
	double					tmp;
	t_comp					z;
	t_comp					c;
	t_comp					c2;
}							t_fra;

typedef struct				s_mlx
{
	void					*mlx;
	void					*win;
	char					*name;
	char					*path;
	int						type;
	int						ocl;
	int						crt_img;
	void					*img;
	char					*data;
	int						bpp;
	int						size;
	int						end;
	int						wid;
	int						hig;
	int						motion;
	t_fra					*f;
}							t_mlx;

/*
** main.c
*/

int							make_fractal(t_mlx *f);

/*
** mandelbrot.c
*/

void						mandelbrot(t_mlx *f);

/*
** julia.c
*/

void						julia(t_mlx *f);

/*
** buddhabrot.c
*/

void						burningship(t_mlx *f);

/*
** init_fractal.c
*/

void						ini_julia(t_mlx *f);
void						ini_mandelbrot(t_mlx *f);
void						ini_burning(t_mlx *f);
void						init_frac(t_mlx *f, int ac, char **av);

/*
** init_julia.c
*/

void						set_julia1(t_mlx *f);
void						set_julia2(t_mlx *f);
void						set_julia3(t_mlx *f);
void						set_julia4(t_mlx *f);
void						set_julia5(t_mlx *f);

/*
** init.c
*/

void						ini_img(t_mlx *f);
void						init_env(t_mlx *f);
void						re_init_frac(t_mlx *f);

/*
** ocl.c
*/

void						set_arg(t_mlx *f);

/*
** utilis.c
*/

void						make_point(t_mlx *f, int i, int it);
void						choose_julia(t_mlx *f);
void						ft_stop(t_mlx *f);
void						error(int nb);

/*
** zoom.c
*/

void						zoom(int but, int x, int y, t_mlx *f);

/*
** hook.c
*/

int							ft_key(int key, t_mlx *f);
int							mouse_move(int x, int y, t_mlx *f);
int							ft_mouse(int but, int x, int y, t_mlx *f);

/*
** display.c
*/

void						display(t_mlx *f);

#endif
