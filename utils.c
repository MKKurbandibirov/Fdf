/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 13:49:13 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/01/25 14:00:28 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_max(int a, int b)
{
	return ((a >= b) * a + (b > a) * b);
}

int	ft_abs(int a)
{
	return ((a >= 0) * a + (a < 0) * (-a));
}

void	ft_bzero(void *s, unsigned int n)
{
	char	*new;

	new = (char *)s;
	while (n > 0)
	{
		*new++ = '\0';
		n--;
	}
}

void	isometric(float *x, float *y, int z)
{
	*x = (*x - *y) * cos(0.523599);
	*y = (*x + *y) * sin(0.523599) - z;
}

void	point_settings(float *x, float *y, int *z, t_fdf *fdf)
{
	int	prev_y;
	int	prev_x;

	*x *= fdf->zoom;
	*y *= fdf->zoom;
	*z *= fdf->zoom * fdf->flatten_rate;
	*x -= fdf->width * fdf->zoom / 2;
	*y -= fdf->height * fdf->zoom / 2;
	prev_y = *y;
	*y = prev_y * cos(fdf->alpha) + *z * sin(fdf->alpha);
	*z = (-1) * prev_y * sin(fdf->alpha) + *z * cos(fdf->alpha);
	prev_x = *x;
	*x = prev_x * cos(fdf->beta) + *z * sin(fdf->beta);
	*z = (-1) * prev_x * sin(fdf->beta) + *z * cos(fdf->beta);
	prev_x = *x;
	*x = prev_x * cos(fdf->gamma) - *y * sin(fdf->gamma);
	*y = prev_x * sin(fdf->gamma) + *y * cos(fdf->gamma);
	if (fdf->projection == 'I')
		isometric(x, y, *z);
	*x += fdf->start_pos_x;
	*y += fdf->start_pos_y;
}
