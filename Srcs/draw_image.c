/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 12:17:08 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/08 15:09:34 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "stdlib.h"

t_point	*get_vertical(size_t i, size_t j, int ***map, t_plane plane)
{
	t_point start;
	t_point end;
	t_point *res;

	start.x = j * plane.zoom;
	start.y = i * plane.zoom;
	start.z = *(map[i][j]);
	if (map[i + 1] && map[i + 1][j])
	{
		end.x = j * plane.zoom;
		end.y = (i + 1) * plane.zoom;
		end.z = *(map[i + 1][j]);
		res = (t_point*)malloc(sizeof(*res) * 2);
		res[0] = count_projection(plane, start);
		res[0].x += plane.posx;
		res[0].y += plane.posy;
		res[1] = count_projection(plane, end);
		res[1].x += plane.posx;
		res[1].y += plane.posy;
		return (res);
	}
	return (NULL);
}

t_point	*get_horizontal(size_t i, size_t j, int ***map, t_plane plane)
{
	t_point start;
	t_point end;
	t_point *res;

	start.x = j * plane.zoom;
	start.y = i * plane.zoom;
	start.z = *(map[i][j]);
	if (map[i][j + 1])
	{
		end.x = (j + 1) * plane.zoom;
		end.y = i * plane.zoom;
		end.z = *(map[i][j + 1]);
		res = (t_point*)malloc(sizeof(*res) * 2);
		res[0] = count_projection(plane, start);
		res[0].x += plane.posx;
		res[0].y += plane.posy;
		res[1] = count_projection(plane, end);
		res[1].x += plane.posx;
		res[1].y += plane.posy;
		return (res);
	}
	return (NULL);
}

int		draw_image(int ***map, t_plane plane, t_image *image)
{
	size_t	i;
	size_t	j;
	t_point	*li;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if ((li = get_vertical(i, j, map, plane)))
			{
				line(li, image);
				free(li);
			}
			if ((li = get_horizontal(i, j, map, plane)))
			{
				line(li, image);
				free(li);
			}
			j++;
		}
		i++;
	}
	return (0);
}
