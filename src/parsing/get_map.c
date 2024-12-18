/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:23:14 by fanfan            #+#    #+#             */
/*   Updated: 2024/12/18 15:30:32 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// ces fonctions recupere la map dan sun tableau et
// s'arrete lorsquelle croise un eligne vide si elle a commence a lire de la map
// permet d'eviter les lignes vides dans la map
// car on considere que la map sarrete des quon trouve une ligne full vide
// et on ne prend pas en compte les lignes vides avant la map
// le realloc etaot hyper galere mais ca a lair de marcher :*

// fonction char_add_back_tab fait le meme taf si ca marche pas bien
// mais tas lair de 100fois lavoir mieux codé que moi, gg de fouuuu

// je change le return de get_map car pour moi tout doit sarreter si ca foire

char	**add_line_to_tab(char **map, char *line, int i)
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
	replace_enter_by_space(&line);
	*map = add_line_to_tab(*map, line, *i);
	if (!*map)
		return (false);
	(*i)++;
	return (true);
}

// ne respecte pas le single jsp quoi xD LOL
bool	get_map(t_parsing *info, int fd)
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
