/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buddhabrot.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rthidet <rthidet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/29 14:13:32 by rthidet           #+#    #+#             */
/*   Updated: 2016/04/30 13:02:22 by rthidet          ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef buddhabrot
# define buddhabrot

# include "../inc/libft.h"
# include "../inc/mlx.h"
# include <stdio.h>

# define WINX 800
# define WINY 800

typedef struct		s_comp
{
	double		r;
	double		i;
}					t_comp;

typedef struct		s_it
{
	int				min[3];
	int				max[3];
}					t_it;

typedef struct		s_frac
{
	double			xpos;
	double			ypos;
	int				zoom;
}					t_frac;

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	int				i_set;
	void			*img;
	char			*data;
	int				bpp;
	int				size;
	int				end;
	int				pos_x;
	int				pos_y;
	int				***map;
	t_it			it;
	t_frac			frac;
}					t_mlx;


#endif

