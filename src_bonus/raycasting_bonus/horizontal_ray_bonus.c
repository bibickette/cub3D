/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_ray_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:00:57 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/27 16:58:11 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
Calcule la première intersection du rayon avec les lignes horizontales de
la grille de la map.
En fonction de l'angle du rayon,
 cette fonction détermine :
 le point d'intersection initial (`ray->rx`,`ray->ry`)
 et les incréments de pas (`ray->xo`,
	`ray->yo`) pour avancer vers la prochaine ligne de la grille.
Les cas particuliers gèrent les rayons parfaitement horizontaux
en plaçant l'intersection à la position du joueur.
 */

void	init_horizontal_value_bonus(t_ray *ray, float ray_len)
{
	ray->distance = ray_len;
	ray->last_ray = HORIZONTAL;
	if (ray->angle > PI && ray->angle < 2 * PI)
		ray->id = SO;
	else
		ray->id = NO;
	if (ray->door.is_door_horizontal == IS_DOOR_HORIZONTAL)
	{
		ray->id = DOOR_CLOSE_INT;
		if (ray_len <= DISTANCE_TO_DOOR)
		{
			ray->door.can_open_door = true;
			ray->door.door_x = ray->door.h_door_closed_x;
			ray->door.door_y = ray->door.h_door_closed_y;
		}
	}
	ray->wall_hit = fmod(ray->hx, SCALE) / SCALE;
}

static void	hzplan_find_intersection(t_ray *ray, t_parsing *info)
{
	ray->arc_tan = -1 / tan(ray->angle);
	if (ray->angle > PI)
	{
		ray->hy = (((int)ray->player_posy / SCALE) * SCALE) - 0.0001;
		ray->hx = (ray->player_posy - ray->hy) * ray->arc_tan
			+ ray->player_posx;
		ray->yo = -SCALE;
		ray->xo = -ray->yo * ray->arc_tan;
	}
	if (ray->angle < PI)
	{
		ray->hy = (((int)ray->player_posy / SCALE) * SCALE) + SCALE;
		ray->hx = (ray->player_posy - ray->hy) * ray->arc_tan
			+ ray->player_posx;
		ray->yo = SCALE;
		ray->xo = -ray->yo * ray->arc_tan;
	}
	if (ray->angle == 0 || ray->angle == PI)
	{
		ray->hx = ray->player_posx;
		ray->hy = ray->player_posy;
		ray->dist_to_wall = info->max_x;
	}
}

/*
Calcule la distance entre le joueur et la première intersection horizontale
avec un mur.
Cette fonction  appelle `hzplan_find_intersection` pour trouver
la première intersection horizontale.
Ensuite,
	elle parcourt la grille ligne par ligne,en avançant jusqu'à
	rencontrer un mur ou atteindre la limite maximale de recherche (dof).
La distance à l'intersection est finalement calculée et retournée.
*/

// bool	is_door_or_wall(t_parsing *info, t_ray *ray)
// {
// 	return (ray->map_pos < info->max_x * info->max_y
// 		&& (info->int_map[ray->map_pos] == 1
// 			|| info->int_map[ray->map_pos] == DOOR_CLOSE_INT));
// }
float	ray_horizon_plan_len_bonus(t_player *player, t_ray *ray,
		t_parsing *info)
{
	ray->player_posx = player->pos_x + MINI_PLAYER_SIZE / 2;
	ray->player_posy = player->pos_y + MINI_PLAYER_SIZE / 2;
	ray->dist_to_wall = 0;
	hzplan_find_intersection(ray, info);
	while (ray->dist_to_wall < info->max_y)
	{
		ray->map_x = (int)(ray->hx) / SCALE;
		ray->map_y = (int)(ray->hy) / SCALE;
		ray->map_pos = ray->map_y * info->max_x + ray->map_x;
		if (ray->map_pos < 0)
			ray->map_pos = 0;
		// si mon joueur au premier tour de la boucle NEST PAS sur la porte
		// si je suis face porte ouverte, register la position de la porte
		if (is_door_or_wall(info, ray))
		{
			door_handling(info, ray, HORIZONTAL);
			break ;
		}
		else
		{
			ray->hx += ray->xo;
			ray->hy += ray->yo;
			ray->dist_to_wall++;
		}
	}
	return (get_distance(ray->player_posx, ray->player_posy, ray->hx, ray->hy));
}
