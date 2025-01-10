/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:43:55 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/10 13:19:36 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	load_texture(t_parsing *info)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		info->textures.walls[i].img.mlx_img = mlx_xpm_file_to_image(info->mlx.mlx_ptr,
				info->textures.walls[i].path_to_img, &info->textures.walls[i].width, &info->textures.walls[i].height);
		if (!info->textures.walls[i].img.mlx_img)
			return (print_error(MLX_FILE_TO_IMG_ERR,
					info->textures.walls[i].path_to_img), false);
		info->textures.walls[i].img.addr = mlx_get_data_addr(info->textures.walls[i].img.mlx_img,
				&info->textures.walls[i].img.bpp,
				&info->textures.walls[i].img.line_len,
				&info->textures.walls[i].img.endian);
		if (!info->textures.walls[i].img.addr)
			return (print_error(MLX_GET_DATA_ADDR_ERR, NULL), false);
		i++;
	}
	return (true);
}
