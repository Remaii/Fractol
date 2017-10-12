/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 12:44:07 by rthidet           #+#    #+#             */
/*   Updated: 2016/06/04 22:21:41 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fractol.h"

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
	src = (char *)ft_memalloc(o->size + 1);
	src[o->size] = '\0';
	fread(src, sizeof(char), o->size, fh);
	fclose(fh);
	return (src);
}

t_ocl					*ocl(t_mlx *f)
{
	t_ocl				*o;

	o = ft_memalloc(sizeof(t_ocl));
	o->err = 0;
	o->err = clGetPlatformIDs(1, &o->platform, &o->plat_num);
	o->err = clGetDeviceIDs(o->platform, CL_DEVICE_TYPE_CPU, 1, &o->device,\
																&o->num_dev);
	o->propreties[0] = CL_CONTEXT_PLATFORM;
	o->propreties[1] = (cl_context_properties)o->platform;
	o->propreties[2] = 0;
	o->context = clCreateContext(o->propreties, o->num_dev, &o->device, NULL,\
																NULL, &o->err);
	o->file = load_cl(f->path, o);
	o->cmd_queue = clCreateCommandQueue(o->context, o->device, 0, &o->err);
	o->program = clCreateProgramWithSource(o->context, 1,\
										(const char **)&o->file, NULL, &o->err);
	o->err = clBuildProgram(o->program, o->num_dev, &o->device, NULL, NULL,\
																		NULL);
	o->kernel = clCreateKernel(o->program, "fractal", &o->err);
	o->out = clCreateBuffer(o->context, CL_MEM_WRITE_ONLY, f->wid * f->size,\
																NULL, &o->err);
	o->global[0] = f->wid;
	o->global[1] = f->hig;
	o->global[2] = 0;
	return (o);
}

void					set_arg(t_mlx *f)
{
	static t_ocl		*o = NULL;

	if (o == NULL)
		o = ocl(f);
	o->err = clSetKernelArg(o->kernel, 0, sizeof(cl_mem), &o->out);
	o->err = clSetKernelArg(o->kernel, 1, sizeof(int), &f->bpp);
	o->err = clSetKernelArg(o->kernel, 2, sizeof(int), &f->size);
	o->err = clSetKernelArg(o->kernel, 3, sizeof(double), &FF(zoom_x));
	o->err = clSetKernelArg(o->kernel, 4, sizeof(double), &FF(zoom_y));
	o->err = clSetKernelArg(o->kernel, 5, sizeof(double), &FF(x1));
	o->err = clSetKernelArg(o->kernel, 6, sizeof(double), &FF(y1));
	o->err = clSetKernelArg(o->kernel, 7, sizeof(double), &FF(mouse_x));
	o->err = clSetKernelArg(o->kernel, 8, sizeof(double), &FF(mouse_y));
	o->err = clSetKernelArg(o->kernel, 9, sizeof(int), &FF(r));
	o->err = clSetKernelArg(o->kernel, 10, sizeof(int), &FF(g));
	o->err = clSetKernelArg(o->kernel, 11, sizeof(int), &FF(b));
	o->err = clSetKernelArg(o->kernel, 12, sizeof(int), &FF(it));
	o->err = clEnqueueNDRangeKernel(o->cmd_queue, o->kernel, 2, NULL, o->global,
			NULL, 0, NULL, NULL);
	o->err = clFinish(o->cmd_queue);
	o->err = clEnqueueReadBuffer(o->cmd_queue, o->out, CL_TRUE, 0,
									f->wid * f->size, f->data, 0, NULL, NULL);
}
