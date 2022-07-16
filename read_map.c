/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nfarfetc <nfarfetc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 10:45:33 by nfarfetc          #+#    #+#             */
/*   Updated: 2022/01/26 11:24:06 by nfarfetc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	get_height(char *filename)
{
	int		height;
	int		fd;
	char	*line;

	height = 0;
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error("Error: could not open the file!");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		height++;
		free(line);
	}
	close(fd);
	return (height);
}

int	get_width(char *filename)
{
	int		fd;
	char	*line;
	int		width;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error("Error: could not open the file!");
	line = get_next_line(fd);
	if (!line)
		print_error("Error: file is empty!");
	width = count_words(line, ' ');
	free(line);
	close(fd);
	return (width);
}

void	create_matrix(t_fdf *fdf, char *filename)
{
	int	i;

	fdf->width = get_width(filename);
	fdf->height = get_height(filename);
	fdf->weight = (int **)malloc(sizeof(int *) * (fdf->height));
	if (!fdf->weight)
		print_error("Error: malloc error!");
	i = -1;
	while (++i < fdf->height)
	{
		fdf->weight[i] = malloc(sizeof(int) * (fdf->width));
		if (!fdf->weight[i])
			print_error("Error: malloc error!");
	}
}

void	fill_matrix(int *weigth_line, char *line)
{
	int		i;
	char	**nums;

	nums = ft_split(line, ' ');
	if (!nums)
		print_error("Error: split error!");
	i = 0;
	while (nums[i])
	{
		weigth_line[i] = ft_atoi(nums[i]);
		free(nums[i]);
		i++;
	}
	free(nums);
	nums = NULL;
}

void	read_map(t_fdf *fdf, char *filename)
{
	int		i;
	int		fd;
	char	*line;

	create_matrix(fdf, filename);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		print_error("Error: could not open the file!");
	i = -1;
	while (++i < fdf->height)
	{
		line = get_next_line(fd);
		fill_matrix(fdf->weight[i], line);
		free(line);
	}
}
