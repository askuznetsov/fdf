/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_projection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 12:11:18 by okuznets          #+#    #+#             */
/*   Updated: 2018/09/28 17:03:35 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_point	count_projection(t_plane plane, t_point point)
{
	t_point	res;
	double	t;
	double	f;
	double	z;
	double	p;

	point = rotate(point, plane);
	f = pow(plane.a, 2) + pow(plane.b, 2) + pow(plane.c, 2);
	z = plane.a * point.x;
	p = plane.d - z - (plane.b * point.y) - (plane.c * point.z);
	t = p / f;
	res.x = point.x + plane.a * t;
	res.y = point.y + plane.b * t;
	res.z = point.z + plane.c * t;
	return (res);
}
