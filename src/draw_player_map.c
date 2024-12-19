/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 15:05:45 by phwang            #+#    #+#             */
/*   Updated: 2024/12/19 14:39:30 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img img, int y, int x, unsigned int color)
{
	char	*pixel;

	pixel = img.addr + y * img.line_len + x * (img.bpp / 8);
	*(unsigned int *)pixel = color;
}

unsigned int	get_backup_color(t_img img, int x, int y)
{
	return (*(unsigned int *)(img.addr + y * img.line_len + x * (img.bpp / 8)));
}

void	draw_mini_map_square(t_img img, int x, int y, unsigned int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < MINI_MAP_SIZE)
	{
		j = -1;
		while (++j < MINI_MAP_SIZE)
			my_mlx_pixel_put(img, y + i, x + j, color);
	}
}

void	draw_map(t_parsing *info)
{
	int	x;
	int	y;
	int	len_max_x;

	y = -1;
	x = 0;
	while (info->map[++y])
	{
		x = -1;
		// -1 car on ne veut pas dessiner une colonne vide
		while (++x < info->max_x)
		{
			// dessine en fonction de la taille du carré
			len_max_x = ft_strlen(info->map[y]);
			if (x < len_max_x && info->map[y][x] == '1')
			{
				draw_mini_map_square(info->mlx.background, x * MINI_MAP_SIZE
					+ MINI_MAP_LOC_X, y * MINI_MAP_SIZE + MINI_MAP_LOC_Y,
					WHITE);
			}
			else if (x < len_max_x && (info->map[y][x] == '0'
					|| is_player(info->map[y][x])))
			{
				draw_mini_map_square(info->mlx.background, x * MINI_MAP_SIZE
					+ MINI_MAP_LOC_X, y * MINI_MAP_SIZE + MINI_MAP_LOC_Y,
					BLACK);
			}
		}
	}
}

void	draw_rays(t_player *player, t_ray *ray, t_parsing *info, int replace)
{
	float	aTan;
	float	nTan;

	ft_memset(ray, 0, sizeof(t_ray));
	ray->ra = player->angle;
	ray->r = 0;
	printf("angle %f\n", ray->ra);
	// HORIZONTAL RAY-GRID INTERSECTION CODE
	while (ray->r < 1)
	{
		ray->dof = 0;
		aTan = -1 / tan(ray->ra);
		if (ray->ra > PI)
		{
			ray->ry = (((int)(player->pos_y + MINI_PLAYER_SIZE / 2 ) >> 6) << 6) - 0.0001;
			ray->rx = ((player->pos_y + MINI_PLAYER_SIZE / 2 ) - ray->ry) * aTan + player->pos_x + MINI_PLAYER_SIZE / 2 ;
			ray->yo = -64;
			ray->xo = -ray->yo * aTan;
			printf("je regarder vers le haut\n");
		}
		if (ray->ra < PI)
		{
			ray->ry = (((int)(player->pos_y + MINI_PLAYER_SIZE / 2 ) >> 6) << 6) + 64;
			ray->rx = ((player->pos_y + MINI_PLAYER_SIZE / 2 ) - ray->ry) * aTan + player->pos_x + MINI_PLAYER_SIZE / 2 ;
			ray->yo = 64;
			ray->xo = -ray->yo * aTan;
			printf("je regarde vers le bas\n");
		}
		if (ray->ra == 0 || ray->ra == PI)
		{
			ray->rx = (player->pos_x + MINI_PLAYER_SIZE / 2 );
			ray->ry = (player->pos_y + MINI_PLAYER_SIZE / 2 );
			ray->dof = 8;
			printf("je regarde vers la droite ou la gauche\n");
		}
		printf("rx %f ry %f\n", ray->rx, ray->ry);
		printf("player pos x %f player pos y %f\n", player->pos_x,
			player->pos_y);
		while (ray->dof < 8)
		{
			ray->mx = (int)(ray->rx) >> 6;
			ray->my = (int)(ray->ry) >> 6;
			ray->mp = ray->my * info->max_x + ray->mx;
			if (ray->mp < 0)
				printf("mp %d\n", ray->mp);
			if (ray->mp < info->max_x * info->max_y
				&& info->int_map[ray->mp] == 1)
			{
				// printf("jai trouve un mur a l'index mp %d\n", ray->mp);
				ray->dof = 8;
			}
			else
			{
				my_mlx_pixel_put(info->mlx.background, ray->ry, ray->rx, GREEN);
				// printf("je nai pas trouve de mur a l'index mp %d\n",
				//	ray->mp);
				ray->rx += ray->xo;
				ray->ry += ray->yo;
				ray->dof += 1;
			}
			printf("doof %d\n", ray->dof);
		}
		draw_mini_line(info, RED, replace);
		// VERICAL RAY-GRID INTERSECTION CODE
		// ray->dof = 0;
		// nTan = -tan(ray->ra);
		// if (ray->ra > PI2 && ray->ra < PI3)
		// {
		// 	ray->rx = (((int)player->pos_x >> 6) << 6) - 0.0001;
		// 	ray->ry = (player->pos_x - ray->rx) * nTan + player->pos_y;
		// 	ray->xo = -64;
		// 	ray->yo = -ray->xo * nTan;
		// }
		// if (ray->ra < PI2 || ray->ra > PI3)
		// {
		// 	ray->rx = (((int)player->pos_x >> 6) << 6) + 64;
		// 	ray->ry = (player->pos_x - ray->rx) * nTan + player->pos_y;
		// 	ray->xo = 64;
		// 	ray->yo = -ray->xo * nTan;
		// }
		// if (ray->ra == 0 || ray->ra == PI)
		// {
		// 	ray->rx = player->pos_x;
		// 	ray->ry = player->pos_y;
		// 	ray->dof = 8;
		// }
		// while (ray->dof < 8)
		// {
		// 	ray->mx = (int)(ray->rx) >> 6;
		// 	ray->my = (int)(ray->ry) >> 6;
		// 	ray->mp = ray->my * info->max_x + ray->mx;
		// 	if (ray->mp < 0)
		// 		printf("mp %d\n", ray->mp);
		// 	if (ray->mp < info->max_x * info->max_y
		// 		&& info->int_map[ray->mp] == 1)
		// 	{
		// 		ray->dof = 8;
		// 	}
		// 	else
		// 	{
		// 		ray->rx += ray->xo;
		// 		ray->ry += ray->yo;
		// 		ray->dof += 1;
		// 	}
		// }
		// draw_mini_line(info, GREEN, replace);
		ray->r++;
	}
}

void	draw_player(t_parsing *info, unsigned int color, int replace)
{
	int	x;
	int	y;

	y = -1;
	while (++y < MINI_PLAYER_SIZE)
	{
		x = -1;
		while (++x < MINI_PLAYER_SIZE)
		{
			// protection anti hors de lecran
			if (y + info->player.pos_y < 0 || y + info->player.pos_y >= SIZE_Y
				|| x + info->player.pos_x < 0 || x
				+ info->player.pos_x >= SIZE_X)
				break ;
			if (replace)
			{
				color = get_backup_color(info->mlx.backup, x
						+ info->player.last_pos_x, y + info->player.last_pos_y);
			}
			my_mlx_pixel_put(info->mlx.background, y + info->player.pos_y, x
				+ info->player.pos_x, color);
		}
	}
	draw_rays(&info->player, &info->ray, info, replace);
	// draw_mini_line(mlx, player, color, replace);
}
