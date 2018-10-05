/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 11:45:35 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/03 18:15:10 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#define	position 150
#define	zoom 15
#define wdth 800
#define hght 600

#include "libft.h"
#include "/usr/local/include/mlx.h"

typedef struct  s_image
{
	void 	*img_ptr;
	void	*img_data;
	int 	bts_pr_pxl;
	int 	sz_ln;
	int 	ndn;
}				t_image;

typedef struct	s_point
{
	double	x;
	double 	y;
	double  z;
}				t_point;

typedef	struct	s_plane
{
	int 	a;
	int 	b;
	int 	c;
	int 	d;
	double 	angle;
	t_point	center;
}				t_plane;

typedef	struct	s_mlx
{
	void *mlx_ptr;
	void *win_ptr;
}				t_mlx;

t_image		put_image(void *mlx_ptr);
int 		*image_point(t_image *image, int x, int y);
char		***read_map(int fd);
t_point 	count_projection(t_plane plane, t_point point);
void 		line(t_point *li, t_image *image);
int 		draw_image(int ***map, t_plane plane, t_image *image);
t_point		rotate(t_point point, t_plane plane);
#endif
