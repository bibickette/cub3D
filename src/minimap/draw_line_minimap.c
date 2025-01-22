/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:03:00 by phwang            #+#    #+#             */
/*   Updated: 2025/01/22 13:46:35 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// dessine un cadrillage en fonction de la taille dun carré
// defini par SCALE
static void	draw_line(t_img img, int x, int y, int flag)
{
	int	i;
	int	size;

	i = -1;
	size = 0;
	if (flag == VERTICAL)
		size = SCALE;
	else if (flag == HORIZONTAL)
	{
		size = x * SCALE;
		x = 0;
	}
	while (++i < size)
	{
		if (flag == HORIZONTAL && (y * SCALE != 0) && (y * SCALE != size - 1))
			my_mlx_pixel_put(img, y * SCALE, x * SCALE + i, PINK);
		else if (flag == VERTICAL && (x * SCALE != 0) && (x * SCALE != SCALE
				- 1))
			my_mlx_pixel_put(img, y * SCALE + i, x * SCALE, RED);
	}
}

// dessine les lignes si besoin
void	draw_line_on_map(t_parsing *info, t_img img)
{
	int	x;
	int	y;

	y = -1;
	x = 0;
	while (info->map[++y])
	{
		x = -1;
		while (++x < info->max_x)
			draw_line(img, x, y, VERTICAL);
		draw_line(img, x, y, HORIZONTAL);
	}
}
