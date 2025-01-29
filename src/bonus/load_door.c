/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_door.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/25 18:25:47 by phwang            #+#    #+#             */
/*   Updated: 2025/01/28 14:20:26 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	set_color_door(t_texture *textures, t_door *door)
{
	int	middle_rgb[3];
	int	open_rgb[3];
	int	close_rgb[3];

	rgb_mix_colors(textures->floor_rgb, textures->ceiling_rgb, middle_rgb);
	rgb_mix_colors(textures->floor_rgb, middle_rgb, open_rgb);
	rgb_mix_colors(textures->ceiling_rgb, middle_rgb, close_rgb);
	door->door_closed_color = rgb_to_uint(close_rgb);
	door->door_open_color = rgb_to_uint(open_rgb);
}

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
	reset_can_took_door(&info->ray.door);
	reset_is_door(&info->ray.door);
	set_color_door(&info->textures, &info->ray.door);
	return (true);
}
