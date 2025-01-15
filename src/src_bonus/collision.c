/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:08:30 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/15 16:21:00 by fsalomon         ###   ########.fr       */
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
	if (map[y][x] && map[y][x] != '1')
		return (true);
	return (false);
}
