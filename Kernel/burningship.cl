__kernel void fractal(__global char * data,
					int bpp,
					int size,
					double zoom_x,
					double zoom_y,
					double x1,
					double y1,
					double mouse_x,
					double mouse_y,
					int r,
					int g,
					int b,
					int it)
{
	int x;
	int y;
	int i;
	int index;
	double cr;
	double ci;
	double zr;
	double zi;
	double tmp;

	x = get_global_id(0);
	y = get_global_id(1);
	cr = x / zoom_x + x1;
	ci = y / zoom_y + y1;
	zr = 0 + mouse_x;
	zi = 0 + mouse_y;
	i = 0;
	while (zr * zr + zi * zi <= 4 && i < it)
	{
		tmp = zr;
		zr = fabs(zr * zr - zi * zi) + cr;
		zi = fabs(2 * zi * tmp) + ci;
		i++;
	}
	index = x * (bpp / 8) + (y * size);
	if (i == it)
	{
		data[index] = 0;
		data[index + 1] = 0;
		data[index + 2] = 0;
	}
	else
	{
		data[index] = b * i;
		data[index + 1] = g * i;
		data[index + 2] = r * i;
	}
}
