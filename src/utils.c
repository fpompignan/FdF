/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 12:36:56 by fassier-          #+#    #+#             */
/*   Updated: 2022/02/07 18:01:01 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int	count_element(char *str)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] != ' ')
			count++;
		i++;
	}
	return (count + 1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	a;
	int	sign;

	a = 0;
	i = 0;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		a = 10 * a + (str[i] - 48);
		i++;
	}
	return (a * sign);
}

int	*transform_alpha_to_num(char **tab_alpha, int *tab_num, int width)
{
	int	i;

	i = 0;
	while (i < width)
	{
		tab_num[i] = ft_atoi(tab_alpha[i]);
		free(tab_alpha[i]);
		i++;
	}
	free (tab_alpha);
	return (tab_num);
}
