/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ocl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/14 12:44:07 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/16 18:56:17 by rthidet          ###   ########.fr       */
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
	printf("1 err = %d\n", o->err);
	o->err = clGetPlatformIDs(1, &o->platform, &o->plat_num);
	printf("2 err = %d\n", o->err);
	o->err = clGetDeviceIDs(o->platform, CL_DEVICE_TYPE_GPU, 1, &o->device, &o->num_dev);
	printf("3 err = %d\n", o->err);
	o->propreties[0] = CL_CONTEXT_PLATFORM;
	o->propreties[1] = (cl_context_properties)o->platform;
	o->propreties[2] = 0;
	o->context = clCreateContext(o->propreties, o->num_dev, &o->device, notify, NULL, &o->err);
	printf("4 err = %d\n", o->err);
	o->file = load_cl(f->name, o);
	printf("5 err = %d\n", o->err);
	o->cmd_queue = clCreateCommandQueue(o->context, o->device, 0, &o->err);
	printf("6 err = %d\n", o->err);
	o->program = clCreateProgramWithSource(o->context, 1, (const char **)&o->file, NULL, &o->err);
	printf("7 err = %d\n", o->err);
	o->err = clBuildProgram(o->program, o->num_dev, &o->device, NULL, NULL, NULL);
	printf("8 err = %d\n", o->err);
	o->kernel = clCreateKernel(o->program, "mandel", &o->err);
	printf("9 err = %d\n", o->err);
	o->out = clCreateBuffer(o->context, CL_MEM_WRITE_ONLY, 1024 * f->size, NULL, &o->err);
	printf("10 err = %d\n", o->err);
	o->global[0] = WIN_X;
	o->global[1] = WIN_Y;
	o->global[2] = 0;
	printf("11 err = %d\n", o->err);
	return (o);
}

void		set_arg(t_mlx *f)
{
	static t_ocl		*o = NULL;

	if (o == NULL)
		o = ocl(f);
	printf("12 err = %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 0, sizeof(cl_mem), &o->out);
	printf("13 err = %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 1, sizeof(int), &f->bpp);
	printf("14 err = %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 2, sizeof(int), &f->size);
	printf("15 err = %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 3, sizeof(double), &f->zoom_x);
	printf("16 err = %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 4, sizeof(double), &f->zoom_y);
	printf("17 err = %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 5, sizeof(double), &f->x1);
	printf("18 err = %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 6, sizeof(double), &f->y1);
	printf("19 err = %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 7, sizeof(double), &f->mouse_x);
	printf("20 err = %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 8, sizeof(double), &f->mouse_y);
	printf("21 err = %d\n", o->err);
	o->err = clSetKernelArg(o->kernel, 9, sizeof(int), &f->it);
	printf("22 err = %d\n", o->err);
	o->err = clEnqueueNDRangeKernel(o->cmd_queue, o->kernel, 2, NULL, o->global,
			NULL, 0, NULL, NULL);
	printf("23 err = %d\n", o->err);
	o->err = clFinish(o->cmd_queue);
	printf("24 err = %d\n", o->err);
	o->err = clEnqueueReadBuffer(o->cmd_queue, o->out, CL_TRUE, 0,
			WIN_X * f->size, f->data, 0, NULL, NULL);
	printf("25 err = %d\n", o->err);
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
