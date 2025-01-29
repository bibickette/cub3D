/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_arg_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 12:23:45 by phwang            #+#    #+#             */
/*   Updated: 2025/01/14 10:16:17 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_info(t_parsing *info)
{
	ft_memset(info, 0, sizeof(t_parsing));
	info->int_map = NULL;
	ft_memset(&info->player, 0, sizeof(t_player));
	ft_memset(&info->mlx, 0, sizeof(t_mlx));
	ft_memset(&info->ray, 0, sizeof(t_ray));
	ft_memset(&info->textures, 0, sizeof(t_texture));
	ft_memset(info->textures.floor_rgb, -1, sizeof(int) * 3);
	ft_memset(info->textures.ceiling_rgb, -1, sizeof(int) * 3);
	ft_memset(info->textures.walls, 0, sizeof(t_wall) * 4);
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
