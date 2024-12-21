/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:38:05 by phwang            #+#    #+#             */
/*   Updated: 2024/12/21 17:12:41 by fsalomon         ###   ########.fr       */
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
static bool	is_horizontal_line_hit_first(int last_ray, int horizontal_len,
		int vertical_len)
{
	if (horizontal_len == vertical_len && horizontal_len != 0)
		return (last_ray == HORIZONTAL);
	if (horizontal_len > 0 && (horizontal_len < vertical_len
			|| vertical_len <= 0))
		return (true);
	return (false);
}

/* verifie quel est le rayon qui a frappé en premier le mur et le dessine */

static void	draw_smallest_ray(t_ray *ray, t_parsing *info, int replace,
		int horizontal_len, int vertical_len)
{
	if (is_horizontal_line_hit_first(ray->last_ray, horizontal_len,
			vertical_len))
	{
		draw_mini_line(info, GREEN, replace, horizontal_len);
		ray->distT = horizontal_len;
		ray->last_ray = HORIZONTAL;
	}
	else
	{
		draw_mini_line(info, RED, replace, vertical_len);
		ray->distT = vertical_len;
		ray->last_ray = VERTICAL;
	}
}

/* 
Trace des rayons en fonction de la position du joueur et de son angle de vue
Dessine ensuite des murs en perspective 3d grace a longueur des rayons.
*/
void	draw_rays(t_player *player, t_ray *ray, t_parsing *info, int replace)
{
	int	horizontal_len;
	int	vertical_len;
	int	color_wall;

	ray->angle = player->angle - (DR * FOV) / 2;
	ray->angle = protect_angle_trigo_value(ray->angle);
	ray->r = 0;
	while (ray->r < FOV)
	{
		horizontal_len = ray_horizon_plan_len(player, ray, info);
		vertical_len = ray_vertical_plan_len(player, ray, info);
		draw_smallest_ray(ray, info, replace, horizontal_len, vertical_len);
		if (ray->last_ray == HORIZONTAL)
			color_wall = BLUE;
		else
			color_wall = DARK_BLUE;
		draw_3d_wall(ray, info, replace, color_wall);
		ray->angle += DR;
		ray->angle = protect_angle_trigo_value(ray->angle);
		ray->r++;
	}
}
