/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naphy <naphy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:55:58 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/28 20:26:52 by naphy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_parsing	info;

	if (!initialization_all_bonus(&info, argc, argv))
		return (1);
	if (!init_create_mlx(&info) || !load_door(&info) || !load_sprite(&info))
		return (destroy_info(&info), destroy_mlx(&info.mlx), 1);
	display_intro();
	display_bonus(&info);
	mlx_hook(info.mlx.win_ptr, KeyPress, KeyPressMask, &key_press_bonus, &info);
	mlx_hook(info.mlx.win_ptr, KeyRelease, KeyReleaseMask, &key_release_bonus,
		&info);
	mlx_hook(info.mlx.win_ptr, DestroyNotify, 0, &cross_exit, &info);
	mlx_loop_hook(info.mlx.mlx_ptr, &display_bonus, &info);
	mlx_loop(info.mlx.mlx_ptr);
	return (0);
}
