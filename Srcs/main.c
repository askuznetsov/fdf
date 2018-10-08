/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/28 11:13:23 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/08 15:09:34 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "fdf.h"

int		error_argc(int nbr)
{
	if (nbr != 2)
	{
		ft_putstr("Error!\n");
		return (1);
	}
	return (0);
}

int		error_file(int nbr)
{
	if (nbr < 0)
	{
		ft_putstr("Wrong file!\n");
		return (1);
	}
	return (0);
}

int		error_map(char ***map)
{
	if (map == NULL)
	{
		ft_putstr("Wrong map!\n");
		return (1);
	}
	return (0);
}

int		plane_init(t_plane *plane, char ***map)
{
	int		centre_x;
	int		centre_y;

	centre_x = 0;
	while (map[0][centre_x])
		centre_x++;
	centre_x--;
	plane->center.x = (centre_x * 30) / 2;
	centre_y = 0;
	while (map[0][centre_y])
		centre_y++;
	centre_y--;
	plane->center.y = (centre_y * 30) / 2;
	plane->a = 0;
	plane->b = -1;
	plane->c = -1;
	plane->d = -40;
	plane->angle = 0.3;
	return (0);
}

int		main(int argc, char **argv)
{
	t_plane				plane;
	t_mlx				mlx;
	int					fd;
	t_image				image;
	t_key_hook_param	param;

	if (error_argc(argc))
		return (0);
	if (error_file(fd = open(argv[1], O_RDONLY)))
		return (0);
	plane.map = read_map(fd);
	if (error_map(plane.map))
		return (0);
	plane.zoom = 15;
	plane.posx = 150;
	plane.posy = 150;
	param.mlx = &mlx;
	param.plane = &plane;
	param.image = &image;
	plane_init(&plane, plane.map);
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, wdth, hght, "fdf");
	image = put_image(mlx.mlx_ptr);
	draw_image((int ***)plane.map, plane, &image);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, image.img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, 2, 5, &key_hook, &param);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
