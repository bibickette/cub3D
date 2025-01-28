/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_door.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:41:27 by phwang            #+#    #+#             */
/*   Updated: 2025/01/28 13:02:26 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	is_player_on_interacted_door(t_ray *ray)
{
	return ((((int)(ray->player_posy) / SCALE) != ray->door.door_open_y
		|| ((int)(ray->player_posx) / SCALE) != ray->door.door_open_x));
}

void	handle_open_close_door(t_parsing *info, t_door *door)
{
	int	door_pos;

	info->keys.want_interact_w_door = false;
	if (door->can_open_door)
	{
		door->can_open_door = false;
		if (info->map[door->door_closed_y][door->door_closed_x] == DOOR_CLOSED)
		{
			info->map[door->door_closed_y][door->door_closed_x] = DOOR_OPEN;
			door_pos = door->door_closed_y * info->max_x + door->door_closed_x;
			info->int_map[door_pos] = DOOR_OPEN_INT;
		}
	}
	else if (door->can_close_door && is_player_on_interacted_door(&info->ray))
	{
		door->can_close_door = false;
		if (info->map[door->door_open_y][door->door_open_x] == DOOR_OPEN)
		{
			info->map[door->door_open_y][door->door_open_x] = DOOR_CLOSED;
			door_pos = door->door_open_y * info->max_x + door->door_open_x;
			info->int_map[door_pos] = DOOR_CLOSED_INT;
		}
	}
}
