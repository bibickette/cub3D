/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 19:03:00 by phwang            #+#    #+#             */
/*   Updated: 2024/12/16 19:03:17 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// dessine un cadrillage en fonction de la taille dun carré
// defini par MINI_MAP_SIZE
void	draw_line(t_img img, int x, int y, int flag)
{
	int	i;
	int	size;

	i = -1;
	if (flag == VERTICAL)
		size = MINI_MAP_SIZE;
	else if (flag == HORIZONTAL)
	{
		size = x * MINI_MAP_SIZE;
		// x a 0 car on veut dessiner la premiere ligne sur le premier pixel
		x = 0;
	}
	while (++i < size)
	{
		// trie le pixel du debut et de la fin
		// pour ne pas mettre al toute premiere et
		// derneire ligne de chaque carré
		// (y * MINI_MAP_SIZE != 0) && (y * MINI_MAP_SIZE != size - 1)
		// (x * size != 0) && (x * size != size - 1)
		if (flag == HORIZONTAL && (y * MINI_MAP_SIZE != 0) && (y
				* MINI_MAP_SIZE != size - 1))
			my_mlx_pixel_put(img, y * MINI_MAP_SIZE + MINI_MAP_LOC_Y, x
				* MINI_MAP_SIZE + i + MINI_MAP_LOC_X, GREY);
		else if (flag == VERTICAL && (x * MINI_MAP_SIZE != 0) && (x
				* MINI_MAP_SIZE != MINI_MAP_SIZE - 1))
			my_mlx_pixel_put(img, y * MINI_MAP_SIZE + i + MINI_MAP_LOC_Y, x
				* MINI_MAP_SIZE + MINI_MAP_LOC_X, GREY);
	}
}

void	draw_mini_line(t_mlx *mlx, t_player *player, unsigned int color,
		int replace)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	// ecrit une ligne jusqua cquelle rencontre un mur OU le bord de lecran
	while (1)
	{
		x = player->pos_x + MINI_PLAYER_SIZE / 2 + i * cos(player->angle);
		y = player->pos_y + MINI_PLAYER_SIZE / 2 + i * sin(player->angle);
		// protection anti ecrire hors de lecran
		if (y < 0 || y >= SIZE_Y || x < 0 || x >= SIZE_X)
			break ;
		// check si on est sur un mur
		if (get_backup_color(mlx->backup, x, y) == WHITE)
			break ;
		if (replace)
			color = get_backup_color(mlx->backup, x, y);
		my_mlx_pixel_put(mlx->background, y, x, color);
		i++;
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
