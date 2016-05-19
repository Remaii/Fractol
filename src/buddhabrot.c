/*  Copyright © 2011-2013 Henrique Dante de Almeida

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

/* buddhabrot: a very small but complete implementation of the Buddhabrot
   style rendering of Mandelbrot fractals. */

#include "../inc/fractol.h"
#include <complex.h>
#include <stdlib.h>
#include <string.h>

#define S 1024
static unsigned gray[S*S];

void buddhabrot(t_mlx *f)
{
	float epsilon = 4.0/S;
	const float factor=4.0f/((float)RAND_MAX+1.0f);
	float x, y;
	unsigned jx, jy;
	unsigned M = 1000;
	unsigned m = 100;
	unsigned R = 1500000;
	unsigned i, j, k;
	unsigned max;
	float complex z, c;

	for (k = 0; k < R; k++)
	{
		x = (float)rand()*factor-2.0f;
		y = (float)rand()*factor-2.0f;
		i = 0;
		c = x + y*I;
		z = 0;
		while ((crealf(z)*crealf(z)+cimagf(z)*cimagf(z)) < 4.0f && i < M)
		{
			z = z*z + c;
			i++;
		}
		if (i < M && i > m)
		{
			z = c;
			for (j = 0; j < i-1; j++)
			{
				jx = (crealf(z)+2.0f)/epsilon;
				jy = (cimagf(z)+2.0f)/epsilon;
				gray[jx*S+jy]++;
				z = z*z + c;
			}
		}
	}
	max = 0;
	for (i = 0; i < (unsigned int)f->size; i++) {
		if (gray[i] > max) max = gray[i];
	}
	for (i = 0; i < (unsigned int)f->size; i++)
	{
		f->data[3*i] = 255*gray[i]/max;
		f->data[3*i+1] = 255*gray[i]/max;
		f->data[3*i+2] = 255*gray[i]/max;
	}
}

