/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_hub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:03:19 by ismelich          #+#    #+#             */
/*   Updated: 2020/01/28 16:15:17 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** This is the function for our Menu Hub.
*/

void			print_menu(t_fdf *data)
{
	mlx_string_put(data->mlx, data->win, 50, 50, 0x1C799E, "HUB");
	mlx_string_put(data->mlx, data->win, 50, 100, 0x1C799E, "ESC == Exit HUB");
	mlx_string_put(data->mlx, data->win, 50, 120,
		0x1C799E, "Mouse wheel == Zoom");
	mlx_string_put(data->mlx, data->win, 50, 140, \
		0x1C799E, "+ || - == Change Altitude");
	mlx_string_put(data->mlx, data->win, 50, 160, \
		0x1C799E, "Key Arrows == Move the map");
	mlx_string_put(data->mlx, data->win, 50, 180, \
		0x1C799E, "Mouse R/L == Switch between 2D and 3D");
	mlx_string_put(data->mlx, data->win, 50, 200, 0x1C799E, "1 == FRUIT Color");
	mlx_string_put(data->mlx, data->win, 50, 220, \
		0x1C799E, "2 == TRENDY Color");
	mlx_string_put(data->mlx, data->win, 50, 240, 0x1C799E, "r == Reset Map"); \
}

/*
** Our main drawing function based on the bresenham algorithm.
*/

static void		draw_pixels(t_fdf *d, t_draw s, t_draw e)
{
	int dx;
	int dy;
	int dir[2];
	int p[2];

	dx = ft_abs(e.x - s.x);
	dy = ft_abs(e.y - s.y);
	dir[0] = (s.x < e.x ? 1 : -1);
	dir[1] = (s.y < e.y ? 1 : -1);
	p[0] = (dx > dy ? dx : -dy) / 2;
	while (s.x != e.x || s.y != e.y)
	{
		mlx_pixel_put(d->mlx, d->win, d->pos_x + s.x, d->pos_y + s.y, d->color);
		p[1] = p[0];
		if (p[1] > -dx)
		{
			p[0] -= dy;
			s.x += dir[0];
		}
		if (p[1] < dy)
		{
			p[0] += dx;
			s.y += dir[1];
		}
	}
}

/*
** In "draw_lines" we are giving our "draw_pixels" all the informations it needs
** to draw a straigh line.
*/

static void		draw_lines(t_fdf *data, t_draw start, t_draw end)
{
	t_draw		*info;

	if (!(info = (t_draw*)malloc(sizeof(t_draw))))
		exit(-1);
	info->z = data->map[start.y][start.x] * data->altitude;
	info->z2 = data->map[end.y][end.x] * data->altitude;
	info->x = start.x * data->zoom;
	info->x2 = end.x * data->zoom;
	info->y = start.y * data->zoom;
	info->y2 = end.y * data->zoom;
	if (data->projection == ISOMETRIC)
		projection(data, info);
	start.x = info->x;
	start.y = info->y;
	end.x = info->x2;
	end.y = info->y2;
	draw_pixels(data, start, end);
	free(info);
}

/*
** In "set_coordinates" we set the coordinates and the color for our
** bresenham algorithm.
*/

void			set_coordinates(t_fdf *data, int x, int y)
{
	t_draw		coordinates[2];

	color(data, x, y);
	coordinates[0].x = x;
	coordinates[0].y = y;
	if (x < data->width - 1)
	{
		coordinates[1].x = x + 1;
		coordinates[1].y = y;
		draw_lines(data, coordinates[0], coordinates[1]);
	}
	if (y < data->height - 1)
	{
		coordinates[1].x = x;
		coordinates[1].y = y + 1;
		draw_lines(data, coordinates[0], coordinates[1]);
	}
}

/*
** This is were the pixel drawing begins, "draw" will loop through
** other sub-functions in order to draw the pixels.
*/

void			draw(t_fdf *data)
{
	int			x;
	int			y;

	y = 0;
	mlx_clear_window(data->mlx, data->win);
	print_menu(data);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			set_coordinates(data, x, y);
			x++;
		}
		y++;
	}
}
