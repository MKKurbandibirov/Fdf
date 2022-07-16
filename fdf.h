/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 10:29:13 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/01/25 15:16:31 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <mlx.h>
# include <math.h>

# define WIN_HEIGHT 1000
# define WIN_WIDTH 1000
# define MENU_HEIGHT 120

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_line
{
	float	x1;
	float	y1;
	int		z1;
	float	x2;
	float	y2;
	int		z2;
}	t_line;

typedef struct s_fdf
{
	int		width;
	int		height;
	int		**weight;
	void	*mlx_ptr;
	void	*win_ptr;
	int		zoom;
	int		start_pos_x;
	int		start_pos_y;
	float	flatten_rate;
	float	alpha;
	float	beta;
	float	gamma;
	char	projection;
	int		color;
	t_img	img;
}	t_fdf;

void	print_error(char *err_str);
int		count_words(char const *s, char c);
int		ft_atoi(const char *str);
char	**ft_split(char const *s, char c);

void	point_settings(float *x, float *y, int *z, t_fdf *fdf);
void	ft_bzero(void *s, unsigned int n);
int		ft_abs(int a);
int		ft_max(int a, int b);

void	read_map(t_fdf *fdf, char *filename);
void	draw(t_fdf *fdf, t_img *img);

void	zoom(int key, t_fdf *fdf);
void	move(int key, t_fdf *fdf);
void	flatten(int key, t_fdf *fdf);
void	rotate(int key, t_fdf *fdf);
void	projection(int key, t_fdf *fdf);

int		get_color(int z1, int z2);

#endif