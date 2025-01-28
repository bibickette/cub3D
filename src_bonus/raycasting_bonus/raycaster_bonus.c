/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:38:05 by phwang            #+#    #+#             */
/*   Updated: 2025/01/28 14:21:41 by phwang           ###   ########.fr       */
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
	reset_can_took_door(&ray->door);
	while (ray->r < SIZE_X)
	{
		horizontal_len = ray_horizon_plan_len_bonus(player, ray, info);
		vertical_len = ray_vertical_plan_len_bonus(player, ray, info);
		find_smallest_ray_bonus(ray, horizontal_len, vertical_len);
		draw_3d_wall_bonus(info, ray);
		reset_is_door(&ray->door);
		ray->angle += ray->rad_value / SIZE_X;
		ray->angle = protect_angle_trigo_value(ray->angle);
		ray->r++;
	}
}
