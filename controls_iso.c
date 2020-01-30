/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls_iso.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:02:47 by ismelich          #+#    #+#             */
/*   Updated: 2020/01/30 16:57:07 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** Isometric projection function.
*/

void	isometric(int *x, int *y, int z)
{
	int previous_x;
	int previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (previous_x - previous_y) * cos(0.523599);
	*y = -z + (previous_x + previous_y) * sin(0.523599);
}

void	projection(t_fdf *data, t_draw *info)
{
	isometric(&info->x, &info->y, info->z);
	isometric(&info->x2, &info->y2, info->z2);
}

/*
** Mouse Controls
*/

int		mouse_controls(int button, int x, int y, t_fdf *data)
{
	if (button == 1 && x && y)
		data->projection = PARALLEL;
	else if (button == 2)
		data->projection = ISOMETRIC;
	else if (button == 4)
		data->zoom += 1;
	else if (button == 5)
		data->zoom -= 1;
	draw(data);
	return (0);
}

/*
** Keyboard Controls
*/

void	key_controls_2(int key, t_fdf *data)
{
	if (key == 18)
		data->palette = FRUIT;
	else if (key == 19)
		data->palette = TRENDY;
	else if (key == 34)
		data->projection = ISOMETRIC;
	else if (key == 35)
		data->projection = PARALLEL;
}

/*
** Keyboard Controls
*/

int		key_controls_1(int key, t_fdf *data)
{
	write(1, "X", 1);
	if (key == 53)
		exit(0);
	else if (key == 69)
		data->altitude += 1;
	else if (key == 78)
		data->altitude -= 1;
	else if (key == 123)
		data->pos_x -= 5;
	else if (key == 124)
		data->pos_x += 5;
	else if (key == 125)
		data->pos_y += 5;
	else if (key == 126)
		data->pos_y -= 5;
	else if (key == 15)
		reset_map(data);
	key_controls_2(key, data);
	draw(data);
	return (0);
}
