/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:08:30 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/27 16:48:55 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	is_possible_to_move(t_parsing *info, int x, int y)
{
	if (!is_possible_to_move_in_a_way(info->map, info->player.pos_x / SCALE, y))
		return (false);
	if (!is_possible_to_move_in_a_way(info->map, x, info->player.pos_y / SCALE))
		return (false);
	if (!is_possible_to_move_in_a_way(info->map, x, y))
		return (false);
	return (true);
}

bool	is_possible_to_move_in_a_way(char **map, int x, int y)
{
	if (map[y][x] && map[y][x] != '1' && map[y][x] != DOOR_CLOSED)
		return (true);
	return (false);
}
