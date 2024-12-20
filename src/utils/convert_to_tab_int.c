/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_tab_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:09:27 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/20 11:57:59 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_atoi_char(char c)
{
	if (is_player(c))
		return (0);
	return (c - '0');
}

static int	*init_int_tab(int *tab, char **map, int max_x, int max_y)
{
	int	y;
	int	x;
	int	i;

	y = 0;
	x = 0;
	i = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			if (!map[y][x])
				tab[i] = 2;
			else
				tab[i] = ft_atoi_char(map[y][x]);
			i++;
			x++;
		}
		y++;
	}
	return (tab);
}

// converti la map en tableau d'int
int	*convert_to_int_tab(t_parsing *info, char **map)
{
	int	size;
	int	*int_tab;

	size = 0;
	size = info->max_x * info->max_y;
	int_tab = ft_calloc(size, sizeof(int));
	if (!int_tab)
		return (print_error(MALLOC_ERR, NULL), NULL);
	int_tab = init_int_tab(int_tab, map, info->max_x, info->max_y);
	return (int_tab);
}
