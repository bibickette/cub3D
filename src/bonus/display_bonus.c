/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naphy <naphy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:19:37 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/28 20:35:18 by naphy            ###   ########.fr       */
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
			if (!is_on_minimap(x, y, MINI_MAP_RAY + MINI_MAP_BORDER))
				my_mlx_pixel_put(*(info->mlx.current_background), y, x,
					info->textures.ceiling_color);
		}
	}
	while (++y < SIZE_Y)
	{
		x = -1;
		while (++x < SIZE_X)
		{
			if (!is_on_minimap(x, y, MINI_MAP_RAY + MINI_MAP_BORDER))
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
		draw_mini_map(info);
		raycaster_bonus(&info->player, &info->ray, info);
		draw_animated_heart(info, NB_OF_HEARTS);
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
