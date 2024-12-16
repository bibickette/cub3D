/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 18:35:38 by phwang            #+#    #+#             */
/*   Updated: 2024/12/16 19:01:08 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (true);
	return (false);
}

static void	set_angle_player(char c, t_player *player)
{
	// alors je sais pas pk mais ca tourne dans le sens 
	// anti horaire avec les vraies valeurs
	// donc jai mis en negatif et ca marche wtf
	if (c == 'N')
		player->angle = -(PI / 2);
	else if (c == 'S')
		player->angle = -(3 * PI / 2);
	else if (c == 'E')
		player->angle = 0;
	else if (c == 'W')
		player->angle = -(PI);
}

static void	player_setting(char **map, t_player *player, int pos_x, int pos_y)
{
	player->x = pos_x;
	player->y = pos_y;
	// place le pnj sur le milieu de la case qui lui correspond
	player->pos_x = pos_x * MINI_MAP_SIZE + MINI_MAP_LOC_X + MINI_MAP_SIZE / 2
		- MINI_PLAYER_SIZE / 2;
	player->pos_y = pos_y * MINI_MAP_SIZE + MINI_MAP_LOC_Y + MINI_MAP_SIZE / 2
		- MINI_PLAYER_SIZE / 2;
	set_angle_player(map[pos_y][pos_x], player);
	player->d_x = cos(player->angle) * 5;
	player->d_y = sin(player->angle) * 5;
}

bool	init_player(char **map, t_player *player)
{
	int	x;
	int	y;
	int	player_count;

	player_count = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (is_player(map[y][x]))
			{
				player_setting(map, player, x, y);
				player_count++;
			}
		}
	}
	if (player_count != 1)
		return (print_error(MAP_ERR, PLAYER_NB), false);
	return (true);
}
