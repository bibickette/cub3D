/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:31:45 by phwang            #+#    #+#             */
/*   Updated: 2025/02/19 14:03:52 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static bool	get_map(int fd, char ***map)
{
	char	*line;

	line = get_next_line(fd, 0);
	if (!line)
		return (print_error(MAP_ERR, NO_MAP), false);
	else if (!is_white_space_line(line))
	{
		if (!char_add_back_tab(map, line))
			return (free_n_set_null(&line), false);
	}
	free_n_set_null(&line);
	while (1)
	{
		line = get_next_line(fd, 0);
		if (!line)
			break ;
		if (!is_white_space_line(line) || (*map))
			if (!char_add_back_tab(map, line))
				return (false);
		free_n_set_null(&line);
	}
	return (true);
}

bool	init_map_bonus(t_parsing *info, int fd)
{
	char	**map;

	map = NULL;
	if (!get_map(fd, &map))
		return (false);
	info->map = map;
	if (!info->map)
		return (false);
	if (!is_valid_map_bonus(info))
		return (false);
	info->int_map = convert_to_int_tab_bonus(info, info->map);
	if (!info->int_map)
		return (false);
	return (true);
}
