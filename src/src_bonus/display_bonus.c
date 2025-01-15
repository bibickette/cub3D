/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:19:37 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/15 13:32:33 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	replace_background(t_parsing *info)
{
	int	y;
	int	x;

	y = -1;
	while (++y < SIZE_Y / 2)
	{
		x = -1;
		while (++x < SIZE_X)
		{
			my_mlx_pixel_put(*(info->mlx.current_background), y, x,
				info->textures.ceiling_color);
		}
	}
	while (++y < SIZE_Y)
	{
		x = -1;
		while (++x < SIZE_X)
		{
			my_mlx_pixel_put(*(info->mlx.current_background), y, x,
				info->textures.floor_color);
		}
	}
}

int	display_bonus(t_parsing *info)
{
	if (info->nb_frame >= FRAME_TIME)
	{
		handle_key_bonus(info);
		replace_background(info);
		raycaster(&info->player, &info->ray, info);
		mlx_put_image_to_window(info->mlx.mlx_ptr, info->mlx.win_ptr,
			info->mlx.current_background->mlx_img, 0, 0);
		if (info->mlx.current_background == &info->mlx.background)
			info->mlx.current_background = &info->mlx.background2;
		else
			info->mlx.current_background = &info->mlx.background;
		info->nb_frame = 0;
	}
	info->nb_frame++;
	return (0);
}
