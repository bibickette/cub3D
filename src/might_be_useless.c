/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   might_be_useless.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:07:28 by phwang            #+#    #+#             */
/*   Updated: 2025/01/23 16:13:30 by phwang           ###   ########.fr       */
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
// 			break ;
// 		my_mlx_pixel_put(*(info->mlx.current_background), y, x, color);
// 		i++;
// 	}
// }

void	draw_player_on_minimap(t_parsing *info, unsigned int color, int replace)
{
	int	x;
	int	y;

	y = -1;
	while (++y < PLAYER_SIZE_MINIMAP)
	{
		x = -1;
		while (++x < PLAYER_SIZE_MINIMAP)
		{
			// printf("x = %d, y = %d\n", MINI_MAP_CENTER
			// 	- PLAYER_SIZE_MINIMAP / 2 + x, MINI_MAP_CENTER
			// 	- PLAYER_SIZE_MINIMAP / 2 + y);
			my_mlx_pixel_put(*(info->mlx.current_background), MINI_MAP_CENTER
				- PLAYER_SIZE_MINIMAP / 2 + y, MINI_MAP_CENTER
				- PLAYER_SIZE_MINIMAP / 2 + x, color);
		}
	}
}

static void	draw_mini_map_square(t_img img, int x, int y, unsigned int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MINI_MAP_SIZE)
	{
		j = -1;
		while (++j < MINI_MAP_SIZE)
		{
			if (is_on_minimap(x + j, y + i, MINI_MAP_RAY))
				my_mlx_pixel_put(img, y + i, x + j, color);
		}
	}
}

static int	square_pos(t_parsing *info, int pos, int flag)
{
	if (flag == POS_X)
		return (MINI_MAP_CENTER + pos * MINI_MAP_SIZE - (info->player.pos_x - 2)
			/ 2);
	return (MINI_MAP_CENTER + pos * MINI_MAP_SIZE - (info->player.pos_y - 2)
		/ 2);
}

void	draw_full_mini_map(t_parsing *info)
{
	int	x;
	int	y;
	int	len_max_x;

	y = -1;
	x = 0;
	while (info->map[++y])
	{
		x = -1;
		while (++x < info->max_x)
		{
			len_max_x = ft_strlen(info->map[y]);
			if (x < len_max_x && info->map[y][x] == '1')
			{
				draw_mini_map_square(*(info->mlx.current_background),
					square_pos(info, x, POS_X), square_pos(info, y, POS_Y),
					info->textures.ceiling_color);
			}
			else if (x < len_max_x && (info->map[y][x] == '0'
					|| is_player(info->map[y][x])))
			{
				draw_mini_map_square(*(info->mlx.current_background),
					square_pos(info, x, POS_X), square_pos(info, y, POS_Y),
					info->textures.floor_color);
			}
		}
	}
}
