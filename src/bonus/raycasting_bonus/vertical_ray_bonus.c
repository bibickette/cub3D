/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_ray_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:06:55 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/28 12:25:59 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*
Calcule la première intersection du rayon avec les lignes verticale
 de la grille de la map.
En fonction de l'angle du rayon,
 cette fonction détermine :
 le point d'intersection initial (`ray->rx`,`ray->ry`)
 et les incréments de pas (`ray->xo`,
	`ray->yo`) pour avancer vers la prochaine ligne de la grille.
Les cas particuliers gèrent les rayons parfaitement verticaux en
plaçant l'intersection à la position du joueur.
 */

void	init_vertical_value_bonus(t_ray *ray, float ray_len)
{
	ray->distance = ray_len;
	if (ray->angle > ray->pi2 && ray->angle < ray->pi3)
		ray->id = EA;
	else
		ray->id = WE;
	init_door_closed_v(ray, ray_len);
	init_door_open_v(ray);
	ray->wall_hit = fmod(ray->vy, SCALE) / SCALE;
}

static void	vtplan_find_intersection(t_ray *ray, t_parsing *info)
{
	ray->tan = -tan(ray->angle);
	if (ray->angle > ray->pi2 && ray->angle < ray->pi3)
	{
		ray->vx = (((int)ray->player_posx / SCALE) * SCALE) - 0.0001;
		ray->vy = (ray->player_posx - ray->vx) * ray->tan + ray->player_posy;
		ray->xo = -SCALE;
		ray->yo = -ray->xo * ray->tan;
	}
	if (ray->angle < ray->pi2 || ray->angle > ray->pi3)
	{
		ray->vx = (((int)ray->player_posx / SCALE) * SCALE) + SCALE;
		ray->vy = (ray->player_posx - ray->vx) * ray->tan + ray->player_posy;
		ray->xo = SCALE;
		ray->yo = -ray->xo * ray->tan;
	}
	if (ray->angle == ray->pi3 || ray->angle == ray->pi2)
	{
		ray->vx = ray->player_posx;
		ray->vy = ray->player_posy;
		ray->dist_to_wall = info->max_y;
	}
}

/*
Calcule la distance entre le joueur et la première intersection verticale
avec un mur.
Cette fonction  appelle `vtplan_find_intersection` pour trouver la première
 intersection verticale.
Ensuite,
	elle parcourt la grille colonne par colonne,en avançant jusqu'à
	rencontrer un mur ou atteindre la limite maximale de recherche (dof).
La distance à l'intersection est finalement calculée et retournée.
*/
// jai trouve la longueur de chaque coté opposé a langle
// jadditionne ces cotés jusqua trouver un mur
// while tous les murs

float	ray_vertical_plan_len_bonus(t_player *player, t_ray *ray,
		t_parsing *info)
{
	ray->player_posx = player->pos_x + MINI_PLAYER_SIZE / 2;
	ray->player_posy = player->pos_y + MINI_PLAYER_SIZE / 2;
	ray->dist_to_wall = 0;
	vtplan_find_intersection(ray, info);
	while (ray->dist_to_wall < info->max_x)
	{
		ray->map_x = (int)(ray->vx) / SCALE;
		ray->map_y = (int)(ray->vy) / SCALE;
		ray->map_pos = ray->map_y * info->max_x + ray->map_x;
		if (ray->map_pos < 0)
			ray->map_pos = 0;
		door_open_handling_v(info, ray);
		if (is_door_closed_or_wall(info, ray))
			return (door_closed_handling_v(info, ray));
		else
		{
			ray->vx += ray->xo;
			ray->vy += ray->yo;
			ray->dist_to_wall++;
		}
	}
	return (get_distance(ray->player_posx, ray->player_posy, ray->vx, ray->vy));
}
