/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 19:51:06 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/14 02:08:48 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "OpenCL/opencl.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/sysctl.h>
#include <assert.h>

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				size;
	int				end;

	int				it;
	int				x;
	int				y;
	double			zoom_x;
	double			zoom_y;
	double			xx;
	double			yy;
}					t_mlx;

typedef struct			s_ocl
{
	cl_kernel			kernel;
	cl_command_queue	cmd_queue[16];
	cl_context			context;
	cl_platform_id		plat;
	cl_uint				num_plat;
	cl_device_id		*device;
	cl_uint				num_dev;
	cl_mem				output;
	cl_int				err;
}						t_ocl;

cl_context				create_context(t_ocl *o)
{
	cl_device_id		cpus[16];
	cl_uint				num_cpus;
	cl_context			context;

	o->device = malloc(16 * sizeof(cl_device_id));
	o->err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_CPU, 16, cpus, &num_cpus);
	printf("device %d\n", o->err);
	o->err = clGetDeviceIDs(NULL, CL_DEVICE_TYPE_GPU, 16, o->device, &o->num_dev);
	if (o->err != CL_SUCCESS || o->num_dev == 0)
	{
		o->device = cpus;
		o->num_dev = num_cpus;
	}
	context = clCreateContext(0, o->num_dev, o->device, NULL, NULL, &o->err);
	printf("context %d\n", o->err);
	return (context);
}

char					*load_cl(const char *filename)
{
	struct stat			statb;
	FILE				*fh;
	char				*src;

	fh = fopen(filename, "r");
	if (fh == 0)
		return (0);
	stat(filename, &statb);
	src = (char *)malloc(statb.st_size + 1);
	fread(src, statb.st_size, 1, fh);
	src[statb.st_size] = '\0';
	return (src);
}

cl_kernel				get_kernel(t_ocl *o, const char *filename)
{
	cl_kernel			kernel[1];
	cl_program			program[1];
	char				*source;

	source = load_cl(filename);
	program[0] = clCreateProgramWithSource(o->context, 1,
											(const char **)&source,
											NULL, &o->err);
	printf("program %d\n", o->err);
	o->err = clBuildProgram(program[0], 0, NULL, NULL, NULL, NULL);
	printf("build %d\n", o->err);
	kernel[0] = clCreateKernel(program[0], "render", &o->err);
	return (kernel[0]);
}

void					set_arg(t_ocl *o, t_mlx *f)
{
	printf("set kernel arg %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 0, sizeof(char *), &f->data);
	o->err = clSetKernelArg(o->kernel, 1, sizeof(int), &f->bpp);
	o->err = clSetKernelArg(o->kernel, 2, sizeof(int), &f->size);
	o->err = clSetKernelArg(o->kernel, 3, sizeof(int), &f->it);
	o->err = clSetKernelArg(o->kernel, 4, sizeof(int), &f->x);
	o->err = clSetKernelArg(o->kernel, 5, sizeof(int), &f->y);
	o->err = clSetKernelArg(o->kernel, 6, sizeof(int), &f->zoom_x);
	o->err = clSetKernelArg(o->kernel, 7, sizeof(int), &f->zoom_y);
	o->err = clSetKernelArg(o->kernel, 8, sizeof(int), &f->xx);
	o->err = clSetKernelArg(o->kernel, 8, sizeof(int), &f->yy);
	printf("kernel arg %d\n", o->err);
}

t_mlx					init_mlx()
{
	t_mlx f;

	printf("set mlx\n");
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, 1024, 1024, "test");
	f.img = mlx_new_image(f.win, 1024, 1024);
	f.data = mlx_get_data_addr(f.img, &f.bpp, &f.size, &f.end);
	printf("mlx is set \n");
	return (f);
}

int						main()
{
	const char *filename = "mandel.cl";
	t_ocl				o;
	size_t				ret_size;
	size_t				buff_size;
	char				*outimg;
	int					i;
	t_mlx				f;

	f = init_mlx();
	buff_size = sizeof(char) * 1024 * 1024 * 3;
	ret_size = 0;
	outimg = (char *)malloc(buff_size);
	o.context = create_context(&o);
	if (o.num_dev == 0)
		return (-1);
	while (i < o.num_dev)
	{
		o.cmd_queue[i] = clCreateCommandQueue(o.context, o.device[i], 0, &o.err);
		printf("cmd_queue %d\n", o.err);
		i++;
	}
	o.output = clCreateBuffer(o.context, CL_MEM_WRITE_ONLY, buff_size, NULL, &o.err);
	printf("output %d\n", o.err);
	o.kernel = get_kernel(&o, filename);
	printf("kernel %d\n", o.err);
	set_arg(&o, &f);
	mlx_loop(f.mlx);
	return (0);
}
