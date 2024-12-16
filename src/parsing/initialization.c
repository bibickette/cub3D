/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:23:45 by phwang            #+#    #+#             */
/*   Updated: 2024/12/16 19:07:31 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_info(t_parsing *info)
{
	ft_memset(info, 0, sizeof(t_parsing));
	ft_memset(&info->player, 0, sizeof(t_player));
	ft_memset(&info->mlx, 0, sizeof(t_mlx));
	ft_memset(info->textures.floor_rgb, -1, sizeof(int) * 3);
	ft_memset(info->textures.ceiling_rgb, -1, sizeof(int) * 3);
}

bool	initialization_all(t_parsing *info, int argc, char **argv)
{
	init_info(info);
	if (!is_valid_arguments(argc, argv))
		return (false);
	if (!is_valid_data(info, argv[1]))
		return (destroy_info(info), false);
	return (true);
}

bool	init_create_mlx(t_parsing *info)
{
	info->mlx.mlx_ptr = mlx_init();
	if (!info->mlx.mlx_ptr)
		return (print_error(MLX_INIT_ERR, NULL), false);
	if (!create_background(&info->mlx))
		return (false);
	draw_map(info);
	// draw_line_on_map(info, info->mlx.background);
	if (!create_backup(&info->mlx))
		return (false);
	info->mlx.win_ptr = mlx_new_window(info->mlx.mlx_ptr, SIZE_X, SIZE_Y,
			TITLE);
	if (!info->mlx.win_ptr)
		return (print_error(MLX_NEW_WIN_ERR, NULL), false);
	return (true);
}
