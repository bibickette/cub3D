/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:38:05 by phwang            #+#    #+#             */
/*   Updated: 2025/01/27 14:40:23 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
// static void	draw_mini_line(t_parsing *info, unsigned int color,
// 		float line_length)
// {
// 	float	i;
// 	int		x;
// 	int		y;

// 	i = 0;
// 	x = MINI_MAP_CENTER + i * cos(info->player.angle);
// 	y = MINI_MAP_CENTER + i * sin(info->player.angle);
// 	while (i < line_length / 2 + 1)
// 	{
// 		x = MINI_MAP_CENTER + i * cos(info->ray.angle);
// 		y = MINI_MAP_CENTER + i * sin(info->ray.angle);
// 		if (get_backup_color(*(info->mlx.current_background), x,
// 				y) == info->textures.ceiling_color)
// 			break ;
// 		if (is_on_minimap(x, y, MINI_MAP_RAY))
// 			my_mlx_pixel_put(*(info->mlx.current_background), y, x, color);
// 		i++;
// 	}
// }

void	door_handling(t_parsing *info, t_ray *ray, int door_flag, int direction)
{
	if (info->int_map[ray->map_pos] == DOOR_CLOSE_INT)
	{
		if (direction == HORIZONTAL)
			ray->is_door_horizontal = door_flag;
		else
			ray->is_door_vertical = door_flag;
		if (ray->r == SIZE_X / 2)
		{
			ray->door_x = ray->map_x;
			ray->door_y = ray->map_y;
		}
	}
}

bool	is_door_or_wall(t_parsing *info, t_ray *ray)
{
	return (ray->map_pos < info->max_x * info->max_y
		&& (info->int_map[ray->map_pos] == 1
			|| info->int_map[ray->map_pos] == DOOR_CLOSE_INT));
}

static void	find_smallest_ray_bonus(t_ray *ray, float horizontal_len,
		float vertical_len)
{
	if (vertical_len > horizontal_len)
		init_horizontal_value_bonus(ray, horizontal_len);
	if (vertical_len < horizontal_len)
		init_vertical_value_bonus(ray, vertical_len);
	ray->wall_hit -= floor(ray->wall_hit);
}

/*
Trace des rayons en fonction de la position du joueur et de son angle de vue
Dessine ensuite des murs en perspective 3d grace a longueur des rayons.
*/
void	raycaster_bonus(t_player *player, t_ray *ray, t_parsing *info)
{
	float	horizontal_len;
	float	vertical_len;

	ray->angle = player->angle - (ray->rad_value / 2);
	ray->angle = protect_angle_trigo_value(ray->angle);
	ray->r = 0;
	ray->can_open_door = false;
	while (ray->r < SIZE_X)
	{
		horizontal_len = ray_horizon_plan_len_bonus(player, ray, info);
		vertical_len = ray_vertical_plan_len_bonus(player, ray, info);
		find_smallest_ray_bonus(ray, horizontal_len, vertical_len);
		// draw_mini_line(info, WHITE, ray->diatance); // bonus part
		draw_3d_wall_bonus(ray, info);
		ray->is_door_horizontal = IS_NOT_DOOR;
		ray->is_door_vertical = IS_NOT_DOOR;
		ray->angle += ray->rad_value / SIZE_X;
		ray->angle = protect_angle_trigo_value(ray->angle);
		ray->r++;
	}
}
