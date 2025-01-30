/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_data_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:13:44 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/30 12:48:45 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

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

static bool	load_identifier(t_parsing *info, char *line, int identifier)
{
	int	index;
	int	texture_len;

	index = start_of_texture(line);
	texture_len = len_of_texture(&line[index]);
	if (!init_texture(info, &line[index], identifier, texture_len))
		return (false);
	return (true);
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
			return (free_n_set_null(&line), false);
		if (identifier)
			if (!load_identifier(info, line, identifier))
				return (free_n_set_null(&line), false);
		if (!identifier && !is_white_space_line(line))
			return (print_error(IDPLC_ERR, NULL), free_n_set_null(&line), 0);
		free_n_set_null(&line);
		if (count_id == COMPLETE)
			break ;
		line = get_next_line(fd, 0);
	}
	if (count_id != COMPLETE)
		return (print_error(ID_ERR, NULL), false);
	return (is_valid_file_and_rgb(info));
}

bool	is_valid_data_bonus(t_parsing *info, char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (!init_texture_and_color(info, fd))
		return (close(fd), false);
	if (!init_map_bonus(info, fd))
		return (close(fd), false);
	close(fd);
	return (true);
}
