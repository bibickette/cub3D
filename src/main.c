/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:55:58 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/13 14:32:34 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_mlx(t_mlx *mlx)
{
	if (mlx->background.mlx_img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->background.mlx_img);
	if (mlx->backup.mlx_img)
		mlx_destroy_image(mlx->mlx_ptr, mlx->backup.mlx_img);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
		mlx_destroy_display(mlx->mlx_ptr);
	if (mlx->mlx_ptr)
		free(mlx->mlx_ptr);
}
void	my_mlx_pixel_put(t_img img, int y, int x, unsigned int color)
{
	char	*pixel;

	pixel = img.addr + y * img.line_len + x * (img.bpp / 8);
	*(unsigned int *)pixel = color;
}

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

void	put_backup_player(t_mlx *mlx, int where_x, int where_y)
{
	unsigned int	color;
	char			*pixel;
	int				x;
	int				y;

	y = -1;
	while (++y < MINI_PLAYER_SIZE)
	{
		x = -1;
		while (++x < MINI_PLAYER_SIZE)
		{
			color = *(unsigned int *)(mlx->backup.addr + (((y + where_y
								* MINI_PLAYER_SIZE) * mlx->backup.line_len + (x
								+ where_x * MINI_PLAYER_SIZE)
							* ((mlx->backup.bpp / 8)))));
			pixel = mlx->background.addr + ((y + where_y * MINI_PLAYER_SIZE)
					* mlx->background.line_len + (x + where_x
						* MINI_PLAYER_SIZE) * (mlx->background.bpp / 8));
			if (!(color == (unsigned int)0xFF000000))
				*(unsigned int *)pixel = color;
		}
	}
}

void	draw_player(t_mlx *mlx, t_player *player, unsigned int color)
{
	int	x;
	int	y;

	y = -1;
	while (++y < MINI_PLAYER_SIZE)
	{
		x = -1;
		while (++x < MINI_PLAYER_SIZE)
			my_mlx_pixel_put(mlx->background, y + player->pix_y, x
				+ player->pix_x, color);
	}
}

bool	init_mlx(t_mlx *mlx, t_player player)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (print_error(MLX_INIT_ERR, NULL), false);
	if (!create_background(mlx))
		return (printf("pouet\n"), false);
	if (!create_backup(mlx))
		return (printf("pouet\n"), false);
	// draw_player(mlx, &player, YELLOW);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, SIZE_X, SIZE_Y, TITLE);
	if (!mlx->win_ptr)
		return (print_error(MLX_NEW_WIN_ERR, NULL), false);
	return (true);
}

int	display(t_parsing *info)
{
	draw_player(&info->mlx, &info->player, YELLOW);
	mlx_put_image_to_window(info->mlx.mlx_ptr, info->mlx.win_ptr,
		info->mlx.background.mlx_img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_parsing	info;

	if (!initialization_all(&info, argc, argv))
		return (1);
	if (!init_mlx(&info.mlx, info.player))
		return (1);
	mlx_key_hook(info.mlx.win_ptr, &handle_key, &info);
	mlx_hook(info.mlx.win_ptr, DestroyNotify, 0, &cross_exit, &info);
	mlx_loop_hook(info.mlx.mlx_ptr, &display, &info);
	// mlx_put_image_to_window(info.mlx.mlx_ptr, info.mlx.win_ptr,
	// 	info.mlx.background.mlx_img, 0, 0);
	mlx_loop(info.mlx.mlx_ptr);
	return (0);
}
