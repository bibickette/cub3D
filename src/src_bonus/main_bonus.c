/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:55:58 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/15 13:20:44 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_parsing	info;

	if (!initialization_all(&info, argc, argv))
		return (1);
	if (!init_create_mlx(&info))
		return (destroy_info(&info), destroy_mlx(&info.mlx), 1);
	print_map(info.map);
	print_map_int(info.int_map, info.max_x, info.max_y);
	print_player_info(info.player);
	display_bonus(&info);
	mlx_hook(info.mlx.win_ptr, KeyPress, KeyPressMask, &key_press_bonus, &info);
	mlx_hook(info.mlx.win_ptr, KeyRelease, KeyReleaseMask, &key_release_bonus, &info);
	mlx_hook(info.mlx.win_ptr, DestroyNotify, 0, &cross_exit, &info);
	mlx_loop_hook(info.mlx.mlx_ptr, &display_bonus, &info);
	mlx_loop(info.mlx.mlx_ptr);
	return (0);
}
