/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <phwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:31:45 by phwang            #+#    #+#             */
/*   Updated: 2025/02/19 14:00:59 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// static char	**add_line_to_tab(char **map, char *line, int i)
// {
// 	map = ft_realloc_map(map, sizeof(char *) * (i + 1), sizeof(char *) * i);
// 	if (!map)
// 		return (print_error(MALLOC_ERR, NULL), NULL);
// 	map[i] = ft_strdup(line);
// 	free_n_set_null(&line);
// 	if (!map[i])
// 	{
// 		free_tab(map);
// 		return (print_error(MALLOC_ERR, NULL), NULL);
// 	}
// 	map[i + 1] = NULL;
// 	return (map);
// }

// static bool	convert_n_add(char ***map, char *line, int *i)
// {
// 	if (!convert_tab_in_space(&line))
// 		return (free_tab(*map), false);
// 	*map = add_line_to_tab(*map, line, *i);
// 	if (!*map)
// 		return (false);
// 	(*i)++;
// 	return (true);
// }

static bool	get_map(int fd, char ***map)
{
	char	*line;

	line = get_next_line(fd, 0);
	if (!line)
		return (print_error(MAP_ERR, NO_MAP), false);
	else if (!is_white_space_line(line))
	{
		if (!char_add_back_tab(map, line))
			return (free_n_set_null(&line), false);
	}
	free_n_set_null(&line);
	while (1)
	{
		line = get_next_line(fd, 0);
		if (!line)
			break ;
		if (!is_white_space_line(line) || (*map))
			if (!char_add_back_tab(map, line))
				return (false);
		free_n_set_null(&line);
	}
	return (true);
}

bool	init_map(t_parsing *info, int fd)
{
	char	**map;

	map = NULL;
	if (!get_map(fd, &map))
		return (false);
	info->map = map;
	if (!info->map)
		return (false);
	if (!is_valid_map(info))
		return (false);
	info->int_map = convert_to_int_tab(info, info->map);
	if (!info->int_map)
		return (false);
	return (true);
}
