/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:25:47 by phwang            #+#    #+#             */
/*   Updated: 2025/01/26 23:00:19 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	load_door(t_parsing *info)
{
	int	width;
	int	height;

	info->door.mlx_img = mlx_xpm_file_to_image(info->mlx.mlx_ptr, DOOR_FILE,
			&width, &height);
	if (!info->door.mlx_img)
		return (print_error(MLX_FILE_TO_IMG_ERR, DOOR_FILE), false);
	if (width != (int)TEXTURE_SIZE || height != (int)TEXTURE_SIZE)
		return (print_error(IMG_SIZE_ERR, DOOR_FILE), false);
	info->door.addr = mlx_get_data_addr(info->door.mlx_img, &info->door.bpp,
			&info->door.line_len, &info->door.endian);
	if (!info->door.addr)
		return (print_error(MLX_GET_DATA_ADDR_ERR, NULL), false);
	info->keys.want_to_open_door = false;
	info->ray.can_open_door = false;
	return (true);
}
