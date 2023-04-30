/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:46:02 by fassier-          #+#    #+#             */
/*   Updated: 2022/02/07 18:02:06 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int	get_height(char *filename, int *width)
{
	int		fd;
	int		count;
	char	*lines;

	count = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("erreur d'ouverture du fichier\n");
		exit (1);
	}
	lines = get_next_line(fd);
	if (lines == NULL)
		return (0);
	*width = count_element(lines);
	while (lines)
	{
		count++;
		free(lines);
		lines = get_next_line(fd);
	}
	free(lines);
	close(fd);
	return (count);
}

int	**creation_matrice(int width, int height)
{
	int	**matrice;
	int	i;
	int	j;

	matrice = malloc (sizeof(int *) * height);
	if (!matrice)
		return (NULL);
	i = 0;
	while (i < height)
	{
		matrice[i] = malloc(sizeof(int) * width);
		if (!matrice[i])
		{
			j = 0;
			while (j < i)
			{
				free(matrice[j]);
				j++;
			}
			return (NULL);
		}
		i++;
	}
	return (matrice);
}

int	**fill_matrix(int width, int height, char **argv)
{
	int		**matrice;
	int		i;
	int		fd;
	char	*line;
	char	**tab_alphabet;

	matrice = creation_matrice(width, height);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1 || !matrice)
		return (NULL);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		tab_alphabet = ft_split(line, " ");
		if (tab_alphabet == NULL)
			return (NULL);
		matrice[i] = transform_alpha_to_num(tab_alphabet, matrice[i], width);
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (matrice);
}
