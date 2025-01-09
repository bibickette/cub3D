/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycaster.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:38:05 by phwang            #+#    #+#             */
/*   Updated: 2025/01/09 16:09:07 by fsalomon         ###   ########.fr       */
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
static bool	is_horizontal_line_hit_first(int last_ray, float horizontal_len,
		float vertical_len)
{
	if (horizontal_len == vertical_len && horizontal_len != 0)
		return (last_ray == HORIZONTAL);
	if (horizontal_len > 0 && (horizontal_len < vertical_len
			|| vertical_len <= 0))
		return (true);
	return (false);
}

static void	find_smallest_ray(t_ray *ray, float horizontal_len,
		float vertical_len, int *color_wall)
{
	if (is_horizontal_line_hit_first(ray->last_ray, horizontal_len,
			vertical_len))
	{
		ray->distance = horizontal_len;
		ray->last_ray = HORIZONTAL;
		if (ray->angle > PI && ray->angle < 2 * PI)
			*color_wall = BLUE;
		else
			*color_wall = RED;
	}
	else
	{
		ray->distance = vertical_len;
		ray->last_ray = VERTICAL;
		if (ray->angle > ray->pi2 && ray->angle < ray->pi3)
			*color_wall = DARK_RED;
		else
			*color_wall = DARK_BLUE;
		// Conserve seulement la fraction
	}
}

/*
Trace des rayons en fonction de la position du joueur et de son angle de vue
Dessine ensuite des murs en perspective 3d grace a longueur des rayons.
*/
void	raycaster(t_player *player, t_ray *ray, t_parsing *info, int replace)
{
	float	horizontal_len;
	float	vertical_len;
	int		color_wall;

	ray->angle = player->angle - (ray->rad_value / 2);
	ray->angle = protect_angle_trigo_value(ray->angle);
	ray->r = 0;
	while (ray->r < SIZE_X)
	{
		horizontal_len = ray_horizon_plan_len(player, ray, info);
		vertical_len = ray_vertical_plan_len(player, ray, info);
		find_smallest_ray(ray, horizontal_len, vertical_len, &color_wall);
		draw_3d_wall(ray, info, replace, color_wall);
		ray->angle += ray->rad_value / SIZE_X;
		ray->angle = protect_angle_trigo_value(ray->angle);
		ray->r++;
	}
}
