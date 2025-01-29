/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_open.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:20:24 by phwang            #+#    #+#             */
/*   Updated: 2025/01/29 15:20:35 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/* je detecte sur le meme principe des murs la porte ouverte et je sauvegarde
sa position x y, je dis aussi variable took nearest is true car comme ca il
detectera seulement la premiere porte et pas les portes ouvertes
qui sont derrieres la premiere porte detectée */
void	door_open_handling_v(t_parsing *info, t_ray *ray)
{
	if (ray->map_pos < info->max_x * info->max_y
		&& info->int_map[ray->map_pos] == DOOR_OPEN_INT)
	{
		ray->door.is_door_open_v = IS_DOOR_VERTICAL;
		if (ray->r == SIZE_X / 2 && !ray->door.took_nearest_door_v)
		{
			ray->door.v_door_open_x = ray->map_x;
			ray->door.v_door_open_y = ray->map_y;
			ray->door.distance_to_open_v = get_distance(ray->player_posx,
					ray->player_posy, ray->vx, ray->vy);
			ray->door.took_nearest_door_v = true;
		}
	}
}

/* si la distance est assez loin mais pas trop proche de la porte ouverte
alors je peux louvrir */
void	init_door_open_v(t_ray *ray)
{
	if (ray->door.is_door_open_v == IS_DOOR_VERTICAL)
	{
		if (ray->door.distance_to_open_v <= DISTANCE_TO_CLOSE_DOOR
			&& ray->door.distance_to_open_v > MINI_PLAYER_SIZE / 2
			+ SECURITY_DISTANCE)
		{
			ray->door.can_close_door = true;
			ray->door.door_open_x = ray->door.v_door_open_x;
			ray->door.door_open_y = ray->door.v_door_open_y;
		}
	}
}

void	door_open_handling_h(t_parsing *info, t_ray *ray)
{
	if (ray->map_pos < info->max_x * info->max_y
		&& info->int_map[ray->map_pos] == DOOR_OPEN_INT)
	{
		ray->door.is_door_open_h = IS_DOOR_HORIZONTAL;
		if (ray->r == SIZE_X / 2 && !ray->door.took_nearest_door_h)
		{
			ray->door.h_door_open_x = ray->map_x;
			ray->door.h_door_open_y = ray->map_y;
			ray->door.distance_to_open_h = get_distance(ray->player_posx,
					ray->player_posy, ray->hx, ray->hy);
			ray->door.took_nearest_door_h = true;
		}
	}
}

/* ray->door.distance_to_open_h <= DISTANCE_TO_CLOSE_DOOR
			&& ray->door.distance_to_open_h > MINI_PLAYER_SIZE / 2
			+ SECURITY_DISTANCE)
tout ca cest pour mettre une distance de securite pour fermer la porte */
void	init_door_open_h(t_ray *ray)
{
	if (ray->door.is_door_open_h == IS_DOOR_HORIZONTAL)
	{
		if (ray->door.distance_to_open_h <= DISTANCE_TO_CLOSE_DOOR
			&& ray->door.distance_to_open_h > MINI_PLAYER_SIZE / 2
			+ SECURITY_DISTANCE)
		{
			ray->door.can_close_door = true;
			ray->door.door_open_x = ray->door.h_door_open_x;
			ray->door.door_open_y = ray->door.h_door_open_y;
		}
	}
}

bool	is_door_closed_or_wall(t_parsing *info, t_ray *ray)
{
	return (ray->map_pos < info->max_x * info->max_y
		&& (info->int_map[ray->map_pos] == 1
			|| info->int_map[ray->map_pos] == DOOR_CLOSED_INT));
}
