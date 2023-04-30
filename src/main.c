/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 16:21:19 by fassier-          #+#    #+#             */
/*   Updated: 2022/02/07 18:00:34 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	bresenham_h(float x, float y, int z, t_fdf map)
{
	float	x1;
	float	y1;
	float	x_step;
	float	y_step;
	int		z1;

	x1 = x + 1;
	y1 = y;
	z1 = map.matrice[(int)y1][(int)x1];
	ft_zoom(&x, &y, map);
	ft_zoom(&x1, &y1, map);
	put_color(z, &map);
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	ft_shift(&x, &y, map);
	ft_shift(&x1, &y1, map);
	x_step = x1 - x;
	y_step = y1 - y;
	new_step(&x_step, &y_step);
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(map.mlx_ptr, map.win_ptr, x, y, map.color);
		x = x + x_step;
		y = y + y_step;
	}
}

void	bresenham_v(float x, float y, int z, t_fdf map)
{
	float	x1;
	float	y1;
	float	x_step;
	float	y_step;
	int		z1;

	x1 = x;
	y1 = y + 1;
	z1 = map.matrice[(int)y1][(int)x1];
	ft_zoom(&x, &y, map);
	ft_zoom(&x1, &y1, map);
	put_color(z, &map);
	isometric(&x, &y, z);
	isometric(&x1, &y1, z1);
	ft_shift(&x, &y, map);
	ft_shift(&x1, &y1, map);
	x_step = x1 - x;
	y_step = y1 - y;
	new_step(&x_step, &y_step);
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(map.mlx_ptr, map.win_ptr, x, y, map.color);
		x = x + x_step;
		y = y + y_step;
	}
}

void	draw(t_fdf map)
{
	int	x;
	int	y;
	int	z;

	y = 0;
	while (y < map.height)
	{
		x = 0;
		while (x < map.width)
		{
			z = map.matrice[(int)y][(int)x];
			if (x < map.width - 1)
				bresenham_h(x, y, z, map);
			if (y < map.height - 1)
				bresenham_v(x, y, z, map);
			x = x + 1;
		}
		y = y + 1;
	}
}

int	ft_close(int key, t_fdf *map)
{
	if (key == 53)
	{
		mlx_destroy_window (map->mlx_ptr, map->win_ptr);
		exit(1);
	}
	return (0);
}

/*t_fdf	initialisation_map(char **argv)
{
	t_fdf	map;

	map.zoom = 10;
	map.shift_x = 250;
	map.shift_y = 120;
	map.height = get_height(argv[1],  &(map.width));
	if (!map.height || !map.width)
	{
		ft_putstr("fichier vide \n");
		exit(1);
	}
	map.matrice = fill_matrix(map.width, map.height, argv);
	if (!map.matrice)
	{
		ft_putstr("erreur de malloc ou d'ouvertur de fichier\n");
		exit (1);
	}
	return (map);
}*/

int	main(int argc, char **argv)
{
	t_fdf	map;

	if (argc != 2)
		return (0);
	map = initialisation_map(argv);
	map.mlx_ptr = mlx_init();
	if (map.mlx_ptr == NULL)
		return (1);
	map.win_ptr = mlx_new_window(map.mlx_ptr, 1000, 1000, "FDF");
	if (map.win_ptr == NULL)
		return (1);
	draw(map);
	mlx_key_hook(map.win_ptr, ft_close, &map);
	mlx_loop(map.mlx_ptr);
	return (0);
}
