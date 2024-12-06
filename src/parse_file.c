/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:13:44 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/06 13:23:59 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	init_texture_and_color(t_parsing *info, int fd)
{
	char	*line;
	int		identifier;
	int		index;
	int		count_id;

	identifier = 0;
	count_id = 0;
	line = get_next_line(fd, 0);
	while (line)
	{
		identifier = is_start_with_id(line);
		if (identifier)
		{
			index = start_of_texture(line);
			init_data(info, &line[index], identifier,
				len_of_texture(&line[index]));
			count_id++;
		}
		if (count_id == 6)
			break ;
		line = get_next_line(fd, 0);
	}
	if (count_id != 6)
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
