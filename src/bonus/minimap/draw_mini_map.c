/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:03:00 by phwang            #+#    #+#             */
/*   Updated: 2025/01/30 12:26:21 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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
		return ((pos * MINI_MAP_SIZE) - ((info->player.pos_x - 2) / 2)
			+ MINI_MAP_CENTER);
	return ((pos * MINI_MAP_SIZE) - ((info->player.pos_y - 2) / 2)
		+ MINI_MAP_CENTER);
}

static void	choose_which_wall(t_parsing *info, int x, int y)
{
	int	screen_x;
	int	screen_y;

	screen_x = square_pos(info, x, POS_X);
	screen_y = square_pos(info, y, POS_Y);
	if (info->map[y][x] == '1')
		draw_mini_map_square(*(info->mlx.current_background), screen_x,
			screen_y, info->textures.ceiling_color);
	else if (info->map[y][x] == '0')
		draw_mini_map_square(*(info->mlx.current_background), screen_x,
			screen_y, info->textures.floor_color);
	else if (info->map[y][x] == DOOR_CLOSED)
		draw_mini_map_square(*(info->mlx.current_background), screen_x,
			screen_y, info->ray.door.door_closed_color);
	else if (info->map[y][x] == DOOR_OPEN)
		draw_mini_map_square(*(info->mlx.current_background), screen_x,
			screen_y, info->ray.door.door_open_color);
}

// dessine les murs a la bonne position en fonction du joueur
// qui reste a la position MINIMAPCENTER
static void	draw_actual_mini_map(t_parsing *info)
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
			if (x < len_max_x)
				choose_which_wall(info, x, y);
		}
	}
}

void	draw_mini_map(t_parsing *info)
{
	draw_circle_map(info, MINI_MAP_RAY + MINI_MAP_BORDER, NUDE);
	draw_actual_mini_map(info);
	draw_player_on_minimap(info, OTHER_PINK);
}
