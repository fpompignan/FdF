/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fassier- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:15:12 by fassier-          #+#    #+#             */
/*   Updated: 2022/02/07 17:26:33 by fassier-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <unistd.h>	
# include <stdlib.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**matrice;
	int		zoom;
	int		shift_x;
	int		shift_y;
	int		color;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_fdf;

void	ft_putstr(char *str);
void	ft_putchar(char c);
int		ft_strlen(char *str);
char	*get_next_line(int fd);
char	*ft_read_and_save(int fd, char *save);
char	*ft_save(char *save);
char	*ft_get_line(char *save);
char	*ft_strchr(char *s, char c);
char	*ft_strjoin(char *s1, char *s2);
int		get_height(char *filename, int *width);
int		count_element(char *str);
int		char_is_separator(char c, char *charset);
int		count_words(char *str, char *charset);
void	write_word(char *dest, char *from, char *charset);
void	write_split(char **split, char *str, char *charset);
char	**ft_split(char *str, char *charset);
int		ft_atoi(char *str);
int		**fill_matrix(int width, int height, char **argv);
int		**creation_matrice(int width, int height);
int		*transform_alpha_to_num(char **tab_alpha, int *tab_num, int width);
void	bresenham_h(float x, float y, int z, t_fdf map);
void	bresenham_v(float x, float y, int z, t_fdf map);
void	draw(t_fdf map);
void	isometric(float *x, float *y, int z);
void	ft_shift(float *x, float *y, t_fdf map);
void	ft_zoom(float *x, float *y, t_fdf map);
void	new_step(float *x_step, float *y_step);
void	put_color(int z, t_fdf *map);
t_fdf	initialisation_map(char **argv);

#endif
