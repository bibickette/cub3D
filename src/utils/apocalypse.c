/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apocalypse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:55:43 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/18 15:31:05 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		if (tab[i])
			free_n_set_null(&tab[i]);
	free(tab);
	tab = 0;
}

void	free_n_set_null(char **to_free)
{
	if (to_free)
	{
		free(to_free);
		*to_free = 0;
	}
}

void	destroy_info(t_parsing *info)
{
	int	i;

	i = -1;
	get_next_line(0, 1);
	while (++i < 4)
		if (info->textures.walls[i].path_to_img)
			free_n_set_null(&info->textures.walls[i].path_to_img);
	if (info->map)
		free_tab(info->map);
	free(info->int_map);
	info->int_map = 0;
}
