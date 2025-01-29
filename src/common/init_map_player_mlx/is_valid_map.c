/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:07:29 by phwang            #+#    #+#             */
/*   Updated: 2025/01/28 13:47:52 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_max_map(t_parsing *info)
{
	int	x;
	int	y;

	y = -1;
	while (info->map[++y])
	{
		x = -1;
		while (info->map[y][++x])
		{
			if (info->map[y][x] == '1' && x + 1 > info->max_x)
				info->max_x = x + 1;
		}
	}
	info->max_y = y;
}

static bool	there_is_empty_line_in_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (map[i][0] == '\n')
			return (print_error(MAP_ERR, EMPTY_LINE), true);
	}
	return (false);
}

static bool	check_char_in_map(char **map)
{
	int	i;
	int	j;

	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] != '0' && map[j][i] != '1' && !is_player(map[j][i])
				&& map[j][i] != ' ' && map[j][i] != '\n')
				return (print_error(MAP_ERR, CHAR_ERR), false);
		}
	}
	return (true);
}

bool	is_valid_map(t_parsing *info)
{
	int	last_tab;

	last_tab = 0;
	if (there_is_empty_line_in_map(info->map))
		return (false);
	if (!check_char_in_map(info->map))
		return (false);
	if (!init_player(info->map, &info->player))
		return (false);
	if (!check_first_last_line(info->map, &last_tab))
		return (false);
	if (!is_everything_surrounded(info->map, last_tab))
		return (false);
	set_max_map(info);
	return (true);
}
