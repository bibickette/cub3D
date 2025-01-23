/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:38:05 by phwang            #+#    #+#             */
/*   Updated: 2025/01/23 16:38:20 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Si les longueurs sont égales et non nulles, on privilégie le dernier rayon.
 Si la longueur horizontale est valide et
				-> soit inférieure à la verticale,
				-> soit si la longueur verticale est invalide (négative ou nulle)
 Alors on privilégie le rayon horizontal.
 dans les autres cas on previligie le rayon vertical.
 */
// static bool	is_horizontal_line_hit_first(int last_ray, float horizontal_len,
// 		float vertical_len)
// {
// 	if (vertical_len <= horizontal_len)
// 		return (false);
// 	else
// 		return (true);
// 	return (false);
// }
static void	draw_mini_line(t_parsing *info, unsigned int color,
		float line_length)
{
	float	i;
	int		x;
	int		y;

	i = 0;
	x = MINI_MAP_CENTER + i * cos(info->player.angle);
	y = MINI_MAP_CENTER + i * sin(info->player.angle);
	while (i < line_length / 2 + 1)
	{
		x = MINI_MAP_CENTER + i * cos(info->ray.angle);
		y = MINI_MAP_CENTER + i * sin(info->ray.angle);
		if (get_backup_color(*(info->mlx.current_background), x,
				y) == info->textures.ceiling_color)
			break ;
		if (is_on_minimap(x, y, MINI_MAP_RAY))
			my_mlx_pixel_put(*(info->mlx.current_background), y, x, color);
		i++;
	}
}

static void	find_smallest_ray(t_ray *ray, float horizontal_len,
		float vertical_len)
{
	if (vertical_len > horizontal_len)
		init_horizontal_value(ray, horizontal_len);
	if (vertical_len < horizontal_len)
		init_vertical_value(ray, vertical_len);
	ray->wall_hit -= floor(ray->wall_hit);
}

/*
Trace des rayons en fonction de la position du joueur et de son angle de vue
Dessine ensuite des murs en perspective 3d grace a longueur des rayons.
*/
void	raycaster(t_player *player, t_ray *ray, t_parsing *info)
{
	float	horizontal_len;
	float	vertical_len;

	ray->angle = player->angle - (ray->rad_value / 2);
	ray->angle = protect_angle_trigo_value(ray->angle);
	ray->r = 0;
	while (ray->r < SIZE_X)
	{
		horizontal_len = ray_horizon_plan_len(player, ray, info);
		vertical_len = ray_vertical_plan_len(player, ray, info);
		find_smallest_ray(ray, horizontal_len, vertical_len);
		// draw_mini_line(info, WHITE, ray->diatance); // bonus part
		draw_3d_wall(ray, info);
		// draw_wall_on_minimap(ray, info);
		ray->angle += ray->rad_value / SIZE_X;
		ray->angle = protect_angle_trigo_value(ray->angle);
		ray->r++;
	}
}
