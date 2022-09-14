/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenhem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 17:54:50 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/09 16:25:33 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdlib.h>
#include <fdf.h>

void	vertical_line(t_point start, t_point end, t_image *image)
{
	double	coeff;
	double	x;
	int		y;

	if (start.x == end.x)
		*image_point(image, start.x, start.y) = 0xFFFFFF;
	coeff = (end.x - start.x) / (end.y - start.y);
	y = start.y;
	x = start.x;
	while (y < end.y)
	{
		if (x >= 0 && x < 800 && y >= 0 && y < 600)
			*image_point(image, (int)floor(x), y) = 0xFFFFFF;
		y++;
		x += coeff;
	}
}

void	horizontal_line(t_point s, t_point e, t_image *image)
{
	double	coeff;
	int		x;
	double	y;

	if (s.x == e.x)
		*image_point(image, s.x, s.y) = 0xFFFFFF;
	coeff = (double)(e.y - s.y) / (e.x - s.x);
	y = s.y;
	x = s.x;
	while (x < e.x)
	{
		if (x >= 0 && x < 800 && y >= 0 && y < 600)
			*image_point(image, x, (int)floor(y)) = 0xFFFFFF;
		x++;
		y += coeff;
	}
}

void	line(t_point *li, t_image *image)
{
	int		lengthx;
	int		lengthy;
	t_point	start;
	t_point	end;

	start = li[0];
	end = li[1];
	lengthx = (li[1].x - li[0].x);
	lengthy = (li[1].y - li[0].y);
	if (abs(lengthx) > abs(lengthy))
	{
		if (lengthx > 0)
			horizontal_line(start, end, image);
		else
			horizontal_line(end, start, image);
	}
	else
	{
		if (lengthy > 0)
			vertical_line(start, end, image);
		else
			vertical_line(end, start, image);
	}
}
