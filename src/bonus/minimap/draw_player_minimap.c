/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_minimap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:05:45 by phwang            #+#    #+#             */
/*   Updated: 2025/01/28 15:16:29 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_player_on_minimap(t_parsing *info, unsigned int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < PLAYER_SIZE_MINIMAP)
	{
		x = -1;
		while (++x < PLAYER_SIZE_MINIMAP)
		{
			my_mlx_pixel_put(*(info->mlx.current_background), MINI_MAP_CENTER
				- PLAYER_SIZE_MINIMAP / 2 + y, MINI_MAP_CENTER
				- PLAYER_SIZE_MINIMAP / 2 + x, color);
		}
	}
}
