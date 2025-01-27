/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:52:00 by fanfan            #+#    #+#             */
/*   Updated: 2025/01/27 16:10:21 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	printf("CHAR MAP :\n");
	while (map[i])
	{
		printf("%s", map[i]);
		i++;
	}
	printf("\n");
}

void	print_map_int(int *map, int max_x, int max_y)
{
	int	i;
	int	j;

	i = 0;
	printf("INT MAP :\n");
	while (i < max_y)
	{
		j = 0;
		while (j < max_x)
		{
			printf("%d", map[i * max_x + j]);
			j++;
		}
		printf("\n");
		i++;
	}
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
