/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:33:40 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/20 15:39:10 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	check_letter_coma_rgb_value(char *line)
{
	int	nb_value;
	int	i;
	int	coma;

	nb_value = 0;
	coma = 0;
	i = -1;
	while (line[++i] && line[i] != '\n')
	{
		if (!ft_isdigit(line[i]) && line[i] != ' ' && line[i] != ',')
			return (print_error(LETTER_ERR, NULL), false);
		if (ft_isdigit(line[i]) && !ft_isdigit(line[i + 1]))
			nb_value++;
		if (line[i] == ',')
			coma++;
	}
	if (nb_value != 3)
		return (print_error(NB_VALUE_RGB_ERR, NULL), false);
	if (coma != 2)
		return (print_error(COMA_ERR, NULL), false);
	return (true);
}

static bool	parse_rgb(char *line, int rgb[3])
{
	int		i;
	int		num_len;
	int		r;

	r = 0;
	i = 0;
	if (!check_letter_coma_rgb_value(line))
		return (false);
	while (line[i] && line[i] != '\n')
	{
		num_len = 0;
		while (line[i] && (line[i] == ' ' || line[i] == ','))
			i++;
		while (ft_isdigit(line[i]))
		{
			num_len++;
			i++;
		}
		rgb[r++] = ft_atoi(line + i - num_len);
	}
	return (true);
}

static bool	init_path_id(t_parsing *info, char *line, int texture_len, int ID)
{
	int	cardinal;

	if (ID == NORTH)
		cardinal = NO;
	if (ID == SOUTH)
		cardinal = SO;
	if (ID == EAST)
		cardinal = EA;
	if (ID == WEST)
		cardinal = WE;
	info->textures.walls[cardinal].path_to_img = ft_substr(line, 0,
			texture_len);
	if (!info->textures.walls[cardinal].path_to_img)
		return (print_error(MALLOC_ERR, NULL), false);
	info->textures.walls[cardinal].id = ID;
	return (true);
}

bool	init_texture(t_parsing *info, char *line, int ID, int texture_len)
{
	if (ID != FLOOR && ID != CEILING)
		return (init_path_id(info, line, texture_len, ID));
	if (ID == FLOOR)
		return (parse_rgb(line, info->textures.floor_rgb));
	if (ID == CEILING)
		return (parse_rgb(line, info->textures.ceiling_rgb));
	return (true);
}
