/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_circle_minimap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 13:49:34 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/25 17:18:15 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_circle_map(t_parsing *info, int radius, int color)
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
