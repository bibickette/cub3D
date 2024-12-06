/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:35:35 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/06 11:09:29 by fsalomon         ###   ########.fr       */
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
	if (ft_strnstr(&line[i], "F  ", 2))
		return (FLOOR);
	if (ft_strnstr(&line[i], "D ", 2))
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
			return (false);
		i++;
	}
	return (true);
}

bool	is_valid_file_and_rgb(t_parsing_data *info)
{
	if (!is_valid_rgb_value(info->floor_ceiling.floor_rgb))
		return (false);
	if (!is_valid_rgb_value(info->floor_ceiling.ceiling_rgb))
		return (false);
	if (!is_file_readable(info->walls.north.path_to_img)
		|| is_invalid_file_format(info->walls.north.path_to_img, ".xpm"))
		return (false);
	if (!is_file_readable(info->walls.south.path_to_img)
		|| is_invalid_file_format(info->walls.south.path_to_img, ".xpm"))
		return (false);
	if (!is_file_readable(info->walls.east.path_to_img)
		|| is_invalid_file_format(info->walls.east.path_to_img, ".xpm"))
		return (false);
	if (!is_file_readable(info->walls.west.path_to_img)
		|| is_invalid_file_format(info->walls.west.path_to_img, ".xpm"))
		return (false);
	return (true);
}
