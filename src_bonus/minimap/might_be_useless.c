/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   might_be_useless.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:07:28 by phwang            #+#    #+#             */
/*   Updated: 2025/01/25 17:33:06 by phwang           ###   ########.fr       */
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

// dessine un cadrillage en fonction de la taille dun carré
// defini par SCALE
static void	draw_line(t_img img, int x, int y, int flag)
{
	int	i;
	int	size;

	i = -1;
	size = 0;
	if (flag == VERTICAL)
		size = SCALE;
	else if (flag == HORIZONTAL)
	{
		size = x * SCALE;
		x = 0;
	}
	while (++i < size)
	{
		if (flag == HORIZONTAL && (y * SCALE != 0) && (y * SCALE != size - 1))
			my_mlx_pixel_put(img, y * SCALE, x * SCALE + i, PINK);
		else if (flag == VERTICAL && (x * SCALE != 0) && (x * SCALE != SCALE
				- 1))
			my_mlx_pixel_put(img, y * SCALE + i, x * SCALE, RED);
	}
}

// dessine les lignes si besoin
void	draw_line_on_map(t_parsing *info, t_img img)
{
	int	x;
	int	y;

	y = -1;
	x = 0;
	while (info->map[++y])
	{
		x = -1;
		while (++x < info->max_x)
			draw_line(img, x, y, VERTICAL);
		draw_line(img, x, y, HORIZONTAL);
	}
}
