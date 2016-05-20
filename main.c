/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/20 18:41:04 by rthidet           #+#    #+#             */
/*   Updated: 2016/05/20 18:46:48 by rthidet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <complex.h>
#include <stdio.h>

int		main()
{
	double complex x;
	double complex y;
	double xr;
	double xi;
	double yr;
	double yi;

	x = -2.1 + 0.6 * I;
	y = -1.2 + 1.2 * I;
	xr = creal(x);
	xi = cimag(x);
	yr = creal(y);
	yi = cimag(y);
	printf("xr = %4.1f xi = %4.1f yr = %4.1f yi = %4.1f\n", xr, xi, yr, yi);
	return (0);
}
