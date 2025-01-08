/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   might_be_useless.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 15:07:28 by phwang            #+#    #+#             */
/*   Updated: 2025/01/08 15:07:32 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_mini_line(t_parsing *info, unsigned int color, int replace,
		float line_length)
{
	float	i;
	int	x;
	int	y;

	i = 0;
	x = info->player.pos_x + MINI_PLAYER_SIZE / 2 + i * cos(info->player.angle);
	y = info->player.pos_y + MINI_PLAYER_SIZE / 2 + i * sin(info->player.angle);
	// ecrit une ligne jusqua cquelle rencontre un mur OU le bord de lecran
	while (i < line_length)
	{
		x = info->player.pos_x + MINI_PLAYER_SIZE / 2 + i
			* cos(info->ray.angle);
		y = info->player.pos_y + MINI_PLAYER_SIZE / 2 + i
			* sin(info->ray.angle);
		// protection anti ecrire hors de lecran,
		// utils seulement si on sort de la minimap
		// if (y < 0 || y >= SIZE_Y || x < 0 || x >= SIZE_X)
		// 	break ;
		// check si on est sur un mur
		// if (get_backup_color(info->mlx.backup, x, y) == WHITE)
		// 	break ;
		if (replace)
			color = get_backup_color(info->mlx.backup, x, y);
		my_mlx_pixel_put(info->mlx.background, y, x, color);
		i++;
	}
}
