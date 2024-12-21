/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:14:22 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/21 17:18:12 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_rectangle(int x, int y,
		unsigned int color, t_parsing *info, int replace)
{
	int	i;
	int	j;
	int	line_length;

	i = 0;
	line_length = get_line_length_int(x, y, x, y + info->ray.lineH);
	while (i < line_length)
	{
		j = 0;
		while (j < 8)
		{
			if (y + i < 0 || y + i >= SIZE_Y || x + j < 0 || x + j >= SIZE_X)
				break ;
			if (replace)
				color = get_backup_color(info->mlx.backup, x, y);
			my_mlx_pixel_put(info->mlx.background, y + i, x + j, color);
			j++;
		}
		i++;
	}
}

static void	draw_big_line(t_parsing *info, t_ray *ray, unsigned int color,
		int replace)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = ray->r * 8 + 530;
	// 8 max x et 530 dercalage pour pas ecrire sur minimap
	y = ray->lineO;
	draw_rectangle(x, y, color, info, replace);
}

void	draw_3d_wall(t_ray *ray, t_parsing *info, int replace,
		int color_wall)
{
	ray->ca = info->player.angle - ray->angle;
	ray->ca = protect_angle_trigo_value(ray->ca);
	ray->distT = ray->distT * cos(ray->ca);
	ray->lineH = ((info->max_x * info->max_y) * 320) / ray->distT;
	if (ray->lineH > 320)
		ray->lineH = 320;
	ray->lineO = 160 - ray->lineH / 2;
	draw_big_line(info, ray, color_wall, replace);
}
/* jai compris quon avait une fenetre de 320 par 160 du coup
 pour le resultat 3d mais jarrive pas a changer les valeurs sans que ca segfault */