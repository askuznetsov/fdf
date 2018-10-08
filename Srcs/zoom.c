/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:29:17 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/08 15:31:59 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom_up(t_key_hook_param param)
{
	param.plane->zoom += 1;
	draw_image((int***)param.plane->map, *param.plane, param.image);
	mlx_put_image_to_window(param.mlx->mlx_ptr,
	param.mlx->win_ptr, param.image->img_ptr, 0, 0);
}

void	zoom_down(t_key_hook_param param)
{
	param.plane->zoom -= 1;
	draw_image((int***)param.plane->map, *param.plane, param.image);
	mlx_put_image_to_window(param.mlx->mlx_ptr,
	param.mlx->win_ptr, param.image->img_ptr, 0, 0);
}
