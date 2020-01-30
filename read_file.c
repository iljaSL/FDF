/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:05:14 by ismelich          #+#    #+#             */
/*   Updated: 2020/01/28 16:18:45 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** In "map_size" we determine the height and width of our map and store it
** in our structur "height" and "width".
*/

void		map_size(char *file, t_fdf *data)
{
	char	*line;
	int		fd;
	int		height;
	int		width;

	if ((fd = open(file, O_RDONLY)) < 0)
	{
		error("Invalid Map");
	}
	height = 0;
	while (get_next_line(fd, &line) > 0)
	{
		height++;
		width = ft_words_counter(line);
		free(line);
	}
	if (close(fd) == -1)
	{
		error("File can not be closed");
	}
	data->height = height;
	data->width = width;
}

/*
** In "malloc_z" we allocate the 2D table full with ints,
** inside our "map" structur.
*/

void		malloc_z(char *file, t_fdf *data)
{
	int		**map;
	int		i;

	if (!(data->map = (int **)malloc(sizeof(t_fdf *) * (data->height + 1))))
		exit(1);
	i = 0;
	while (i < data->height)
	{
		data->map[i] = (int *)malloc(sizeof(t_fdf) * (data->width + 1));
		if (!data->map[i])
			exit(1);
		i++;
	}
}

/*
** In "fill_map" we convert the string into ints with the help of ft_aoi
** With ft_strsplit we will take care of the empty spaces.
*/

void		fill_map(int *line_z, char *line)
{
	char	**map;
	int		i;

	map = ft_strsplit(line, ' ');
	i = 0;
	while (map[i])
	{
		line_z[i] = ft_atoi(map[i]);
		free(map[i]);
		i++;
	}
	free(map);
}

/*
** We read the file with get_next_line and allocating the map in a
** 2D Array.
*/

void		read_file(char *file, t_fdf *data)
{
	char	*line;
	int		fd;
	int		i;

	map_size(file, data);
	if (data->width == 0 || data->height == 0)
	{
		error("Invalid Map");
	}
	malloc_z(file, data);
	if ((fd = open(file, O_RDONLY)) < 0)
		exit(1);
	i = 0;
	while (get_next_line(fd, &line) > 0)
	{
		fill_map(data->map[i], line);
		free(line);
		i++;
	}
	data->map[i] = NULL;
	if (close(fd) == -1)
		exit(1);
}
