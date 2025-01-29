/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_closed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:17:32 by phwang            #+#    #+#             */
/*   Updated: 2025/01/28 12:59:08 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/* la porte quon voit au milieu de lecran est la porte quon peut interagir */
/* je register la porte fermée horizontale et vertical */
float	door_closed_handling_v(t_parsing *info, t_ray *ray)
{
	if (info->int_map[ray->map_pos] == DOOR_CLOSED_INT)
	{
		ray->door.is_door_closed_v = IS_DOOR_VERTICAL;
		if (ray->r == SIZE_X / 2)
		{
			ray->door.v_door_closed_x = ray->map_x;
			ray->door.v_door_closed_y = ray->map_y;
		}
	}
	return (get_distance(ray->player_posx, ray->player_posy, ray->vx, ray->vy));
}

/* si la distance est bonne alors je peux ouvrir cette porte 
et je mets ses coordonnées dans la coord generale de la bonne porte */
void	init_door_closed_v(t_ray *ray, float ray_len)
{
	if (ray->door.is_door_closed_v == IS_DOOR_VERTICAL)
	{
		ray->id = DOOR_CLOSED_INT;
		if (ray_len <= DISTANCE_TO_OPEN_DOOR)
		{
			ray->door.can_open_door = true;
			ray->door.door_closed_x = ray->door.v_door_closed_x;
			ray->door.door_closed_y = ray->door.v_door_closed_y;
		}
	}
}

float	door_closed_handling_h(t_parsing *info, t_ray *ray)
{
	if (info->int_map[ray->map_pos] == DOOR_CLOSED_INT)
	{
		ray->door.is_door_closed_h = IS_DOOR_HORIZONTAL;
		if (ray->r == SIZE_X / 2)
		{
			ray->door.h_door_closed_x = ray->map_x;
			ray->door.h_door_closed_y = ray->map_y;
		}
	}
	return (get_distance(ray->player_posx, ray->player_posy, ray->hx, ray->hy));
}

void	init_door_closed_h(t_ray *ray, float ray_len)
{
	if (ray->door.is_door_closed_h == IS_DOOR_HORIZONTAL)
	{
		ray->id = DOOR_CLOSED_INT;
		if (ray_len <= DISTANCE_TO_OPEN_DOOR)
		{
			ray->door.can_open_door = true;
			ray->door.door_closed_x = ray->door.h_door_closed_x;
			ray->door.door_closed_y = ray->door.h_door_closed_y;
		}
	}
}
