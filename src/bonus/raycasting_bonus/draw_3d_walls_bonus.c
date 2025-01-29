/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_walls_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:30:57 by phwang            #+#    #+#             */
/*   Updated: 2025/01/28 11:44:12 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static unsigned int	get_color_pixel_texture(t_parsing *info, int x, int y,
		int id)
{
	unsigned int	color;
	char			*dst;

	if (id == DOOR_CLOSED_INT)
	{
		dst = info->door.addr + (y * info->door.line_len + x * (info->door.bpp
					/ 8));
	}
	else
	{
		dst = info->textures.walls[id].img.addr + (y
				* info->textures.walls[id].img.line_len + x
				* (info->textures.walls[id].img.bpp / 8));
	}
	color = *(unsigned int *)dst;
	return (color);
}

static void	draw_ray_bonus(t_parsing *info, t_ray *ray, int id)
{
	float	i;
	float	line_length;
	int		tex_x;
	int		tex_y;

	line_length = get_distance(ray->start_x, ray->start_y, ray->start_x,
			ray->start_y + ray->height_l);
	tex_x = (int)(ray->wall_hit * TEXTURE_SIZE);
	i = -1;
	if (ray->start_y < 0)
		i = -(ray->start_y + 1);
	while (++i < line_length)
	{
		tex_y = (int)((i / line_length) * TEXTURE_SIZE);
		if (!is_on_minimap(ray->start_y + i, ray->start_x, MINI_MAP_RAY
				+ MINI_MAP_BORDER))
			my_mlx_pixel_put(*(info->mlx.current_background), ray->start_y + i,
				ray->start_x, get_color_pixel_texture(info, tex_x, tex_y, id));
		if (ray->start_y + i + 1 > SIZE_Y)
			break ;
	}
}

void	draw_3d_wall_bonus(t_parsing *info, t_ray *ray)
{
	int	x;
	int	y;

	x = SIZE_X / 2;
	y = SIZE_Y / 2;
	ray->cos_angle = info->player.angle - ray->angle;
	ray->cos_angle = protect_angle_trigo_value(ray->cos_angle);
	ray->distance = (ray->distance) * cos(ray->cos_angle);
	ray->height_l = (SCALE / ray->distance) * (x / tan(ray->rad_value
				/ 2));
	ray->base_l = y - ray->height_l / 2;
	ray->start_x = ray->r;
	ray->start_y = ray->base_l;
	draw_ray_bonus(info, ray, ray->id);
}
