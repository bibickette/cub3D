/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 13:43:55 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/15 13:01:32 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	load_texture(t_parsing *info)
{
	int		i;
	int		width;
	int		height;
	t_wall	*walls;

	walls = info->textures.walls;
	i = 0;
	while (i < 4)
	{
		walls[i].img.mlx_img = mlx_xpm_file_to_image(info->mlx.mlx_ptr,
				walls[i].path_to_img, &width, &height);
		if (!walls[i].img.mlx_img)
			return (print_error(MLX_FILE_TO_IMG_ERR, walls[i].path_to_img),
				false);
		if (width != (int)TEXTURE_SIZE || height != (int)TEXTURE_SIZE)
			return (print_error(IMG_SIZE_ERR, walls[i].path_to_img), false);
		walls[i].img.addr = mlx_get_data_addr(walls[i].img.mlx_img,
				&walls[i].img.bpp, &walls[i].img.line_len,
				&walls[i].img.endian);
		if (!walls[i].img.addr)
			return (print_error(MLX_GET_DATA_ADDR_ERR, NULL), false);
		i++;
	}
	return (true);
}
