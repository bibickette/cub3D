/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 09:33:40 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/17 18:07:18 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	parse_rgb(char *line, int rgb[3])
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
		printf("line = %s\n", line);
		// check toute la ligne et return false si lettre et + 2 virgule
		// et que trois valeurs bien collées
		while (line[i] && (line[i] == ' ' || line[i] == ','))
		{
			printf("line[%d] debut = %c\n", i, line[i]);
			i++;
		}
		while (ft_isdigit(line[i]) || line[i] == '-' || line[i] == '+')
		{
			printf("line[%d] = %c\n", i, line[i]);
			num_len++;
			i++;
		}
		num_to_convert = ft_substr(line, i - num_len, num_len);
		printf("num_to_convert = %s\n", num_to_convert);
		rgb[r] = ft_atoi(num_to_convert);
		printf("rgb[%d] = %d\n", r, rgb[r]);
		free(num_to_convert);
		r++;
		if (r == 3)
			break ;
	}
	return (true);
}

static bool	init_floor_ceiling(t_parsing *info, char *line, int ID)
{
	if (ID == FLOOR)
	{
		return (parse_rgb(line, info->textures.floor_rgb));
	}
	if (ID == CEILING)
	{
		return (parse_rgb(line, info->textures.ceiling_rgb));
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
	{
		if (!init_path_id(info, line, texture_len, ID))
			return (false);
	}
	return (init_floor_ceiling(info, line, ID));
}
