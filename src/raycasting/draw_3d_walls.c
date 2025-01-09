/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:14:22 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/09 15:44:33 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_rectangle(int x, int y, unsigned int color, t_parsing *info,
		int replace)
{
	float	i;
	float	line_length;

	i = 0;
	line_length = get_distance(x, y, x, y + info->ray.height_l);
	while (i < line_length)
	{
		if (replace)
			color = get_backup_color(info->mlx.backup, x, y + i);
		my_mlx_pixel_put(info->mlx.background, y + i, x, color);
		i++;
	}
}



static void	draw_big_line(t_parsing *info, t_ray *ray, unsigned int color,
		int replace)
{
	int	x;
	int	y;
	int id;
	
	if (color == DARK_RED)
		id = 0;
	else if (color == DARK_BLUE)
		id = 1;
	else if (color == RED)
		id = 2;
	else
		id = 3;
	
	x = ray->r;
	y = ray->offset_l;

	draw_rectangle(x, y, color, info, replace);
}

void	draw_3d_wall(t_ray *ray, t_parsing *info, int replace, int color_wall)
{
	int	x;
	int	y;

	x = SIZE_X / 2;
	y = SIZE_Y / 2;
	ray->cos_angle = info->player.angle - ray->angle;
	ray->cos_angle = protect_angle_trigo_value(ray->cos_angle);
	ray->distance = (ray->distance) * cos(ray->cos_angle);
	ray->height_l = (MINI_MAP_SIZE / ray->distance) * (x / tan(((PI / 180)
					* FOV) / 2));
	if (ray->height_l > x)
		ray->height_l = x;
	ray->offset_l = y - ray->height_l / 2;
	if (ray->offset_l < 0)
		ray->offset_l = 0;
	draw_big_line(info, ray, color_wall, replace);
}

/* jai compris quon avait une fenetre de 320 par 160 du coup
 pour le resultat 3d mais jarrive pas a changer les valeurs
 sans que ca segfault */