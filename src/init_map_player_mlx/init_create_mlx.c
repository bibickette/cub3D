/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_create_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:29:01 by phwang            #+#    #+#             */
/*   Updated: 2025/01/14 10:19:06 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	create_background(t_mlx *mlx, unsigned int floor_color,
		unsigned int ceiling_color)
{
	int	x;
	int	y;

	mlx->background.mlx_img = mlx_new_image(mlx->mlx_ptr, SIZE_X, SIZE_Y);
	if (!mlx->background.mlx_img)
		return (print_error(MLX_IMG_ERR, NULL), false);
	mlx->background.addr = mlx_get_data_addr(mlx->background.mlx_img,
			&mlx->background.bpp, &mlx->background.line_len,
			&mlx->background.endian);
	if (!mlx->background.addr)
		return (print_error(MLX_GET_DATA_ADDR_ERR, NULL), false);
	y = -1;
	while (++y < SIZE_Y / 2)
	{
		x = -1;
		while (++x < SIZE_X)
			my_mlx_pixel_put(mlx->background, y, x, ceiling_color);
	}
	while (++y < SIZE_Y)
	{
		x = -1;
		while (++x < SIZE_X)
			my_mlx_pixel_put(mlx->background, y, x, floor_color);
	}
	return (true);
}

static bool	create_backup(t_mlx *mlx)
{
	int				y;
	int				x;
	unsigned int	color;

	mlx->backup.mlx_img = mlx_new_image(mlx->mlx_ptr, SIZE_X, SIZE_Y);
	if (!mlx->backup.mlx_img)
		return (print_error(MLX_IMG_ERR, NULL), false);
	mlx->backup.addr = mlx_get_data_addr(mlx->backup.mlx_img, &mlx->backup.bpp,
			&mlx->backup.line_len, &mlx->backup.endian);
	if (!mlx->backup.addr)
		return (print_error(MLX_GET_DATA_ADDR_ERR, NULL), false);
	y = -1;
	while (++y < SIZE_Y)
	{
		x = -1;
		while (++x < SIZE_X)
		{
			color = *(unsigned int *)(mlx->background.addr + y
					* mlx->background.line_len + x * (mlx->background.bpp / 8));
			my_mlx_pixel_put(mlx->backup, y, x, color);
		}
	}
	return (true);
}

bool	init_create_mlx(t_parsing *info)
{
	int	screen_width;
	int	screen_height;

	info->mlx.mlx_ptr = mlx_init();
	if (!info->mlx.mlx_ptr)
		return (print_error(MLX_INIT_ERR, NULL), false);
	if (!create_background(&info->mlx, info->textures.floor_color,
			info->textures.ceiling_color))
		return (false);
	if (!create_backup(&info->mlx))
		return (false);
	mlx_get_screen_size(info->mlx.mlx_ptr, &screen_width, &screen_height);
	if (SIZE_X > screen_width || SIZE_Y > screen_height)
		return (print_error(SCREEN_SIZE_ERR, NULL), false);
	info->mlx.win_ptr = mlx_new_window(info->mlx.mlx_ptr, SIZE_X, SIZE_Y,
			TITLE);
	if (!info->mlx.win_ptr)
		return (print_error(MLX_NEW_WIN_ERR, NULL), false);
	if (!load_texture(info))
		return (false);
	return (true);
}
