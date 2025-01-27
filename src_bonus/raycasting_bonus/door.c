/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 16:20:24 by phwang            #+#    #+#             */
/*   Updated: 2025/01/27 16:20:41 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	door_handling(t_parsing *info, t_ray *ray, int door_flag, int direction)
{
	if (info->int_map[ray->map_pos] == DOOR_CLOSE_INT)
	{
		if (direction == HORIZONTAL)
			ray->door.is_door_horizontal = door_flag;
		else
			ray->door.is_door_vertical = door_flag;
		if (ray->r == SIZE_X / 2)
		{
			if (direction == HORIZONTAL)
			{
				ray->door.horizontal_door_x = ray->map_x;
				ray->door.horizontal_door_y = ray->map_y;
			}
			else
			{
				ray->door.vertical_door_x = ray->map_x;
				ray->door.vertical_door_y = ray->map_y;
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
