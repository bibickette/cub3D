/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   might_be_useless.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naphy <naphy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:07:28 by phwang            #+#    #+#             */
/*   Updated: 2025/01/28 20:27:44 by naphy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
// 			break ;
// 		my_mlx_pixel_put(*(info->mlx.current_background), y, x, color);
// 		i++;
// 	}
// }

// dessine un cadrillage en fonction de la taille dun carré
// // defini par SCALE
// static void	draw_line(t_img img, int x, int y, int flag)
// {
// 	int	i;
// 	int	size;

// 	i = -1;
// 	size = 0;
// 	if (flag == VERTICAL)
// 		size = SCALE;
// 	else if (flag == HORIZONTAL)
// 	{
// 		size = x * SCALE;
// 		x = 0;
// 	}
// 	while (++i < size)
// 	{
// 		if (flag == HORIZONTAL && (y * SCALE != 0) && (y * SCALE != size - 1))
// 			my_mlx_pixel_put(img, y * SCALE, x * SCALE + i, PINK);
// 		else if (flag == VERTICAL && (x * SCALE != 0) && (x * SCALE != SCALE
// 				- 1))
// 			my_mlx_pixel_put(img, y * SCALE + i, x * SCALE, RED);
// 	}
// }

// // dessine les lignes si besoin
// void	draw_line_on_map(t_parsing *info, t_img img)
// {
// 	int	x;
// 	int	y;

// 	y = -1;
// 	x = 0;
// 	while (info->map[++y])
// 	{
// 		x = -1;
// 		while (++x < info->max_x)
// 			draw_line(img, x, y, VERTICAL);
// 		draw_line(img, x, y, HORIZONTAL);
// 	}
// }

// static int	is_positive_direction(int start, int end)
// {
// 	if (start < end)
// 		return (1);
// 	return (-1);
// }

// static void	init_delta_step(t_parsing *info, int end_x, int end_y,
	//		int *error)
// {
// 	info->arrow.delta_x = abs(end_x - MINI_MAP_CENTER);
// 	info->arrow.delta_y = abs(end_y - MINI_MAP_CENTER);
// 	info->arrow.step_x = is_positive_direction(MINI_MAP_CENTER, end_x);
// 	info->arrow.step_y = is_positive_direction(MINI_MAP_CENTER, end_y);
// 	*error = info->arrow.delta_x - info->arrow.delta_y;
// }

// static void	draw_line_arrow(t_parsing *info, int end_x, int end_y)
// {
// 	int	error;
// 	int	double_error;
// 	int	sx;
// 	int	sy;

// 	sx = MINI_MAP_CENTER;
// 	sy = MINI_MAP_CENTER;
// 	init_delta_step(info, end_x, end_y, &error);
// 	while (1)
// 	{
// 		my_mlx_pixel_put(*info->mlx.current_background, sy, sx, OTHER_PINK);
// 		if (sx == end_x && sy == end_y)
// 			break ;
// 		double_error = error * 2;
// 		if (double_error > -info->arrow.delta_y)
// 		{
// 			error -= info->arrow.delta_y;
// 			sx += info->arrow.step_x;
// 		}
// 		if (double_error < info->arrow.delta_x)
// 		{
// 			error += info->arrow.delta_x;
// 			sy += info->arrow.step_y;
// 		}
// 	}
// }

// void	draw_player_arrow(t_parsing *info)
// {
// 	int		base_offset_end_x;
// 	int		base_offset_end_y;
// 	int		end_x;
// 	int		end_y;
// 	float	triangle_dr;

// 	triangle_dr = PLAYER_ANGLE_WIDTH;
// 	base_offset_end_x = (PLAYER_SIZE_MINIMAP * 3) * cos(-info->player.angle
// 			+ PLAYER_ANGLE_WIDTH);
// 	base_offset_end_y = (PLAYER_SIZE_MINIMAP * 3) * -sin(-info->player.angle
// 			+ PLAYER_ANGLE_WIDTH);
// 	end_x = MINI_MAP_CENTER + base_offset_end_x;
// 	end_y = MINI_MAP_CENTER + base_offset_end_y;
// 	while (triangle_dr > -PLAYER_ANGLE_WIDTH)
// 	{
// 		draw_line_arrow(info, end_x, end_y);
// 		base_offset_end_x = (PLAYER_SIZE_MINIMAP * 3) * cos(-info->player.angle
// 				+ triangle_dr);
// 		base_offset_end_y = (PLAYER_SIZE_MINIMAP * 3) * -sin(-info->player.angle
// 				+ triangle_dr);
// 		end_x = MINI_MAP_CENTER + base_offset_end_x;
// 		end_y = MINI_MAP_CENTER + base_offset_end_y;
// 		triangle_dr -= 0.01;
// 	}
// }
