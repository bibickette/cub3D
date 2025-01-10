/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_3d_walls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 13:14:22 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/10 13:18:38 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static unsigned int	get_color_pixel_texture(t_parsing *info, int x, int y, int id)
{
	unsigned int	color;
	char			*dst;

	dst = info->textures.walls[id].img.addr + (y
			* info->textures.walls[id].img.line_len + x
			* (info->textures.walls[id].img.bpp / 8));
	color = *(unsigned int *)dst;
	return (color);
}

static int	get_texture_x(unsigned int color, t_ray *ray, t_wall *wall)
{
	int tex_x;
	if (color == BLUE || color == RED)
	{
		if (color == BLUE)
			tex_x = (int)((ray->rx - floor(ray->rx)) * wall[EA].width);
		else
			tex_x = (int)((ray->rx - floor(ray->rx)) * wall[WE].width);

	}
	else
	{
		if (color == DARK_RED)
			tex_x = (int)((ray->ry - floor(ray->ry)) * wall[NO].width);
		else
			tex_x = (int)((ray->ry - floor(ray->ry)) * wall[SO].width);
		
	}
	return(tex_x);
}

int get_texture_y(int y, int wall_height, int screen_height)
{
    return ((y * wall_height) / screen_height);
}

static void	draw_rectangle(int x, int y, unsigned int color, t_parsing *info,
		int replace,int id)
{
	float	i;
	float	line_length;
	int		tex_x;
	int		tex_y;
	float	ecran_y;

	ecran_y = 512.00;

	// tex_x = get_texture_x(color, &info->ray, info->textures.walls);
	// pour calculer le tex x il faut prendre le wall hit et le faire protportionnellement a la largeur de la texture 
	tex_x = (int)(info->ray.wall_hit * TEXTURE_SIZE);
	i = 0;
	line_length = get_distance(x, y, x, y + info->ray.height_l);
	info->ray.wall_bottom = y + line_length;// a mettre avec le rapport de limage 
	info->ray.wall_top = y;
	// tex y cest proportionellement bottom + i par rapport a la hauteur de limage
	
	while (i < line_length)
	{
		// tex_y = get_texture_y(i, info->textures.walls[id].height, info->ray.height_l);
		tex_y =  ((y + i) * TEXTURE_SIZE) / ecran_y;
		if (replace)
			color = get_backup_color(info->mlx.backup, x, y + i);
		else
			color = get_color_pixel_texture(info, tex_x, tex_y, id);
		my_mlx_pixel_put(info->mlx.background, y + i, x, color);
		i++;
	}
}

static void	draw_big_line(t_parsing *info, t_ray *ray, unsigned int color,
		int replace)
{
	int	x;
	int	y;
	int	id;

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
	draw_rectangle(x, y, color, info, replace, id);
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