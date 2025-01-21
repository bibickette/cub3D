/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:41:34 by phwang            #+#    #+#             */
/*   Updated: 2025/01/21 14:20:00 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_on_minimap(int x, int y)
{
	int	dx;
	int	dy;

	dy = y - MINI_MAP_CENTER;
	dx = x - MINI_MAP_CENTER;
	if ((dx * dx + dy * dy) < (MINI_MAP_RAY_BORDER * MINI_MAP_RAY_BORDER))
		return (true);
	return (false);
}
