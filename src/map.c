/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:09:58 by fassier-          #+#    #+#             */
/*   Updated: 2022/02/07 18:02:22 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos (0.8);
	*y = (*x + *y) * sin(0.8) - z;
}

void	ft_shift(float *x, float *y, t_fdf map)
{
	*x += map.shift_x;
	*y += map.shift_y;
}

void	ft_zoom(float *x, float *y, t_fdf map)
{
	*x = *x * map.zoom;
	*y = *y * map.zoom;
}

void	new_step(float *x_step, float *y_step)
{
	int	max;

	if (fabs(*x_step) > fabs(*y_step))
		max = fabs(*x_step);
	else
		max = fabs(*y_step);
	*x_step = *x_step / max;
	*y_step = *y_step / max;
}

void	put_color(int z, t_fdf *map)
{
	if (z > 0)
		map->color = 0xe80c0c;
	else if (z == 0)
		map->color = 0xffffff;
	else
		map->color = 0x00ff00;
}
