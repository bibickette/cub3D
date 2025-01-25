/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:31:45 by phwang            #+#    #+#             */
/*   Updated: 2025/01/25 18:14:43 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static char	**add_line_to_tab(char **map, char *line, int i)
{
	map = ft_realloc_map(map, sizeof(char *) * (i + 1), sizeof(char *) * i);
	if (!map)
		return (print_error(MALLOC_ERR, NULL), NULL);
	map[i] = ft_strdup(line);
	free_n_set_null(&line);
	if (!map[i])
	{
		free_tab(map);
		return (print_error(MALLOC_ERR, NULL), NULL);
	}
	map[i + 1] = NULL;
	return (map);
}

static bool	convert_n_add(char ***map, char *line, int *i)
{
	if (!convert_tab_in_space(&line))
		return (free_tab(*map), false);
	*map = add_line_to_tab(*map, line, *i);
	if (!*map)
		return (false);
	(*i)++;
	return (true);
}

static bool	get_map(int fd, int *end, char ***map)
{
	char	*line;
	int		i;

	i = 0;
	line = get_next_line(fd, 0);
	if (!line)
		return (print_error(MAP_ERR, NO_MAP), false);
	while (line)
	{
		if (!is_white_space_line(line))
		{
			if (*end)
				return (print_error(MAP_ERR, EMPTY_LINE), false);
			if (!convert_n_add(map, line, &i))
				return (false);
		}
		else if (is_white_space_line(line))
		{
			if (i != 0)
				*end = 1;
			free_n_set_null(&line);
		}
		line = get_next_line(fd, 0);
	}
	return (true);
}

bool	init_map_bonus(t_parsing *info, int fd)
{
	int		flag;
	char	**map;

	flag = 0;
	map = NULL;
	if (!get_map(fd, &flag, &map))
		return (false);
	info->map = map;
	if (!info->map)
		return (false);
	if (!is_valid_map_bonus(info))
		return (false);
	info->int_map = convert_to_int_tab_bonus(info, info->map);
	if (!info->int_map)
		return (false);
	return (true);
}
