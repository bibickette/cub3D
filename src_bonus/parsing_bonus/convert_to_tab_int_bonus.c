/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_tab_int_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:09:27 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/28 11:44:12 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static int	ft_atoi_char(char c)
{
	if (is_player(c))
		return (0);
	else if (c == ' ')
		return (2);
	else if (c == '1')
		return (1);
	else if (c == '0')
		return (0);
	else if (c == DOOR_CLOSED)
		return (DOOR_CLOSED_INT);
	return (NO_SIGN);
}

static int	*init_int_tab(int *tab, char **map, int max_x, int max_y)
{
	int		y;
	int		x;
	int		i;
	size_t	line_len;

	y = 0;
	i = 0;
	while (y < max_y)
	{
		x = 0;
		if (map[y])
			line_len = ft_strlen(map[y]);
		while (x < max_x)
		{
			if (x >= (int)line_len || map[y][x] == '\n')
				tab[i++] = 2;
			else
				tab[i++] = ft_atoi_char(map[y][x]);
			x++;
		}
		y++;
	}
	return (tab);
}

// converti la map en tableau d'int
int	*convert_to_int_tab_bonus(t_parsing *info, char **map)
{
	int	size;
	int	*int_tab;

	size = 0;
	size = info->max_x * info->max_y;
	int_tab = ft_calloc(size, sizeof(int));
	if (!int_tab)
		return (print_error(MALLOC_ERR, NULL), NULL);
	int_tab = init_int_tab(int_tab, map, info->max_x, info->max_y);
	return (int_tab);
}
