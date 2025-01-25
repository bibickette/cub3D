/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_minimap.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:05:45 by phwang            #+#    #+#             */
/*   Updated: 2025/01/25 19:24:06 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	is_positive_direction(int start, int end)
{
	if (start < end)
		return (1);
	return (-1);
}

static void	init_delta_step(t_parsing *info, int end_x, int end_y, int *error)
{
	info->arrow.delta_x = abs(end_x - MINI_MAP_CENTER);
	info->arrow.delta_y = abs(end_y - MINI_MAP_CENTER);
	info->arrow.step_x = is_positive_direction(MINI_MAP_CENTER, end_x);
	info->arrow.step_y = is_positive_direction(MINI_MAP_CENTER, end_y);
	*error = info->arrow.delta_x - info->arrow.delta_y;
}

static void	draw_line_arrow(t_parsing *info, int end_x, int end_y)
{
	int	error;
	int	double_error;
	int	sx;
	int	sy;

	sx = MINI_MAP_CENTER;
	sy = MINI_MAP_CENTER;
	init_delta_step(info, end_x, end_y, &error);
	while (1)
	{
		my_mlx_pixel_put(*info->mlx.current_background, sy, sx, WHITE);
		if (sx == end_x && sy == end_y)
			break ;
		double_error = error * 2;
		if (double_error > -info->arrow.delta_y)
		{
			error -= info->arrow.delta_y;
			sx += info->arrow.step_x;
		}
		if (double_error < info->arrow.delta_x)
		{
			error += info->arrow.delta_x;
			sy += info->arrow.step_y;
		}
	}
}

void	draw_player_arrow(t_parsing *info)
{
	int		base_offset_end_x;
	int		base_offset_end_y;
	int		end_x;
	int		end_y;
	float	triangle_dr;

	triangle_dr = PLAYER_ANGLE_WIDTH;
	base_offset_end_x = (PLAYER_SIZE_MINIMAP * 3) * cos(-info->player.angle
			+ PLAYER_ANGLE_WIDTH);
	base_offset_end_y = (PLAYER_SIZE_MINIMAP * 3) * -sin(-info->player.angle
			+ PLAYER_ANGLE_WIDTH);
	end_x = MINI_MAP_CENTER + base_offset_end_x;
	end_y = MINI_MAP_CENTER + base_offset_end_y;
	while (triangle_dr > -PLAYER_ANGLE_WIDTH)
	{
		draw_line_arrow(info, end_x, end_y);
		base_offset_end_x = (PLAYER_SIZE_MINIMAP * 3) * cos(-info->player.angle
				+ triangle_dr);
		base_offset_end_y = (PLAYER_SIZE_MINIMAP * 3) * -sin(-info->player.angle
				+ triangle_dr);
		end_x = MINI_MAP_CENTER + base_offset_end_x;
		end_y = MINI_MAP_CENTER + base_offset_end_y;
		triangle_dr -= 0.01;
	}
}
