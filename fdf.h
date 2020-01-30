/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ismelich <ismelich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 15:50:55 by ismelich          #+#    #+#             */
/*   Updated: 2020/01/30 16:58:31 by ismelich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/includes/libft.h"
# include "libft/includes/get_next_line.h"
# include <math.h>
# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>

typedef enum
{
	ISOMETRIC,
	PARALLEL
}	t_projection;

typedef enum
{
	FRUIT,
	TRENDY
}	t_palette;

typedef struct		s_draw
{
	int				dx;
	int				dy;
	int				x;
	int				x2;
	int				y;
	int				y2;
	int				z;
	int				z2;
}					t_draw;

typedef struct		s_fdf
{
	int				**map;
	int				map_h;
	int				map_w;
	int				height;
	int				width;
	int				zoom;
	int				altitude;
	int				color;
	int				pos_x;
	int				pos_y;
	t_projection	projection;
	t_palette		palette;
	void			*mlx;
	void			*win;
}					t_fdf;

int					key_controls_1(int key, t_fdf *data);
int					mouse_controls(int key, int x, int y, t_fdf *data);
void				read_file(char *file, t_fdf *data);
void				draw(t_fdf *data);
void				print_menu(t_fdf *data);
void				color(t_fdf *data, int x, int y);
void				projection(t_fdf *data, t_draw *info);
void				isometric(int *x, int *y, int z);
void				reset_map(t_fdf *data);
void				error(char *error);

#endif
