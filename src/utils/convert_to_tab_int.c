/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_tab_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 12:09:27 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/18 16:57:58 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_atoi_char(char c)
{
	if(is_player(c))
		return(0);
	return (c - '0');
}

int	*convert_to_int_tab(t_parsing *info, char **map)
{
	int	y;
	int	x;
	int	size;
	int	i;
	int	*int_tab;

	y = 0;
	x = 0;
	size = 0;
	i = 0;
	size = info->max_x * info->max_y;
	int_tab = ft_calloc(size, sizeof(int));
	if (!int_tab)
		return (print_error(MALLOC_ERR, NULL), NULL);
	while (y < info->max_y)
	{
		x = 0;
		while (x < info->max_x)
		{
			if (!map[y][x])
				int_tab[i] = 2;
			else
				int_tab[i] = ft_atoi_char(map[y][x]);
			printf("%d ", int_tab[i]);
			i++;
			x++;
		}
		printf("\n");
		y++;
	}
	return (int_tab);
}
