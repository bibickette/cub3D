/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:14:22 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/08 14:44:41 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_on_minimap(int x, int y, t_parsing *info)
{
	if (x >= MINI_MAP_LOC_X && x < MINI_MAP_LOC_X + MINI_MAP_SIZE * info->max_x
		&& y >= MINI_MAP_LOC_Y && y < MINI_MAP_LOC_Y + MINI_MAP_SIZE
		* info->max_y)
		return (true);
	return (false);
}

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
		// if (!is_on_minimap(x, y + i, info))
		my_mlx_pixel_put(info->mlx.background, y + i, x, color);
		i++;
	}
}

static void	draw_big_line(t_parsing *info, t_ray *ray, unsigned int color,
		int replace)
{
	int	x;
	int	y;

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
 pour le resultat 3d mais jarrive pas a changer les valeurs sans que ca segfault */