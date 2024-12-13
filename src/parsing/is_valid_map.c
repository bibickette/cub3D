/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:07:29 by phwang            #+#    #+#             */
/*   Updated: 2024/12/13 14:01:26 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

static bool	check_player_pos(char **map, t_player *player)
{
	int	i;
	int	j;
	int	player_count;

	player_count = 0;
	j = -1;
	while (map[++j])
	{
		i = -1;
		while (map[j][++i])
		{
			if (is_player(map[j][i]))
			{
				player->x = i;
				player->y = j;
				player->pix_x = PIX;
				player->pix_y = PIX;
				player->direction = map[j][i];
				player_count++;
			}
		}
	}
	if (player_count != 1)
		return (print_error(MAP_ERR, PLAYER_NB), false);
	return (true);
}

bool	is_valid_map(t_parsing *info)
{
	int	last_tab;

	last_tab = 0;
	if (!check_player_pos(info->map, &info->player))
		return (false);
	if (!check_first_last_line(info->map, &last_tab))
		return (false);
	if (!is_everything_surrounded(info->map, last_tab))
		return (false);
	create_corner_walls(info->map, last_tab);
	return (true);
}
