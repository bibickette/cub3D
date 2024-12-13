/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:05:45 by phwang            #+#    #+#             */
/*   Updated: 2024/12/13 16:30:09 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img img, int y, int x, unsigned int color)
{
	char	*pixel;

	pixel = img.addr + y * img.line_len + x * (img.bpp / 8);
	*(unsigned int *)pixel = color;
}

void put_cube(t_img img, int x, int y, int size, unsigned int color)
{
	int i;
	int j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			my_mlx_pixel_put(img, y + i, x + j, color);
			j++;
		}
		i++;
	}
}

void	draw_map(t_parsing *info, unsigned int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < info->max_y)
	{
		x = -1;
		while (++x < info->max_x)
		{
			if (info->map[y][x] == '1')
				put_cube(info->mlx.background, x * (SIZE_X / 2 / info->max_x), y * (SIZE_Y / info->max_y), SIZE_X / 2 / info->max_x , WHITE);
			else if(info->map[y][x] == '0')
				put_cube(info->mlx.background, x * (SIZE_X / 2 / info->max_x), y * (SIZE_Y / info->max_y), SIZE_X / 2 / info->max_x , BLACK);
			else 
				put_cube(info->mlx.background, x * (SIZE_X / 2 / info->max_x), y * (SIZE_Y / info->max_y), SIZE_X / 2 / info->max_x , BLACK);
			
		}
	}
}

void	draw_player(t_mlx *mlx, t_player *player, unsigned int color, int replace)
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
				color = *(unsigned int *)(mlx->backup.addr + (y +player->last_pix_y)
					* mlx->backup.line_len + (x + player->last_pix_x) * (mlx->backup.bpp / 8));
			}
			my_mlx_pixel_put(mlx->background, y + player->pix_y, x
				+ player->pix_x, color);
			
		}
	}
}
