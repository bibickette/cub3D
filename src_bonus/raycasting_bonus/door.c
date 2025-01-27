/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:20:24 by phwang            #+#    #+#             */
/*   Updated: 2025/01/27 22:30:15 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	door_handling(t_parsing *info, t_ray *ray, int direction)
{
	if (info->int_map[ray->map_pos] == DOOR_CLOSE_INT)
	{
		if (direction == HORIZONTAL)
			ray->door.is_door_closed_h = IS_DOOR_HORIZONTAL;
		else
			ray->door.is_door_closed_v = IS_DOOR_VERTICAL;
		// la porte quon voit au milieu de lecran est la porte quon peut ouvrir
		if (ray->r == SIZE_X / 2)
		{
			if (direction == HORIZONTAL)
			{
				ray->door.h_door_closed_x = ray->map_x;
				ray->door.h_door_closed_y = ray->map_y;
			}
			else
			{
				ray->door.v_door_closed_x = ray->map_x;
				ray->door.v_door_closed_y = ray->map_y;
			}
		}
	}
}

bool	is_door_or_wall(t_parsing *info, t_ray *ray)
{
	return (ray->map_pos < info->max_x * info->max_y
		&& (info->int_map[ray->map_pos] == 1
			|| info->int_map[ray->map_pos] == DOOR_CLOSE_INT));
}
