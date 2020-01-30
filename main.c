/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:01:10 by ismelich          #+#    #+#             */
/*   Updated: 2020/01/28 16:08:55 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *error)
{
	ft_putendl(error);
	exit(EXIT_FAILURE);
}

/*
** This are the default setting when we use 'R' for reset. The map will be
** reseted to the location where we started.
*/

void	reset_map(t_fdf *data)
{
	data->zoom = 25;
	if (data->height > 300 || data->width > 300)
		data->zoom = 1;
	else if (data->height > 200 || data->width > 200)
		data->zoom = 2;
	else if (data->height > 100 || data->width > 100)
		data->zoom = 4;
	else if (data->height > 25 || data->width > 25)
		data->zoom = 8;
	data->altitude = 1;
	data->palette = TRENDY;
	data->projection = ISOMETRIC;
	data->pos_x = data->map_w / 2 - (data->map_w / 15);
	data->pos_y = 200;
	draw(data);
}

/*
** "win_interface" will open a window according to our map size input.
** It makes it more 'user-friendly'.
*/

void	win_interface(t_fdf *data)
{
	if (data->height > 300 || data->width > 300)
	{
		data->zoom = 1;
		data->map_h = 1300;
		data->map_w = 2400;
	}
	else if (data->height > 200 || data->width > 200)
	{
		data->zoom = 2;
		data->map_h = 1200;
		data->map_w = 2200;
	}
	else if (data->height > 100 || data->width > 100)
	{
		data->zoom = 4;
		data->map_h = 1000;
		data->map_w = 2000;
	}
	else if (data->height > 25 || data->width > 25)
	{
		data->zoom = 8;
		data->map_h = 1000;
		data->map_w = 1600;
	}
}

/*
** In "setup_image" we will set up all the necessary setting when we
** will open our X-window.
*/

void	setup_image(t_fdf *data)
{
	data->zoom = 25;
	data->map_h = 800;
	data->map_w = 1000;
	data->color = 0xFFFFFF;
	data->altitude = 1;
	data->palette = TRENDY;
	data->projection = ISOMETRIC;
	win_interface(data);
	data->pos_x = data->map_w / 2 - (data->map_w / 15);
	data->pos_y = 200;
}

int		main(int argc, char **argv)
{
	t_fdf		*data;

	if (!(data = (t_fdf*)malloc(sizeof(t_fdf))))
		exit(-1);
	if (argc != 2)
	{
		error("To many/few arguments!");
		error("usage: ./fdf <filename>");
		return (1);
	}
	read_file(argv[1], data);
	setup_image(data);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, data->map_w, data->map_h, "FDF");
	draw(data);
	mlx_hook(data->win, 2, 0, key_controls_1, data);
	mlx_hook(data->win, 4, 0, mouse_controls, data);
	mlx_loop(data->mlx);
	return (0);
}
