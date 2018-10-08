/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_angle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:32:43 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/08 15:33:03 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	angle_right(t_key_hook_param param)
{
	param.plane->angle += 0.1;
	draw_image((int***)param.plane->map, *param.plane, param.image);
	mlx_put_image_to_window(param.mlx->mlx_ptr,
	param.mlx->win_ptr, param.image->img_ptr, 0, 0);
}

void	angle_left(t_key_hook_param param)
{
	param.plane->angle -= 0.1;
	draw_image((int***)param.plane->map, *param.plane, param.image);
	mlx_put_image_to_window(param.mlx->mlx_ptr,
	param.mlx->win_ptr, param.image->img_ptr, 0, 0);
}
