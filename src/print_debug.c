/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanfan <fanfan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:52:00 by fanfan            #+#    #+#             */
/*   Updated: 2024/12/08 12:18:39 by fanfan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void print_map(char **map)
{
	int i = 0;

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
