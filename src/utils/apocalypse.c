/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apocalypse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:55:43 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/14 11:09:21 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		if (tab[i])
			free_n_set_null(&tab[i]);
	free(tab);
	tab = 0;
}

void	free_n_set_null(char **to_free)
{
	if (*to_free)
	{
		free(*to_free);
		*to_free = 0;
	}
}

void	destroy_textures(t_parsing *info)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (info->textures.walls[i].img.mlx_img)
			mlx_destroy_image(info->mlx.mlx_ptr,
				info->textures.walls[i].img.mlx_img);
		if (info->textures.walls[i].path_to_img)
			free_n_set_null(&info->textures.walls[i].path_to_img);
	}
}

void	destroy_info(t_parsing *info)
{
	int	i;

	i = -1;
	get_next_line(0, 1);
	destroy_textures(info);
	if (info->map)
		free_tab(info->map);
	free(info->int_map);
	info->int_map = 0;
}

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
