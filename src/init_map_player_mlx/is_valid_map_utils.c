/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:22:54 by phwang            #+#    #+#             */
/*   Updated: 2025/01/23 12:04:55 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_everything_surrounded(char **map, int last_tab)
{
	int	i;
	int	j;

	j = 0;
	while (++j < last_tab)
	{
		i = -1;
		while (map[j][++i])
		{
			if (map[j][i] == '0' || is_player(map[j][i]))
			{
				if (map[j][i - 1] == ' ' || map[j][i + 1] == ' ' || map[j
					- 1][i] == ' ' || map[j + 1][i] == ' ' || map[j][i
					+ 1] == '\n')
					return (print_error(MAP_ERR, WALL_ERR), false);
			}
		}
	}
	return (true);
}

static bool	check_line(char *line)
{
	int	i;
	int	have_wall;

	i = -1;
	have_wall = false;
	while (line[++i])
	{
		if (!ft_is_white_space(line[i]) && line[i] != '1')
			return (false);
		else if (line[i] == '1')
			have_wall = true;
	}
	return (have_wall);
}

// check si ma premiere et derniere ligne sont bien que des 1
// check aussi quon a minimum 3 lignes
// ne check pas linterieur pour linstant
bool	check_first_last_line(char **map, int *last_tab)
{
	int	nb_tab;

	nb_tab = 0;
	while (map[nb_tab])
		nb_tab++;
	if (nb_tab < 2)
		return (print_error(MAP_ERR, MINIMAL_SIZE_MAP), false);
	(*last_tab) = nb_tab - 1;
	if (!check_line(map[0]) || !check_line(map[(*last_tab)]))
		return (print_error(MAP_ERR, WALL_ERR), false);
	return (true);
}
