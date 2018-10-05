/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 13:03:11 by okuznets          #+#    #+#             */
/*   Updated: 2018/09/28 17:35:11 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

t_point		rotate(t_point p, t_plane plane)
{
	t_point	res;
	t_point	c;
	double	angle;

	c = plane.center;
	angle = plane.angle;
	res.x = c.x + (p.x - c.x) * cos(angle) + (c.y - p.y) * sin(angle);
	res.y = c.y + (p.x - c.x) * sin(angle) + (p.y - c.y) * cos(angle);
	res.z = p.z;
	return (res);
}
