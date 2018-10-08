/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 14:19:32 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/08 15:34:51 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	to_left(t_key_hook_param param)
{
	param.plane->posx -= 10;
	draw_image((int***)param.plane->map, *param.plane, param.image);
	mlx_put_image_to_window(param.mlx->mlx_ptr,
	param.mlx->win_ptr, param.image->img_ptr, 0, 0);
}

void	to_right(t_key_hook_param param)
{
	param.plane->posx += 10;
	draw_image((int***)param.plane->map, *param.plane, param.image);
	mlx_put_image_to_window(param.mlx->mlx_ptr,
	param.mlx->win_ptr, param.image->img_ptr, 0, 0);
}

void	to_down(t_key_hook_param param)
{
	param.plane->posy += 10;
	draw_image((int***)param.plane->map, *param.plane, param.image);
	mlx_put_image_to_window(param.mlx->mlx_ptr,
	param.mlx->win_ptr, param.image->img_ptr, 0, 0);
}

void	to_up(t_key_hook_param param)
{
	param.plane->posy -= 10;
	draw_image((int***)param.plane->map, *param.plane, param.image);
	mlx_put_image_to_window(param.mlx->mlx_ptr,
	param.mlx->win_ptr, param.image->img_ptr, 0, 0);
}

int		key_hook(int key, t_key_hook_param *param)
{
	ft_memset(param->image->img_data, 0, param->image->sz_ln * hght);
	if (key == 123)
		to_left(*param);
	if (key == 124)
		to_right(*param);
	if (key == 125)
		to_down(*param);
	if (key == 126)
		to_up(*param);
	if (key == 78)
		zoom_down(*param);
	if (key == 69)
		zoom_up(*param);
	if (key == 83)
		angle_left(*param);
	if (key == 84)
		angle_right(*param);
	return (0);
}
