/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: okuznets <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 17:14:18 by okuznets          #+#    #+#             */
/*   Updated: 2018/10/08 17:14:18 by okuznets         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
