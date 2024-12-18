/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:33:40 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/18 13:45:22 by fsalomon         ###   ########.fr       */
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
	while (line[i] && (line[i] != ' ' && line[i] != '\n'))
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
	while (line[i] && line[i] != '\n')
	{
		num_to_convert = NULL;
		num_len = 0;
		while (line[i] && (line[i] == ' ' || line[i] == ','))
			i++;
		while (ft_isdigit(line[i]) || line[i] == '-' || line[i] == '+')
		{
			num_len++;
			i++;
		}
		num_to_convert = ft_substr(line, i - num_len, num_len);
		rgb[r] = ft_atoi(num_to_convert);
		free(num_to_convert);
		r++;
		if (r == 3)
			break ;
	}
}

void	init_floor_ceiling(t_parsing *info, char *line, int ID)
{
	if (ID == FLOOR)
	{
		parse_rgb(line, info->textures.floor_rgb);
	}
	if (ID == CEILING)
	{
		parse_rgb(line, info->textures.ceiling_rgb);
	}
}

void	init_data(t_parsing *info, char *line, int ID, int texture_len)
{
	if (ID == NORTH)
	{
		info->textures.walls[NO].path_to_img = ft_substr(line, 0, texture_len);
		info->textures.walls[NO].id = ID;
	}
	if (ID == SOUTH)
	{
		info->textures.walls[SO].path_to_img = ft_substr(line, 0, texture_len);
		info->textures.walls[SO].id = ID;
	}
	if (ID == EAST)
	{
		info->textures.walls[EA].path_to_img = ft_substr(line, 0, texture_len);
		info->textures.walls[EA].id = ID;
	}
	if (ID == WEST)
	{
		info->textures.walls[WE].path_to_img = ft_substr(line, 0, texture_len);
		info->textures.walls[WE].id = ID;
	}
	init_floor_ceiling(info, line, ID);
}
