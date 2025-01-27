/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:35:35 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/27 15:20:53 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_start_with_id(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	if (!ft_strncmp(&line[i], "NO ", 3))
		return (NORTH);
	if (ft_strnstr(&line[i], "SO ", 3))
		return (SOUTH);
	if (ft_strnstr(&line[i], "EA ", 3))
		return (EAST);
	if (ft_strnstr(&line[i], "WE ", 3))
		return (WEST);
	if (ft_strnstr(&line[i], "F ", 2))
		return (FLOOR);
	if (ft_strnstr(&line[i], "C ", 2))
		return (CEILING);
	return (0);
}

static bool	is_valid_rgb_value(int rgb[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (rgb[i] < 0 || rgb[i] > 255)
			return (print_error(RGB_VALUE, NULL), false);
		i++;
	}
	return (true);
}

bool	is_valid_file_and_rgb(t_parsing *info)
{
	int	i;

	i = -1;
	if (!is_valid_rgb_value(info->textures.floor_rgb)
		|| !is_valid_rgb_value(info->textures.ceiling_rgb))
		return (false);
	info->textures.floor_color = rgb_to_uint(info->textures.floor_rgb);
	info->textures.ceiling_color = rgb_to_uint(info->textures.ceiling_rgb);
	while (++i < 4)
	{
		if (is_invalid_file_format(info->textures.walls[i].path_to_img, ".xpm")
			|| !is_file_readable(info->textures.walls[i].path_to_img))
			return (false);
	}
	return (true);
}
