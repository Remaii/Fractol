/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 12:44:07 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/14 13:31:44 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OpenCL/opencl.h"
#include "../inc/fractol.h"
#include <sys/stat.h>
#include <stdio.h>

typedef struct			s_ocl
{
	cl_platform_id		platform;
	cl_program			program;
	cl_kernel			kernel;
	cl_device_id		device;
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
	struct stat			statb;
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
/*	stat(filename, &statb);
	src = (char *)malloc(statb.st_size + 1);
	fread(src, statb.st_size, 1, fh);
	src[statb.st_size] = '\0';
	o->size = statb.st_size + 1;*/
	return (src);
}


int			ocl(t_mlx *f, t_ocl o)
{
	printf("debut ocl err = %d\n", o.err);
	clGetPlatformIDs(1, &o.platform, NULL);
	printf("Get platform err = %d\n", o.err);
	clGetDeviceIDs(o.platform, CL_DEVICE_TYPE_CPU, 1, &o.device, NULL);
	printf("get device err = %d\n", o.err);
	o.context = clCreateContext(NULL, 1, &o.device, NULL, NULL, &o.err);
	printf("create context err = %d\n", o.err);
	o.file = load_cl(f->name, &o);
	printf("load_cl err = %d file =\n%s\n", o.err, o.file);
	o.program = clCreateProgramWithSource(o.context, 1, (const char **)&o.file, &o.size, &o.err);
	printf("create program err = %d\n", o.err);
	clBuildProgram(o.program, 0, NULL, NULL, NULL, NULL);
	printf("Builde program err = %d\n", o.err);
	o.kernel = clCreateKernel(o.program, "mandel", &o.err);
	printf("create kernel err = %d\n", o.err);
	o.cmd_queue = clCreateCommandQueue(o.context, o.device, 0, &o.err);
	printf("cmd_queue err = %d\n", o.err);
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
