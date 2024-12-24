/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_ray.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/21 14:06:55 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/24 13:16:56 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
Calcule la première intersection du rayon avec les lignes verticale de la grille de la map.
En fonction de l'angle du rayon,
 cette fonction détermine :
 le point d'intersection initial (`ray->rx`,`ray->ry`)
 et les incréments de pas (`ray->xo`,
	`ray->yo`) pour avancer vers la prochaine ligne de la grille.
Les cas particuliers gèrent les rayons parfaitement verticaux en plaçant l'intersection à la position du joueur.
 */
static void	vtplan_find_intersection(t_ray *ray, t_parsing *info)
{
	ray->tan = -tan(ray->angle);
	if (ray->angle > PI2 && ray->angle < PI3)
	{
		ray->rx = (((int)ray->player_posx / MINI_MAP_SIZE) * MINI_MAP_SIZE)
			- 0.0001;
		ray->ry = (ray->player_posx - ray->rx) * ray->tan + ray->player_posy;
		ray->xo = -MINI_MAP_SIZE;
		ray->yo = -ray->xo * ray->tan;
	}
	if (ray->angle < PI2 || ray->angle > PI3)
	{
		ray->rx = (((int)ray->player_posx / MINI_MAP_SIZE) * MINI_MAP_SIZE)
			+ MINI_MAP_SIZE;
		ray->ry = (ray->player_posx - ray->rx) * ray->tan + ray->player_posy;
		ray->xo = MINI_MAP_SIZE;
		ray->yo = -ray->xo * ray->tan;
	}
	if (ray->angle == PI3 || ray->angle == PI2)
	{
		ray->rx = ray->player_posx;
		ray->ry = ray->player_posy;
		ray->dof = info->max_y;
	}
}

/*
Calcule la distance entre le joueur et la première intersection verticale avec un mur.
Cette fonction  appelle `vtplan_find_intersection` pour trouver la première intersection verticale.
Ensuite,
	elle parcourt la grille colonne par colonne,en avançant jusqu'à rencontrer un mur ou atteindre la limite maximale de recherche (dof).
La distance à l'intersection est finalement calculée et retournée.
*/
// jai trouve la longueur de chaque coté opposé a langle
// jadditionne ces cotés jusqua trouver un mur
// while tous les murs

int	ray_vertical_plan_len(t_player *player, t_ray *ray, t_parsing *info)
{
	ray->player_posx = player->pos_x + MINI_PLAYER_SIZE / 2;
	ray->player_posy = player->pos_y + MINI_PLAYER_SIZE / 2;
	ray->dof = 0;
	vtplan_find_intersection(ray, info);
	while (ray->dof < info->max_y)
	{
		ray->mx = (int)(ray->rx) / MINI_MAP_SIZE;
		ray->my = (int)(ray->ry) / MINI_MAP_SIZE;
		ray->mp = ray->my * info->max_x + ray->mx;
		if (ray->mp < 0)
			ray->mp = 0;
		// ca equivaut a un break ray->dof = info->max_y; // 8 cest le max y
		if (ray->mp < info->max_x * info->max_y && info->int_map[ray->mp] == 1)
			break ;
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof++;
		}
	}
	return (get_line_length_int(ray->player_posx, ray->player_posy, ray->rx,
			ray->ry));
}
