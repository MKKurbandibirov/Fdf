/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 09:48:49 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/01/25 15:15:22 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	int	i;

	i = (y * img->line_length + x * (img->bits_per_pixel / 8));
	img->addr[i] = color;
	img->addr[++i] = color >> 8;
	img->addr[++i] = color >> 16;
}

void	draw_line(t_line l, t_fdf *fdf, t_img *img)
{
	float	x_step;
	float	y_step;
	int		max;

	l.z1 = (int)fdf->weight[(int)l.y1][(int)l.x1] * fdf->flatten_rate;
	l.z2 = (int)fdf->weight[(int)l.y2][(int)l.x2] * fdf->flatten_rate;
	fdf->color = get_color(l.z1, l.z2);
	point_settings(&l.x1, &l.y1, &l.z1, fdf);
	point_settings(&l.x2, &l.y2, &l.z2, fdf);
	x_step = l.x2 - l.x1;
	y_step = l.y2 - l.y1;
	max = ft_max(ft_abs(x_step), ft_abs(y_step));
	x_step /= max;
	y_step /= max;
	while ((int)(l.x1 - l.x2) || (int)(l.y1 - l.y2))
	{
		if (l.x1 >= 0 && l.x1 < WIN_WIDTH && l.y1 >= 0
			&& l.y1 < WIN_HEIGHT - MENU_HEIGHT)
			my_mlx_pixel_put(img, l.x1, l.y1, fdf->color);
		l.x1 += x_step;
		l.y1 += y_step;
	}
}

void	draw_background(t_fdf *fdf, t_img *img)
{
	int	x;
	int	y;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			if (y > WIN_HEIGHT - MENU_HEIGHT)
				my_mlx_pixel_put(img, x, y, 0x5b5b5b);
			else
				my_mlx_pixel_put(img, x, y, 0x808080);
			x++;
		}
		y++;
	}
}

void	draw_menu(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 890, 0xffffff,
		"Move: Right/Left/Up/Down arrow");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 910, 0xffffff,
		"Rotate axis: x(A/D), y(W/S), z(Q/E)");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 930, 0xffffff,
		"Zoom: -/+");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 950, 0xffffff,
		"Change flatten rate: </>");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 10, 970, 0xffffff,
		"Change projection: I/P");
}

void	draw(t_fdf *fdf, t_img *img)
{
	t_line	l;

	ft_bzero(img->addr, WIN_HEIGHT * WIN_WIDTH * (img->bits_per_pixel / 8));
	draw_background(fdf, img);
	l.y1 = 0;
	while (l.y1 < fdf->height)
	{
		l.x1 = 0;
		while (l.x1 < fdf->width)
		{
			l.x2 = l.x1 + 1;
			l.y2 = l.y1;
			if (l.x1 < fdf->width - 1)
				draw_line(l, fdf, img);
			l.x2 = l.x1;
			l.y2 = l.y1 + 1;
			if (l.y1 < fdf->height - 1)
				draw_line(l, fdf, img);
			(l.x1) += 1;
		}
		(l.y1) += 1;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, img->img_ptr, 0, 0);
	draw_menu(fdf);
}
