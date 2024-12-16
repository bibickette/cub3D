/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:05:45 by phwang            #+#    #+#             */
/*   Updated: 2024/12/16 19:05:17 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img img, int y, int x, unsigned int color)
{
	char	*pixel;

	pixel = img.addr + y * img.line_len + x * (img.bpp / 8);
	*(unsigned int *)pixel = color;
}

unsigned int	get_backup_color(t_img img, int x, int y)
{
	return (*(unsigned int *)(img.addr + y * img.line_len + x * (img.bpp / 8)));
}

void	draw_mini_map_square(t_img img, int x, int y, unsigned int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MINI_MAP_SIZE)
	{
		j = -1;
		while (++j < MINI_MAP_SIZE)
			my_mlx_pixel_put(img, y + i, x + j, color);
	}
}

void	draw_map(t_parsing *info)
{
	int	x;
	int	y;
	int	len_max_x;

	y = -1;
	x = 0;
	while (info->map[++y])
	{
		x = -1;
		// -1 car on ne veut pas dessiner une colonne vide
		while (++x < info->max_x)
		{
			// dessine en fonction de la taille du carré
			len_max_x = ft_strlen(info->map[y]);
			if (x < len_max_x && info->map[y][x] == '1')
			{
				draw_mini_map_square(info->mlx.background, x * MINI_MAP_SIZE
					+ MINI_MAP_LOC_X, y * MINI_MAP_SIZE + MINI_MAP_LOC_Y,
					WHITE);
			}
			else if (x < len_max_x && (info->map[y][x] == '0'
				|| is_player(info->map[y][x])))
			{
				draw_mini_map_square(info->mlx.background, x * MINI_MAP_SIZE
					+ MINI_MAP_LOC_X, y * MINI_MAP_SIZE + MINI_MAP_LOC_Y,
					BLACK);
			}
		}
	}
}

void	draw_player(t_mlx *mlx, t_player *player, unsigned int color,
		int replace)
{
	int	x;
	int	y;

	y = -1;
	while (++y < MINI_PLAYER_SIZE)
	{
		x = -1;
		while (++x < MINI_PLAYER_SIZE)
		{
			// protection anti hors de lecran
			if (y + player->pos_y < 0 || y + player->pos_y >= SIZE_Y || x
				+ player->pos_x < 0 || x + player->pos_x >= SIZE_X)
				break ;
			if (replace)
			{
				color = get_backup_color(mlx->backup, x + player->last_pos_x, y
						+ player->last_pos_y);
			}
			my_mlx_pixel_put(mlx->background, y + player->pos_y, x
				+ player->pos_x, color);
		}
	}
	draw_mini_line(mlx, player, color, replace);
}
