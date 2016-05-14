__kernel void mandel(__global char *data,
					int bpp,
					int size,
					int it,
					int x,
					int y,
					double zoom_x,
					double zoom_y,
					double xx,
					double yy)
{
	int i;
	int index;
	double cr;
	double ci;
	double zr;
	double zi;
	double tmp;

	cr = x / zoom_x + xx;
	ci = y / zoom_y + yy;
	zr = 0 + mouse_x;
	zi = 0 + mouse_y;
	index = x * (bpp / 8) + (y * size);
	i = 0;
	while (zr*zr + zi*zi < 4 && i < it)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + cr;
		zi = 2 * zi * tmp + ci;
		if (i == it)
		{
			data[index] = 0;
			data[index + 1] = 0;
			data[index + 2] = 0;
		}
		else
		{
			data[index] = i * 256;
			data[index + 1] = i * 256 / it;
			data[index + 2] = i * 256 / it + 100;
		}
		i++;
	}
}
