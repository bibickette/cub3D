/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_utils_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:22:54 by phwang            #+#    #+#             */
/*   Updated: 2025/01/28 12:40:55 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

bool	is_everything_surrounded_bonus(char **map, int last_tab)
{
	int	i;
	int	j;

	j = 0;
	while (++j < last_tab)
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == '0' || is_player(map[j][i])
				|| map[j][i] == DOOR_CLOSED)
			{
				if (map[j][i - 1] == ' ' || map[j][i + 1] == ' ' || map[j
					- 1][i] == ' ' || map[j + 1][i] == ' ' || map[j][i
					+ 1] == '\n')
					return (print_error(MAP_ERR, WALL_ERR), false);
			}
		}
	}
	return (true);
}
