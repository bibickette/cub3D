/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apocalypse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:55:43 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/06 14:15:35 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_n_set_null(char *to_free)
{
	if (to_free)
	{
		free(to_free);
		to_free = 0;
	}
}

void	apocalypse_parsing(t_parsing *info)
{
	int	i;

	i = -1;
	get_next_line(0, 1);
	while (++i < 4)
		if (info->textures.walls[i].path_to_img)
			free_n_set_null(info->textures.walls[i].path_to_img);
}
