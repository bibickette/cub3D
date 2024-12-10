/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:52:00 by fanfan            #+#    #+#             */
/*   Updated: 2024/12/10 14:05:20 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("%s", map[i]);
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
