/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanfan <fanfan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:23:14 by fanfan            #+#    #+#             */
/*   Updated: 2024/12/08 12:38:12 by fanfan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	**add_line_to_tab(char **map, char *line, int i)
{
	map = ft_realloc_map(map, sizeof(char *) * (i + 1), sizeof(char *) * i);
	if (!map)
		return (print_error(MALLOC_ERR, NULL), NULL);
	map[i] = ft_strdup(line);
	free_n_set_null(line);
	if (!map[i])
	{
		free_tab(map);
		return (print_error(MALLOC_ERR, NULL), NULL);
	}
	map[i + 1] = NULL;
	return (map);
}

void	get_map(t_parsing *info, int fd)
{
	char	*line;
	char	**map;
	int		i;

	i = 0;
	line = get_next_line(fd, 0);
	map = NULL;
	while (line)
	{
		if (!is_white_space_line(line))
		{
			map = add_line_to_tab(map, line, i);
			if (!map)
				return (free_tab(map));
			i++;
		}
		else if (is_white_space_line(line))
		{
			free_n_set_null(line);
			if (i != 0)
				break ;
		}
		line = get_next_line(fd, 0);
	}
	info->map = map;
}
