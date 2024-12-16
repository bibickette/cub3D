/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:52:00 by fanfan            #+#    #+#             */
/*   Updated: 2024/12/16 18:19:19 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s\n", map[i]);
		i++;
	}
	printf("\n");
}

void	print_texture(t_parsing *info)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		printf("path : %s\n", info->textures.walls[i].path_to_img);
		printf("id : %d\n", info->textures.walls[i].id);
	}
}

void	print_player_info(t_player player)
{
	printf("pos x : %d\n", player.x);
	printf("pos y : %d\n", player.y);
}
