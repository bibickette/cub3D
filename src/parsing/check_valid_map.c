/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:07:29 by phwang            #+#    #+#             */
/*   Updated: 2024/12/09 17:34:46 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
static bool	check_first_last_line(char **map)
{
	int	j;

	j = 0;
	while (map[j])
		j++;
	if (j < 2)
		return (print_error(MAP_ERR, MINIMAL_SIZE_MAP), false);
	if (!check_line(map[0]) || !check_line(map[j - 1]))
		return (false);
	return (true);
}

bool	is_valid_map(t_parsing *info)
{
	if (!check_first_last_line(info->map))
		return (print_error(MAP_ERR, WALL_ERR), false);
	return (true);
}
