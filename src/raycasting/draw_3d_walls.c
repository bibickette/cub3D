/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 16:30:57 by phwang            #+#    #+#             */
/*   Updated: 2025/01/14 10:10:34 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	get_color_pixel_texture(t_parsing *info, int x, int y,
		int id)
{
	unsigned int	color;
	char			*dst;

	dst = info->textures.walls[id].img.addr + (y
			* info->textures.walls[id].img.line_len + x
			* (info->textures.walls[id].img.bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}

static bool	is_inside_screen(int x, int y)
{
	if (x < 0 || x > SIZE_X || y < 0 || y > SIZE_Y)
		return (false);
	return (true);
}

static void	draw_rectangle(unsigned int color, t_parsing *info, int replace,
		int id)
{
	float	i;
	float	line_length;
	int		tex_x;
	int		tex_y;
	t_ray	*ray;

	ray = &info->ray;
	line_length = get_distance(ray->start_x, ray->start_y, ray->start_x,
			ray->start_y + ray->height_l);
	tex_x = (int)(info->ray.wall_hit * info->textures.walls[id].width);
	i = -1;
	while (++i < line_length)
	{
		tex_y = (int)((i / line_length) * TEXTURE_SIZE);
		if (replace)
		{
			if (is_inside_screen(ray->start_x, ray->start_y + i))
				color = get_backup_color(info->mlx.backup, ray->start_x,
						ray->start_y + i);
		}
		else
			color = get_color_pixel_texture(info, tex_x, tex_y, id);
		my_mlx_pixel_put(info->mlx.background, ray->start_y + i, ray->start_x,
			color);
	}
}

static void	draw_big_line(t_parsing *info, t_ray *ray, unsigned int color,
		int replace)
{
	int	id;

	if (color == DARK_RED)
		id = WE;
	else if (color == DARK_BLUE)
		id = EA;
	else if (color == RED)
		id = SO;
	else
		id = NO;
	ray->start_x = ray->r;
	ray->start_y = ray->offset_l;
	draw_rectangle(color, info, replace, id);
}

void	draw_3d_wall(t_ray *ray, t_parsing *info, int replace, int color_wall)
{
	int	x;
	int	y;

	x = SIZE_X / 2;
	y = SIZE_Y / 2;
	info->ray.cos_angle = info->player.angle - info->ray.angle;
	info->ray.cos_angle = protect_angle_trigo_value(info->ray.cos_angle);
	info->ray.distance = (info->ray.distance) * cos(info->ray.cos_angle);
	info->ray.height_l = (MINI_MAP_SIZE / info->ray.distance) * (x
			/ tan(ray->rad_value / 2));
	info->ray.offset_l = y - info->ray.height_l / 2;
	draw_big_line(info, ray, color_wall, replace);
}
