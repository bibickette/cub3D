/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:41:34 by phwang            #+#    #+#             */
/*   Updated: 2025/01/25 19:23:13 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	is_on_minimap(int x, int y, int rayon)
{
	int	dx;
	int	dy;

	dy = y - MINI_MAP_CENTER;
	dx = x - MINI_MAP_CENTER;
	if ((dx * dx + dy * dy) < power_nb(rayon, 2))
		return (true);
	return (false);
}
