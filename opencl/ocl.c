/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 12:44:07 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/14 19:58:37 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OpenCL/opencl.h"
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
	printf("test = %s\n", err);
}

void		set_arg(t_ocl *o, t_mlx *f)
{
	o->err = clSetKernelArg(o->kernel, 0, sizeof(char *), &f->data);
	o->err = clSetKernelArg(o->kernel, 1, sizeof(char *), &f->bpp);
	o->err = clSetKernelArg(o->kernel, 2, sizeof(int), &f->size);
	o->err = clSetKernelArg(o->kernel, 3, sizeof(int), &f->it);
	o->err = clSetKernelArg(o->kernel, 4, sizeof(int), &f->x);
	o->err = clSetKernelArg(o->kernel, 5, sizeof(int), &f->y);
	o->err = clSetKernelArg(o->kernel, 6, sizeof(double), &f->zoom_x);
	o->err = clSetKernelArg(o->kernel, 7, sizeof(double), &f->zoom_y);
	o->err = clSetKernelArg(o->kernel, 8, sizeof(double), &f->x1);
	o->err = clSetKernelArg(o->kernel, 9, sizeof(double), &f->y1);
	o->err = clSetKernelArg(o->kernel, 10, sizeof(int), &f->mouse_x);
	o->err = clSetKernelArg(o->kernel, 11, sizeof(int), &f->mouse_y);
	printf("final arg %d\n", o->err);
}

int			ocl(t_mlx *f, t_ocl o)
{
	size_t gis = 4;
	size_t lis = 1;
	printf("debut ocl err = %d\n", o.err);
	o.err = clGetPlatformIDs(1, &o.platform, NULL);
	printf("Get platform err = %d\n", o.err);
	o.err = clGetDeviceIDs(o.platform, CL_DEVICE_TYPE_ALL, 1, &o.device, &o.num_dev);
	printf("get device num_dev = %d err = %d\n", o.num_dev, o.err);
	o.context = clCreateContext(NULL, 1, &o.device, notify, NULL, &o.err);
	printf("create context err = %d\n", o.err);
	o.file = load_cl(f->name, &o);
	printf("load_cl err = %d\n", o.err);
	o.cmd_queue = clCreateCommandQueue(o.context, o.device, 0, &o.err);
	printf("cmd_queue size = %zu err = %d\n", o.size, o.err);
	o.program = clCreateProgramWithSource(o.context, 1, (const char **)&o.file, NULL, &o.err);
	printf("create program err = %d\n", o.err);
	o.err = clBuildProgram(o.program, 1, &o.device, NULL, NULL, &o.out);
	printf("Builde program err = %d\n", o.err);
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
	f.name = "mandel.cl";
	ocl(&f, o);
	printf("fin err = %d\n", o.err);
	return (0);
}
