/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 12:44:07 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/18 15:16:14 by rthidet          ###   ########.fr       */
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

void		notify(const char *err, const void *pri, size_t cb, void *user_data)
{
	pri = NULL;
	cb = 0;
	user_data = NULL;
	printf("%s\n", err);
}

t_ocl			*ocl(t_mlx *f)
{
	t_ocl	*o;

	o = ft_memalloc(sizeof(t_ocl));
	o->err = 0;
	o->err = clGetPlatformIDs(1, &o->platform, &o->plat_num);
	o->err = clGetDeviceIDs(o->platform, CL_DEVICE_TYPE_CPU, 1, &o->device,\
																&o->num_dev);
	o->propreties[0] = CL_CONTEXT_PLATFORM;
	o->propreties[1] = (cl_context_properties)o->platform;
	o->propreties[2] = 0;
	o->context = clCreateContext(o->propreties, o->num_dev, &o->device, notify,\
																NULL, &o->err);
	o->file = load_cl(f->name, o);
	o->cmd_queue = clCreateCommandQueue(o->context, o->device, 0, &o->err);
	o->program = clCreateProgramWithSource(o->context, 1,\
										(const char **)&o->file, NULL, &o->err);
	o->err = clBuildProgram(o->program, o->num_dev, &o->device, NULL, NULL,\
																		NULL);
	o->kernel = clCreateKernel(o->program, "mandel", &o->err);
	o->out = clCreateBuffer(o->context, CL_MEM_WRITE_ONLY, WIN_X * f->size,\
																NULL, &o->err);
	o->global[0] = WIN_X;
	o->global[1] = WIN_Y;
	o->global[2] = 0;
	return (o);
}

void		set_arg(t_mlx *f)
{
	static t_ocl		*o = NULL;

	if (o == NULL)
		o = ocl(f);
	o->err = clSetKernelArg(o->kernel, 0, sizeof(cl_mem), &o->out);
	o->err = clSetKernelArg(o->kernel, 1, sizeof(int), &f->bpp);
	o->err = clSetKernelArg(o->kernel, 2, sizeof(int), &f->size);
	o->err = clSetKernelArg(o->kernel, 3, sizeof(double), &f->zoom_x);
	o->err = clSetKernelArg(o->kernel, 4, sizeof(double), &f->zoom_y);
	o->err = clSetKernelArg(o->kernel, 5, sizeof(double), &f->x1);
	o->err = clSetKernelArg(o->kernel, 6, sizeof(double), &f->y1);
	o->err = clSetKernelArg(o->kernel, 7, sizeof(double), &f->mouse_x);
	o->err = clSetKernelArg(o->kernel, 8, sizeof(double), &f->mouse_y);
	o->err = clSetKernelArg(o->kernel, 9, sizeof(int), &f->r);
	o->err = clSetKernelArg(o->kernel, 10, sizeof(int), &f->g);
	o->err = clSetKernelArg(o->kernel, 11, sizeof(int), &f->b);
	o->err = clSetKernelArg(o->kernel, 12, sizeof(int), &f->it);
	o->err = clEnqueueNDRangeKernel(o->cmd_queue, o->kernel, 2, NULL, o->global,
			NULL, 0, NULL, NULL);
	o->err = clFinish(o->cmd_queue);
	o->err = clEnqueueReadBuffer(o->cmd_queue, o->out, CL_TRUE, 0,
			WIN_X * f->size, f->data, 0, NULL, NULL);
}
/*
int		main()
{
	t_mlx f;

	f.name = "mandel1.cl";
	f.mlx = mlx_init();
	f.win = mlx_new_window(f.mlx, WIN_X, WIN_Y, "test");
	f.img = mlx_new_image(f.win, WIN_X, WIN_Y);
	f.data = mlx_get_data_addr(f.img, &f.bpp, &f.size, &f.end);
	f.x = 0;
	f.y = 0;
	f.x1 = -2.1;
	f.y1 = -1.2;
	f.x2 = 0.6;
	f.y2 = 1.2;
	f.it = 50;
	f.mouse_x = 0;
	f.mouse_y = 0;
	f.img_x = WIN_X;
	f.img_y = WIN_Y;
	f.zoom_x = f.img_x / (f.x2 - f.x1);
	f.zoom_y = f.img_y / (f.y2 - f.y1);
	set_arg(&f);
	mlx_put_image_to_window(f.mlx, f.win, f.img, 0, 0);
	mlx_key_hook(f.win, hook, &f);
	mlx_loop(f.mlx);
	return (0);
}*/
