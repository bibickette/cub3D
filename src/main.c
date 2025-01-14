/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:55:58 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/14 11:08:06 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_ray(t_ray *ray)
{
	ray->rad_value = ((PI / 180) * FOV);
	ray->pi2 = (PI / 2);
	ray->pi3 = (3 * PI / 2);
}

int	main(int argc, char **argv)
{
	t_parsing	info;

	if (!initialization_all(&info, argc, argv))
		return (1);
	if (!init_create_mlx(&info))
		return (destroy_info(&info), destroy_mlx(&info.mlx), 1);
	init_ray(&info.ray);
	print_map(info.map);
	print_map_int(info.int_map, info.max_x, info.max_y);
	print_player_info(info.player);
	display(&info);
	mlx_hook(info.mlx.win_ptr, KeyPress, KeyPressMask, &handle_key, &info);
	mlx_hook(info.mlx.win_ptr, DestroyNotify, 0, &cross_exit, &info);
	mlx_loop(info.mlx.mlx_ptr);
	return (0);
}
