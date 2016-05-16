/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 12:44:07 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/16 10:14:41 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OpenCL/opencl.h"
#include "../inc/libft.h"
#include "../inc/fractol.h"
#include <sys/stat.h>
#include <stdio.h>
#include <assert.h>

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
}						t_ocl;

int						hook(int key, t_mlx *f)
{
	if (key == 53)
	{
		mlx_destroy_image(f->mlx, f->img);
		mlx_destroy_window(f->mlx, f->win);
		exit(0);
	}
	else
		ft_putendl(ft_itoa(key));
	return (0);
}

char					*load_cl(const char *filename, t_ocl *o)
{
	FILE				*fh;
	char				*src;

	fh = fopen(filename, "r");
	if (fh == 0)
		return (0);
	fseek(fh, 0, SEEK_END);
	o->size = ftell(fh);
	rewind(fh);
	src = (char *)malloc(o->size + 1);
	src[o->size] = '\0';
	fread(src, sizeof(char), o->size, fh);
	fclose(fh);
	return (src);
}

void		notify(const char *err, const void *pri, size_t cb, void *user_data)
{
	printf("%s\n", err);
}

void		set_arg(t_ocl *o, t_mlx *f)
{
	printf("0set arg %d\n", o->err);
	clSetKernelArg(o->kernel, 0, sizeof(char *), &f->data);
	printf("1set arg %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 1, sizeof(int), &f->bpp);
	printf("2set arg %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 2, sizeof(int), &f->size);
	printf("3set arg %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 3, sizeof(int), &f->x);
	printf("4set arg %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 4, sizeof(int), &f->y);
	printf("5set arg %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 5, sizeof(double), &f->zoom_x);
	printf("6set arg %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 6, sizeof(double), &f->zoom_y);
	printf("7set arg %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 7, sizeof(double), &f->x1);
	printf("8set arg %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 8, sizeof(double), &f->y1);
	printf("9set arg %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 9, sizeof(double), &f->mouse_x);
	printf("10set arg %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 10, sizeof(double), &f->mouse_y);
	printf("11set arg %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 11, sizeof(int), &f->it);
	printf("final set arg %d\n", o->err);
}

int			ocl(t_mlx *f, t_ocl o)
{
	size_t gis = 4;
	size_t buff_size = sizeof(char) * 1024 * 1024 * 3;
	size_t lis = 1;
	printf("debut ocl err = %d\n", o.err);
	o.err = clGetPlatformIDs(1, &o.platform, NULL);
	printf("Get platform err = %d\n", o.err);
	o.err = clGetDeviceIDs(o.platform, CL_DEVICE_TYPE_ALL, 1, &o.device, &o.num_dev);
	printf("get device num_dev = %d err = %d\n", o.num_dev, o.err);
	o.context = clCreateContext(NULL, 1, &o.device, notify, NULL, &o.err);
	printf("create context err = %d\n", o.err);
	o.cmd_queue = clCreateCommandQueue(o.context, o.device, 0, &o.err);
	printf("cmd_queue size = %zu err = %d\n", o.size, o.err);
	o.file = load_cl(f->name, &o);
	printf("load_cl err = %d\n", o.err);
	o.program = clCreateProgramWithSource(o.context, 1, (const char **)&o.file, NULL, &o.err);
	printf("create program err = %d\n", o.err);
	o.err = clBuildProgram(o.program, 1, &o.device, NULL, NULL, &o.out);
	printf("Builde program err = %d\n", o.err);
	o.out = clCreateBuffer(o.context, CL_MEM_READ_WRITE, sizeof(int)*f->size, NULL, &o.err);
	printf("Create Buffer size = %d err = %d\n", f->size, o.err);
	o.kernel = clCreateKernel(o.program, "mandel", &o.err);
	printf("create kernel err = %d\n", o.err);
	set_arg(&o, f);
	o.err = clEnqueueNDRangeKernel(o.cmd_queue, o.kernel, 1, &gis, &lis, NULL, 0, NULL, NULL);
	o.err = clFinish(o.cmd_queue);
	return (0);
}

int		main()
{
	t_mlx f;
	t_ocl o;

	o.err = 0;
	f.name = "mandel1.cl";
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, 1024, 1024, "test");
	f.img = mlx_new_image(f.win, 1024, 1024);
	f.data = mlx_get_data_addr(f.img, &f.bpp, &f.size, &f.end);
	ocl(&f, o);
	printf("fin err = %d\n", o.err);
	mlx_key_hook(f.win, hook, &f);
	mlx_loop(f.mlx);
	return (0);
}
