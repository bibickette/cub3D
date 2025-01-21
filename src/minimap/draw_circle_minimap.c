/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle_minimap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:49:34 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/21 14:23:42 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	draw_circle_map(t_parsing *info, int radius, int color)
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
				my_mlx_pixel_put(*info->mlx.current_background, MINI_MAP_CENTER
					+ x, MINI_MAP_CENTER + y, color);
			x++;
		}
		y++;
	}
}

void	draw_mini_map(t_parsing *info)
{
	draw_circle_map(info, MINI_MAP_RAY_BORDER, OTHER_PINK);
	draw_circle_map(info, MINI_MAP_RAY, info->textures.floor_color);
	draw_player_arrow(info);
}
