/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 10:30:43 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/01/25 16:24:40 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#include <stdio.h>

void	print_error(char *err_str)
{
	write (2, err_str, ft_strlen(err_str));
	write (2, "\n", 1);
	exit (EXIT_FAILURE);
}

int	key_press(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(0);
	else if (key == 24 || key == 27)
		zoom(key, fdf);
	else if (key == 123 || key == 124 || key == 125 || key == 126)
		move(key, fdf);
	else if (key == 43 || key == 47)
		flatten(key, fdf);
	else if (key == 0 || key == 1 || key == 2
		|| key == 12 || key == 13 || key == 14)
		rotate(key, fdf);
	else if (key == 34 || key == 35)
		projection(key, fdf);
	return (1);
}

void	fdf_init(t_fdf *fdf)
{
	fdf->zoom = 20;
	fdf->start_pos_x = WIN_HEIGHT / 2 - fdf->height / 2;
	fdf->start_pos_y = WIN_WIDTH / 2 - fdf->width / 2;
	fdf->alpha = 0;
	fdf->beta = 0;
	fdf->gamma = 0;
	fdf->flatten_rate = 1;
	fdf->projection = 'I';
	fdf->mlx_ptr = mlx_init();
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_HEIGHT, WIN_WIDTH, "Fdf");
	fdf->img.img_ptr = mlx_new_image(fdf->mlx_ptr, WIN_HEIGHT, WIN_WIDTH);
	fdf->img.addr = mlx_get_data_addr(fdf->img.img_ptr,
			&fdf->img.bits_per_pixel, &fdf->img.line_length, &fdf->img.endian);
}

int	get_color(int z1, int z2)
{
	if ((z1 || z2) == 0 )
		return (0xffffff);
	else
		return (0xff0000);
}

int	main(int ac, char **av)
{
	t_fdf	fdf;
	int		i;

	if (ac == 2)
	{
		read_map(&fdf, av[1]);
		fdf_init(&fdf);
		draw(&fdf, &fdf.img);
		mlx_hook(fdf.win_ptr, 2, 0, key_press, &fdf);
		mlx_loop(fdf.mlx_ptr);
		i = -1;
		while (++i < fdf.height)
			free(fdf.weight[i]);
		free(fdf.weight);
	}
	else
		print_error("Error: wrong executable pattern!");
	return (0);
}
