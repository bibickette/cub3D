/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   background.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:43:26 by phwang            #+#    #+#             */
/*   Updated: 2024/12/13 15:07:48 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	create_background(t_mlx *mlx)
{
	int	x;
	int	y;

	mlx->background.mlx_img = mlx_new_image(mlx->mlx_ptr, SIZE_X, SIZE_Y);
	if (!mlx->background.mlx_img)
		return (print_error(MLX_IMG_ERR, NULL), false);
	mlx->background.addr = mlx_get_data_addr(mlx->background.mlx_img,
			&mlx->background.bpp, &mlx->background.line_len,
			&mlx->background.endian);
	y = -1;
	while (++y < SIZE_Y)
	{
		x = -1;
		while (++x < SIZE_X)
			my_mlx_pixel_put(mlx->background, y, x, GREY);
	}
	return (true);
}

bool	create_backup(t_mlx *mlx)
{
	int				y;
	int				x;
	unsigned int	color;

	mlx->backup.mlx_img = mlx_new_image(mlx->mlx_ptr, SIZE_X, SIZE_Y);
	if (!mlx->backup.mlx_img)
		return (print_error(MLX_IMG_ERR, NULL), false);
	mlx->backup.addr = mlx_get_data_addr(mlx->backup.mlx_img, &mlx->backup.bpp,
			&mlx->backup.line_len, &mlx->backup.endian);
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
