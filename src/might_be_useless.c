/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   might_be_useless.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:07:28 by phwang            #+#    #+#             */
/*   Updated: 2025/01/14 18:37:59 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	draw_mini_line(t_parsing *info, unsigned int color, int replace,
// 		float line_length)
// {
// 	float	i;
// 	int		x;
// 	int		y;

// 	i = 0;
// 	x = info->player.pos_x + MINI_PLAYER_SIZE / 2 + i * cos(info->player.angle);
// 	y = info->player.pos_y + MINI_PLAYER_SIZE / 2 + i * sin(info->player.angle);
// 	while (i < line_length)
// 	{
// 		x = info->player.pos_x + MINI_PLAYER_SIZE / 2 + i
// 			* cos(info->ray.angle);
// 		y = info->player.pos_y + MINI_PLAYER_SIZE / 2 + i
// 			* sin(info->ray.angle);
// 		if ((x < 0 || x >= SIZE_X || y < 0 || y >= SIZE_Y))
// 			break;
// 		my_mlx_pixel_put(*(info->mlx.current_background), y, x, color);
// 		i++;
// 	}
// }
