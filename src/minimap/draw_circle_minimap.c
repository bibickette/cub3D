/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle_minimap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:49:34 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/21 14:04:38 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_circle_map(t_parsing *info, int xc, int yc, int radius)
{
	int	x;
	int	y;

	y = -radius;
	while (y < radius)
	{
		x = -radius;
		while (x < radius)
		{
			if (x * x + y * y < radius * radius)
				my_mlx_pixel_put(*info->mlx.current_background, xc + x, yc + y,
					BLACK);
			x++;
		}
		y++;
	}
}

void	draw_mini_map(t_parsing *info)
{
	draw_circle_map(info, MINI_MAP_CENTER, MINI_MAP_CENTER, MINI_MAP_RAY);
	draw_player_arrow(info);
}
