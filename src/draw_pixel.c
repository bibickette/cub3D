/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_pixel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:05:45 by phwang            #+#    #+#             */
/*   Updated: 2024/12/13 20:10:44 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img img, int y, int x, unsigned int color)
{
	char	*pixel;

	pixel = img.addr + y * img.line_len + x * (img.bpp / 8);
	*(unsigned int *)pixel = color;
}

void	put_cube(t_img img, int x, int y, int size, unsigned int color)
{
	int	i;
	int	j;

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
void	draw_line(t_img img, int x, int y, int size, int flag)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (flag == HORIZONTAL && y != 0 && y != size - 1)
			my_mlx_pixel_put(img, y, x + i, GREY);
		else if (flag == VERTICAL && x != 0 && x != size - 1)
			my_mlx_pixel_put(img, y + i, x, GREY);
		i++;
	}
}
// info->player.pos_x -= info->player.d_x;
// info->player.pos_y -= info->player.d_y;
// void	draw_mini_line(t_img img, float x, float y, int height, int width)
// {
// 	int	i;
// 	int j;

// 	i = 0;
// 	while (i < height)
// 	{
// 		j = 0;
// 		while(j < width)
// 		{
// 			// my pixel put img, y - player.d_y, x - player.d_x, YELLOW
// 			my_mlx_pixel_put(img, y + i, x + j, YELLOW);
// 			j++;
// 		}
// 		i++;
// 	}
// }

void	draw_mini_line(t_mlx *mlx, t_player *player, unsigned int color,
		int replace)
{
	int	i;
	int	j;
	int a,b;
	int	height;

	int x, y;
	height = 100;
	i = 0;
	a = player->pos_x + MINI_PLAYER_SIZE / 2 + i * cos(player->angle);
	b = player->pos_y + MINI_PLAYER_SIZE / 2 + i * sin(player->angle);
	while (i < height)
	{
		if (replace)
		{
			color = *(unsigned int *)(mlx->backup.addr + (
					 b) * mlx->backup.line_len + (
						a) * (mlx->backup.bpp / 8));
		} // my pixel put img, y - layer.d_y, x - player.d_x, YELLOW
		x = player->pos_x + MINI_PLAYER_SIZE / 2 + i * cos(player->angle);
		y = player->pos_y + MINI_PLAYER_SIZE / 2 + i * sin(player->angle);
		a = x;
		b = y;
		// x = player->pix_x + player->pos_x + i * cos(player->angle);
		// y = player->pix_y + player->pos_y + i * sin(player->angle);)
		my_mlx_pixel_put(mlx->background, y, x, color);
		i++;
	}
}

void	draw_map(t_parsing *info, unsigned int color)
{
	int	x;
	int	y;

	y = -1;
	x = 0;
	while (++y < info->max_y)
	{
		while (x < info->max_x)
		{
			if (info->map[y][x] == '1')
				put_cube(info->mlx.background, x * (SIZE_X / 2 / info->max_x), y
					* (SIZE_Y / info->max_y), SIZE_X / 2 / info->max_x, WHITE);
			else if (info->map[y][x] == '0')
				put_cube(info->mlx.background, x * (SIZE_X / 2 / info->max_x), y
					* (SIZE_Y / info->max_y), SIZE_X / 2 / info->max_x, BLACK);
			else
				put_cube(info->mlx.background, x * (SIZE_X / 2 / info->max_x), y
					* (SIZE_Y / info->max_y), SIZE_X / 2 / info->max_x, BLACK);
			// draw_line(info->mlx.background, x * (SIZE_X / 2 / info->max_x), y
			// 	* (SIZE_Y / info->max_y), SIZE_Y / info->max_y, VERTICAL);
			x++;
		}
		x = 0;
		// draw_line(info->mlx.background, x * (SIZE_X / 2 / info->max_x), y
		// 	* (SIZE_Y / info->max_y), SIZE_X, HORIZONTAL);
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
			if (replace)
			{
				color = *(unsigned int *)(mlx->backup.addr + (y
							+ player->last_pix_y) * mlx->backup.line_len + (x
							+ player->last_pix_x) * (mlx->backup.bpp / 8));
			}
			my_mlx_pixel_put(mlx->background, y + player->pos_y, x
				+ player->pos_x, color);
		}
	}
	draw_mini_line(mlx, player, color, replace);
	// draw_mini_line(mlx->background, player->pix_x + MINI_PLAYER_SIZE / 2
		// - 1 , player->pix_y + MINI_PLAYER_SIZE/2, 30, 2);
}
