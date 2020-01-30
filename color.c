/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 18:01:55 by ismelich          #+#    #+#             */
/*   Updated: 2020/01/24 15:35:48 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fruit_color(t_fdf *data, int x, int y)
{
	int		z;

	z = data->map[y][x];
	if (z * data->altitude < 0)
		data->color = 0x009292;
	if (z * data->altitude == 0)
		data->color = 0xF65156;
	if (z * data->altitude > 0 && z * data->altitude <= 20)
		data->color = 0x88070B;
	if (z * data->altitude > 20 && z * data->altitude <= 50)
		data->color = 0xf8a7e7;
	if (z * data->altitude > 50 && z * data->altitude <= 99)
		data->color = 0xFFCE13;
	if (z * data->altitude >= 100)
		data->color = 0x009292;
}

void	trendy_color(t_fdf *data, int x, int y)
{
	int		z;

	z = data->map[y][x];
	if (z * data->altitude < 0)
		data->color = 0xf0134d;
	if (z * data->altitude == 0)
		data->color = 0xff6f5e;
	if (z * data->altitude > 0 && z * data->altitude <= 20)
		data->color = 0xf5f0e3;
	if (z * data->altitude > 20 && z * data->altitude <= 50)
		data->color = 0xf8a7e7;
	if (z * data->altitude > 50 && z * data->altitude <= 99)
		data->color = 0x40bfc1;
	if (z * data->altitude >= 100)
		data->color = 0xff6f5e;
}

void	color(t_fdf *data, int x, int y)
{
	if (data->palette == FRUIT)
		fruit_color(data, x, y);
	else if (data->palette == TRENDY)
		trendy_color(data, x, y);
}
