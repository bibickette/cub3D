/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanfan <fanfan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:13:44 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/07 17:52:48 by fanfan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	is_double_identifier(int *count_id, int identifier)
{
	if (*count_id & identifier)
	{
		print_error(ID_ERR, NULL);
		return (true);
	}
	*count_id |= identifier;
	return (false);
}

static void	load_identifier(t_parsing *info, char *line, int identifier)
{
	int	index;
	int	texture_len;

	index = start_of_texture(line);
	texture_len = len_of_texture(&line[index]);
	init_data(info, &line[index], identifier, texture_len);
}

static bool	init_texture_and_color(t_parsing *info, int fd)
{
	char	*line;
	int		identifier;
	int		count_id;

	identifier = 0;
	count_id = 0;
	line = get_next_line(fd, 0);
	while (line)
	{
		identifier = is_start_with_id(line);
		if (identifier && is_double_identifier(&count_id, identifier))
			return (free(line), false);
		if (identifier)
			load_identifier(info, line, identifier);
		free_n_set_null(line);
		if (count_id == COMPLETE)
			break ;
		line = get_next_line(fd, 0);
	}
	if (count_id != COMPLETE)
		return (print_error(ID_ERR, NULL), false);
	return (is_valid_file_and_rgb(info));
}

bool	is_valid_data(t_parsing *info, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (!init_texture_and_color(info, fd))
		return (false);
	// if (!init_map(info))
	// 	return (false);
	return (true);
}
