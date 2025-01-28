/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naphy <naphy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 16:36:10 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/28 20:26:22 by naphy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	load_heart(t_parsing *info, char *path, t_img *heart)
{
	int	width;
	int	height;

	heart->mlx_img = mlx_xpm_file_to_image(info->mlx.mlx_ptr, path, &width,
			&height);
	if (!heart->mlx_img)
		return (print_error(MLX_FILE_TO_IMG_ERR, path), false);
	heart->addr = mlx_get_data_addr(heart->mlx_img, &heart->bpp,
			&heart->line_len, &heart->endian);
	if (!heart->addr)
		return (print_error(MLX_GET_DATA_ADDR_ERR, NULL), false);
	return (true);
}

bool	load_sprite(t_parsing *info)
{
	int	i;

	i = 0;
	while (i < SECOND_PART)
	{
		if (i < FIRST_PART)
		{
			if (!load_heart(info, SMALL_HEART_XPM, &info->hearts[i]))
				return (false);
		}
		else
		{
			if (!load_heart(info, BIG_HEART_XPM, &info->hearts[i]))
				return (false);
		}
		i++;
	}
	info->heart_size = SMALL_HEART;
	return (true);
}

static void	set_heart_size_and_frame(int *heart_frame, int *heart_size)
{
	*heart_frame += 1;
	if (*heart_frame >= FIRST_PART)
		*heart_size = BIG_HEART;
	if (*heart_frame == SECOND_PART)
	{
		*heart_frame = 0;
		*heart_size = SMALL_HEART;
	}
}

void	draw_sprite(t_parsing *info, int gap_x)
{
	int				heart_loc_x;
	int				heart_loc_y;
	int				i;
	int				j;
	unsigned int	color;

	heart_loc_x = SIZE_X - info->heart_size / 2 - gap_x;
	heart_loc_y = HEART_GAP - info->heart_size / 2;
	i = 0;
	j = 0;
	while (i < info->heart_size)
	{
		j = 0;
		while (j < info->heart_size)
		{
			color = get_backup_color(info->hearts[info->hearts_frame], j, i);
			if (color != WHITE)
				my_mlx_pixel_put(*info->mlx.current_background, heart_loc_y + i,
					heart_loc_x + j, color);
			j++;
		}
		i++;
	}
}

void	draw_animated_heart(t_parsing *info, int nb_of_hearts)
{
	int	i;

	i = 0;
	while (i < nb_of_hearts)
	{
		draw_sprite(info, HEART_GAP + i * BIG_HEART);
		i++;
	}
	set_heart_size_and_frame(&info->hearts_frame, &info->heart_size);
}
