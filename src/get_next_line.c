/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:25:42 by fassier-          #+#    #+#             */
/*   Updated: 2022/02/07 18:01:34 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

char	*ft_read_and_save(int fd, char *save)
{
	char	buf[42 + 1];
	int		ret;

	ret = 1;
	while (!ft_strchr(save, '\n') && ret != 0)
	{
		ret = read(fd, buf, 42);
		if (ret == -1)
			return (NULL);
		buf[ret] = '\0';
		save = ft_strjoin(save, buf);
	}
	return (save);
}

char	*ft_get_line(char *save)
{
	int		i;
	char	*result;

	if (save[0] == 0)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	result = malloc(sizeof(char) * (i + 2));
	if (!result)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		result[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
	{
		result[i] = save[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}	

char	*ft_save(char *save)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	while (save[i] != '\0' && save[i] != '\n')
		i++;
	if (save[i] == '\0')
	{
		free(save);
		return (NULL);
	}
	result = malloc(sizeof(char) * (ft_strlen(save) - i));
	if (result == NULL)
		return (NULL);
	i++;
	j = 0;
	while (save[i] != '\0')
		result[j++] = save[i++];
	result[j] = '\0';
	free(save);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || 42 <= 0)
		return (NULL);
	save = ft_read_and_save(fd, save);
	if (!save)
		return (NULL);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
/*
//-------------------------------------------------
#include <fcntl.h>
#include <stdio.h>

int main()
{
	int	fd;
	char *after;
	char *before;

	fd = open("./texte",O_RDONLY);
	before = ft_before(str);
	after = ft_after(str,2);
	printf("after : %s\n",after);
	printf("%d\n",ft_strlen(after));
	printf("before : %s\n",before);


	printf("%s",get_next_line(fd));
	printf("---------------------\n");
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));	
	printf("%s",get_next_line(fd));	
	printf("%s",get_next_line(fd));	
	printf("%s",get_next_line(fd));	
	printf("%s",get_next_line(fd));	
	return (0);
}*/
