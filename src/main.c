/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:55:58 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/08 14:44:19 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_parsing	info;

	if (!initialization_all(&info, argc, argv))
		return (1);
	if (!init_create_mlx(&info))
		return (destroy_mlx(&info.mlx), destroy_info(&info), 1);
	print_map(info.map);
	print_map_int(info.int_map, info.max_x, info.max_y);
	print_player_info(info.player);
	display(&info);
	mlx_hook(info.mlx.win_ptr, KeyPress, KeyPressMask, &handle_key, &info);
	mlx_hook(info.mlx.win_ptr, DestroyNotify, 0, &cross_exit, &info);
	// mlx_loop_hook(info.mlx.mlx_ptr, &display, &info);
	// pk on garde pas ce mlx loop hook ? pk ya pas besoin ?
	mlx_loop(info.mlx.mlx_ptr);
	return (0);
}
