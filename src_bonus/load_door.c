/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:25:47 by phwang            #+#    #+#             */
/*   Updated: 2025/01/28 12:45:00 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	load_door(t_parsing *info)
{
	int	width;
	int	height;

	ft_memset(&info->ray.door, 0, sizeof(t_door));
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
	info->keys.want_interact_w_door = false;
	info->ray.door.can_open_door = false;
	info->ray.door.is_door_closed_h = IS_NOT_DOOR;
	info->ray.door.is_door_closed_v = IS_NOT_DOOR;
	// la faire une fonction qui mixe pour une closed door et open door
	info->ray.door.door_closed_color = DOOR_COLOR;
	info->ray.door.door_open_color = 0x00FF00;
	return (true);
}
