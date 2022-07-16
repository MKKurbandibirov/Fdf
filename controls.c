/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 14:05:00 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/01/25 14:08:57 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	zoom(int key, t_fdf *fdf)
{
	if (key == 24)
		fdf->zoom++;
	else if (key == 27 && fdf->zoom > 1)
		fdf->zoom--;
	draw(fdf, &fdf->img);
}

void	move(int key, t_fdf *fdf)
{
	if (key == 123)
		fdf->start_pos_x -= 3;
	else if (key == 124)
		fdf->start_pos_x += 3;
	else if (key == 125)
		fdf->start_pos_y += 3;
	else if (key == 126)
		fdf->start_pos_y -= 3;
	draw(fdf, &fdf->img);
}

void	flatten(int key, t_fdf *fdf)
{
	if (key == 43)
		fdf->flatten_rate *= 0.9;
	else if (key == 47)
		fdf->flatten_rate *= 1.1;
	draw(fdf, &fdf->img);
}

void	rotate(int key, t_fdf *fdf)
{
	if (key == 0)
		fdf->alpha -= M_PI / 36;
	else if (key == 2)
		fdf->alpha += M_PI / 36;
	else if (key == 1)
		fdf->beta -= M_PI / 36;
	else if (key == 13)
		fdf->beta += M_PI / 36;
	else if (key == 12)
		fdf->gamma -= M_PI / 36;
	else if (key == 14)
		fdf->gamma += M_PI / 36;
	draw(fdf, &fdf->img);
}

void	projection(int key, t_fdf *fdf)
{
	if (key == 34)
		fdf->projection = 'I';
	else if (key == 35)
	{
		fdf->alpha = 0;
		fdf->beta = 0;
		fdf->gamma = 0;
		fdf->projection = 'P';
	}
	draw(fdf, &fdf->img);
}
