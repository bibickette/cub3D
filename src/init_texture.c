/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:33:40 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/06 11:31:28 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	start_of_texture(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	i += 2;
	while (line[i] && line[i] == ' ')
		i++;
	return (i);
}

int	len_of_texture(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i] && (line[i] != ' '  && line[i] != '\n'))
	{
		i++;
		len++;
	}
	return (len);
}

static void	parse_rgb(char *line, int rgb[3])
{
	int		i;
	int		num_len;
	char	*num_to_convert;
	int		r;

	r = 0;
	i = 0;
	while (line[i])
	{
		num_to_convert = NULL;
		num_len = 0;
		while (line[i] && (line[i] == ' ' || line[i] == ','))
			i++;
		while (ft_isdigit(line[i++]))
			num_len++;
		num_to_convert = ft_substr(line, i - num_len, num_len);
		rgb[r] = ft_atoi(num_to_convert);
		free(num_to_convert);
		r++;
		if (r == 3)
			break ;
	}
}

void	init_floor_ceiling(t_parsing_data *info, char *line, int ID)
{
	if (ID == FLOOR)
	{
		parse_rgb(line, info->floor_ceiling.floor_rgb);
	}
	if (ID == CEILING)
	{
		parse_rgb(line, info->floor_ceiling.ceiling_rgb);
	}
}

void	init_data(t_parsing_data *info, char *line, int ID, int texture_len)
{
	if (ID == NORTH)
	{
		info->walls.north.path_to_img = ft_substr(line, 0, texture_len);
		info->walls.north.id = ID;
	}
	if (ID == SOUTH)
	{
		info->walls.south.path_to_img = ft_substr(line, 0, texture_len);
		info->walls.south.id = ID;
	}
	if (ID == EAST)
	{
		info->walls.east.path_to_img = ft_substr(line, 0, texture_len);
		info->walls.east.id = ID;
	}
	if (ID == WEST)
	{
		info->walls.west.path_to_img = ft_substr(line, 0, texture_len);
		info->walls.west.id = ID;
	}
	init_floor_ceiling(info, line, ID);
}