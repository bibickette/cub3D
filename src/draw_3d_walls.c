/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:14:22 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/28 17:52:32 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool is_on_minimap(int x, int y, t_parsing *info)
{
	if (x >= MINI_MAP_LOC_X && x < MINI_MAP_LOC_X + MINI_MAP_SIZE * info->max_x
		&& y >= MINI_MAP_LOC_Y && y < MINI_MAP_LOC_Y + MINI_MAP_SIZE * info->max_y)
		return (true);
	return (false);
}

static void	draw_rectangle(int x, int y, unsigned int color, t_parsing *info,
		int replace)
{
	int	i;
	int	j;
	int	line_length;

	i = 0;
	line_length = get_line_length_int(x, y, x, y + info->ray.lineH);
	while (i < line_length)
	{
		j = 0;
		while (j < (SIZE_X / NB_RAYS))
		{
			if (y + i < 0 || y + i >= SIZE_Y || x + j < 0 || x + j >= SIZE_X)
				continue;
			if (replace)
				color = get_backup_color(info->mlx.backup, x + j, y + i);
			if (!is_on_minimap(x + j, y + i, info))	
				my_mlx_pixel_put(info->mlx.background, y + i, x + j, color);
			j++;
		}
		i++;
	}
}

static void	draw_big_line(t_parsing *info, t_ray *ray, unsigned int color,
		int replace)
{
	int	x;
	int	y;

	x = ray->r * (SIZE_X / NB_RAYS);
	y = ray->lineO;
	draw_rectangle(x, y, color, info, replace);
}

void	draw_3d_wall(t_ray *ray, t_parsing *info, int replace, int color_wall)
{
	int	x;
	int	y;

	x = SIZE_X / 2;
	y = SIZE_Y / 2;
	ray->ca = info->player.angle - ray->angle;
	ray->ca = protect_angle_trigo_value(ray->ca);
	ray->distT = (ray->distT) * cos(ray->ca);
	ray->lineH = ((info->max_x * info->max_y) * x) / ray->distT;
	if (ray->lineH > x)
		ray->lineH = x;
	ray->lineO = y - ray->lineH / 2;
	draw_big_line(info, ray, color_wall, replace);
}
/* jai compris quon avait une fenetre de 320 par 160 du coup
 pour le resultat 3d mais jarrive pas a changer les valeurs sans que ca segfault */