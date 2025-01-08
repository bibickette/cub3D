/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:41:34 by phwang            #+#    #+#             */
/*   Updated: 2025/01/08 15:41:40 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_on_minimap(int x, int y, t_parsing *info)
{
	if (x >= MINI_MAP_LOC_X && x < MINI_MAP_LOC_X + MINI_MAP_SIZE * info->max_x
		&& y >= MINI_MAP_LOC_Y && y < MINI_MAP_LOC_Y + MINI_MAP_SIZE
		* info->max_y)
		return (true);
	return (false);
}
