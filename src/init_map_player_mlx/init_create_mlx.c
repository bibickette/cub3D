/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_create_mlx.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:29:01 by phwang            #+#    #+#             */
/*   Updated: 2025/01/28 15:14:38 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_backgrounds(t_mlx *mlx, unsigned int floor_color,
		unsigned int ceiling_color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < SIZE_Y / 2)
	{
		x = -1;
		while (++x < SIZE_X)
		{
			my_mlx_pixel_put(mlx->background, y, x, ceiling_color);
			my_mlx_pixel_put(mlx->background2, y, x, ceiling_color);
		}
	}
	while (++y < SIZE_Y)
	{
		x = -1;
		while (++x < SIZE_X)
		{
			my_mlx_pixel_put(mlx->background, y, x, floor_color);
			my_mlx_pixel_put(mlx->background2, y, x, floor_color);
		}
	}
}

static bool	create_background(t_mlx *mlx, unsigned int floor_color,
		unsigned int ceiling_color)
{
	mlx->background.mlx_img = mlx_new_image(mlx->mlx_ptr, SIZE_X, SIZE_Y);
	if (!mlx->background.mlx_img)
		return (print_error(MLX_IMG_ERR, NULL), false);
	mlx->background.addr = mlx_get_data_addr(mlx->background.mlx_img,
			&mlx->background.bpp, &mlx->background.line_len,
			&mlx->background.endian);
	if (!mlx->background.addr)
		return (print_error(MLX_GET_DATA_ADDR_ERR, NULL), false);
	mlx->background2.mlx_img = mlx_new_image(mlx->mlx_ptr, SIZE_X, SIZE_Y);
	if (!mlx->background2.mlx_img)
		return (print_error(MLX_IMG_ERR, NULL), false);
	mlx->background2.addr = mlx_get_data_addr(mlx->background2.mlx_img,
			&mlx->background2.bpp, &mlx->background2.line_len,
			&mlx->background2.endian);
	if (!mlx->background2.addr)
		return (print_error(MLX_GET_DATA_ADDR_ERR, NULL), false);
	init_backgrounds(mlx, floor_color, ceiling_color);
	mlx->current_background = &mlx->background;
	return (true);
}

static void	init_ray(t_ray *ray)
{
	ray->rad_value = ((PI / 180) * FOV);
	ray->pi2 = (PI / 2);
	ray->pi3 = (3 * PI / 2);
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
	mlx_get_screen_size(info->mlx.mlx_ptr, &screen_width, &screen_height);
	if (SIZE_X > screen_width || SIZE_Y > screen_height)
		return (print_error(SCREEN_SIZE_ERR, NULL), false);
	info->mlx.win_ptr = mlx_new_window(info->mlx.mlx_ptr, SIZE_X, SIZE_Y,
			TITLE);
	if (!info->mlx.win_ptr)
		return (print_error(MLX_NEW_WIN_ERR, NULL), false);
	if (!load_texture(info))
		return (false);
	init_ray(&info->ray);
	return (true);
}
