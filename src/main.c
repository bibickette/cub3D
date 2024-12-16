/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:55:58 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/16 19:00:18 by phwang           ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_parsing	info;

	if (!initialization_all(&info, argc, argv))
		return (1);
	if (!init_create_mlx(&info))
		return (destroy_mlx(&info.mlx), destroy_info(&info), 1);
	mlx_hook(info.mlx.win_ptr, KeyPress, KeyPressMask, &handle_key, &info);
	mlx_hook(info.mlx.win_ptr, DestroyNotify, 0, &cross_exit, &info);
	mlx_loop_hook(info.mlx.mlx_ptr, &display, &info);
	mlx_loop(info.mlx.mlx_ptr);
	return (0);
}
