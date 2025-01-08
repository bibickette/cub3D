/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:31:45 by phwang            #+#    #+#             */
/*   Updated: 2025/01/08 14:35:12 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

static void	replace_enter_by_space(char **line)
{
	int	i;

	i = ft_strlen(*line) - 1;
	if ((*line)[i] == '\n')
		(*line)[i] = ' ';
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

static bool	get_map(t_parsing *info, int fd)
{
	char	*line;
	char	**map;
	int		i;

	i = 0;
	map = NULL;
	line = get_next_line(fd, 0);
	while (line)
	{
		if (!is_white_space_line(line))
		{
			if (!convert_n_add(&map, line, &i))
				return (false);
		}
		else if (is_white_space_line(line))
		{
			free_n_set_null(&line);
			if (i != 0)
				break ;
		}
		line = get_next_line(fd, 0);
	}
	info->map = map;
	return (true);
}

bool	init_map(t_parsing *info, int fd)
{
	if (!get_map(info, fd))
		return (false);
	if (!info->map)
		return (false);
	if (!is_valid_map(info))
		return (false);
	info->int_map = convert_to_int_tab(info, info->map);
	if (!info->int_map)
		return (false);
	return (true);
}
