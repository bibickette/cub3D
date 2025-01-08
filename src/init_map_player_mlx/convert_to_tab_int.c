/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_tab_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:09:27 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/08 16:14:33 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	ft_atoi_char(char c)
{
	if (is_player(c))
		return (0);
	else if (c == ' ')
		return (2);
	else if (c == '1')
		return (1);
	else if (c == '0')
		return (0);
	return (2);
}

static int	*init_int_tab(int *tab, char **map, int max_x, int max_y)
{
	int	y;
	int	x;
	int	i;
	int	flag;

	y = 0;
	i = 0;
	while (y < max_y)
	{
		x = 0;
		flag = 0;
		while (x < max_x)
		{
			if (map[y][x] && map[y][x] == '\n')
				flag = 1;
			if (!map[y][x] || flag)
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
