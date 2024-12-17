/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:07:29 by phwang            #+#    #+#             */
/*   Updated: 2024/12/17 16:34:23 by phwang           ###   ########.fr       */
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
			if (x > info->max_x)
				info->max_x = x;
		}
	}
	info->max_y = y;
}

bool	is_valid_map(t_parsing *info)
{
	int	last_tab;

	last_tab = 0;
	if (!init_player(info->map, &info->player))
		return (false);
	if (!check_first_last_line(info->map, &last_tab))
		return (false);
	if (!is_everything_surrounded(info->map, last_tab))
		return (false);
	create_corner_walls(info->map, last_tab);
	set_max_map(info);
	return (true);
}
