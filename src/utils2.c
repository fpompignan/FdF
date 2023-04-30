/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 17:24:57 by fassier-          #+#    #+#             */
/*   Updated: 2022/02/07 18:01:13 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_fdf	initialisation_map(char **argv)
{
	t_fdf	map;

	map.zoom = 10;
	map.shift_x = 250;
	map.shift_y = 120;
	map.height = get_height(argv[1], &(map.width));
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
}
