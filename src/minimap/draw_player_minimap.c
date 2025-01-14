/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_minimap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:05:45 by phwang            #+#    #+#             */
/*   Updated: 2025/01/14 11:09:54 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_player_on_minimap(t_parsing *info, unsigned int color, int replace)
{
	int	x;
	int	y;

	y = -1;
	while (++y < MINI_PLAYER_SIZE)
	{
		x = -1;
		while (++x < MINI_PLAYER_SIZE)
		{
			if (replace)
			{
				if (info->player.last_pos_x + x < SIZE_X
					&& info->player.last_pos_x + x > 0
					&& info->player.last_pos_y + y < SIZE_Y
					&& info->player.last_pos_y + y > 0)
					color = get_backup_color(info->mlx.backup,
							info->player.last_pos_x + x, info->player.last_pos_y
							+ y);
			}
			my_mlx_pixel_put(info->mlx.background, y + info->player.pos_y, x
				+ info->player.pos_x, color);
		}
	}
}

// static void	draw_mini_map_square(t_img img, int x, int y,
// 		unsigned int color)
// {
// 	int	i;
// 	int	j;

// 	i = -1;
// 	while (++i < MINI_MAP_SIZE)
// 	{
// 		j = -1;
// 		while (++j < MINI_MAP_SIZE)
// 			my_mlx_pixel_put(img, y + i, x + j, color);
// 	}
// }

// void	draw_mini_map(t_parsing *info)
// {
// 	int	x;
// 	int	y;
// 	int	len_max_x;

// 	y = -1;
// 	x = 0;
// 	while (info->map[++y])
// 	{
// 		x = -1;
// 		while (++x < info->max_x)
// 		{
// 			len_max_x = ft_strlen(info->map[y]);
// 			if (x < len_max_x && info->map[y][x] == '1')
// 			{
// 				draw_mini_map_square(info->mlx.background, x * MINI_MAP_SIZE
// 					+ MINI_MAP_LOC_X, y * MINI_MAP_SIZE + MINI_MAP_LOC_Y,
// 					WHITE);
// 			}
// 			else if (x < len_max_x && (info->map[y][x] == '0'
// 				|| is_player(info->map[y][x])))
// 			{
// 				draw_mini_map_square(info->mlx.background, x * MINI_MAP_SIZE
// 					+ MINI_MAP_LOC_X, y * MINI_MAP_SIZE + MINI_MAP_LOC_Y,
// 					BLACK);
// 			}
// 		}
// 	}
// }
