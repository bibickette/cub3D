/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:41:34 by phwang            #+#    #+#             */
/*   Updated: 2025/01/15 12:59:57 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_on_minimap(int x, int y, t_parsing *info)
{
	if (x >= MINI_MAP_LOC_X && x < MINI_MAP_LOC_X + SCALE * info->max_x
		&& y >= MINI_MAP_LOC_Y && y < MINI_MAP_LOC_Y + SCALE
		* info->max_y)
		return (true);
	return (false);
}
