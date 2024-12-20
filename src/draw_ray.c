/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ray.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 21:38:05 by phwang            #+#    #+#             */
/*   Updated: 2024/12/20 13:24:49 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	hzplan_find_intersection(t_ray *ray, t_parsing *info)
{
	ray->arc_tan = -1 / tan(ray->angle);
	if (ray->angle > PI)
	{
		ray->ry = (((int)ray->player_posy / MINI_MAP_SIZE) * MINI_MAP_SIZE)
			- 0.0001;
		ray->rx = (ray->player_posy - ray->ry) * ray->arc_tan
			+ ray->player_posx;
		ray->yo = -MINI_MAP_SIZE;
		ray->xo = -ray->yo * ray->arc_tan;
	}
	if (ray->angle < PI)
	{
		ray->ry = (((int)ray->player_posy / MINI_MAP_SIZE) * MINI_MAP_SIZE)
			+ MINI_MAP_SIZE;
		ray->rx = (ray->player_posy - ray->ry) * ray->arc_tan
			+ ray->player_posx;
		ray->yo = MINI_MAP_SIZE;
		ray->xo = -ray->yo * ray->arc_tan;
	}
	if (ray->angle == 0 || ray->angle == PI)
	{
		ray->rx = ray->player_posx;
		ray->ry = ray->player_posy;
		ray->dof = info->max_x;
	}
}

int	ray_horizon_plan_len(t_player *player, t_ray *ray, t_parsing *info)
{
	ray->player_posx = player->pos_x + MINI_PLAYER_SIZE / 2;
	ray->player_posy = player->pos_y + MINI_PLAYER_SIZE / 2;
	ray->dof = 0;
	hzplan_find_intersection(ray, info);
	// tant que je depasse pas la taille x max de la map
	// pour moi dof est seulement un iterateur mais
	// je sais pas si ca sert a autre chose,
	// si useless, je changerai pour iterateur normal, et sortir dof++ du else
	while (ray->dof < info->max_x)
	{
		ray->mx = (int)(ray->rx) / MINI_MAP_SIZE;
		ray->my = (int)(ray->ry) / MINI_MAP_SIZE;
		ray->mp = ray->my * info->max_x + ray->mx;
		if (ray->mp < 0) // protection anti chercher une valeur negative
			ray->mp = 0;
		// si jai un mur jarrete de chercher
		if (ray->mp < info->max_x * info->max_y && info->int_map[ray->mp] == 1)
			break ;
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof++;
		}
	}
	return (get_line_length_int(ray->player_posx, ray->player_posy, ray->rx,
			ray->ry));
}

void	vtplan_find_intersection(t_ray *ray, t_parsing *info)
{
	ray->tan = -tan(ray->angle);
	if (ray->angle > PI2 && ray->angle < PI3)
	{
		ray->rx = (((int)ray->player_posx / MINI_MAP_SIZE) * MINI_MAP_SIZE)
			- 0.0001;
		ray->ry = (ray->player_posx - ray->rx) * ray->tan + ray->player_posy;
		ray->xo = -MINI_MAP_SIZE;
		ray->yo = -ray->xo * ray->tan;
	}
	if (ray->angle < PI2 || ray->angle > PI3)
	{
		ray->rx = (((int)ray->player_posx / MINI_MAP_SIZE) * MINI_MAP_SIZE)
			+ MINI_MAP_SIZE;
		ray->ry = (ray->player_posx - ray->rx) * ray->tan + ray->player_posy;
		ray->xo = MINI_MAP_SIZE;
		ray->yo = -ray->xo * ray->tan;
	}
	if (ray->angle == PI3 || ray->angle == PI2)
	{
		ray->rx = ray->player_posx;
		ray->ry = ray->player_posy;
		ray->dof = info->max_y;
	}
}

int	ray_vertical_plan_len(t_player *player, t_ray *ray, t_parsing *info)
{
	ray->player_posx = player->pos_x + MINI_PLAYER_SIZE / 2;
	ray->player_posy = player->pos_y + MINI_PLAYER_SIZE / 2;
	ray->dof = 0;
	vtplan_find_intersection(ray, info);
	// jai trouve la longueur de chaque coté opposé a langle
	// jadditionne ces cotés jusqua trouver un mur
	// while tous les murs
	while (ray->dof < info->max_y)
	{
		ray->mx = (int)(ray->rx) / MINI_MAP_SIZE;
		ray->my = (int)(ray->ry) / MINI_MAP_SIZE;
		ray->mp = ray->my * info->max_x + ray->mx;
		if (ray->mp < 0)
			ray->mp = 0;
		// ca equivaut a un break ray->dof = info->max_y; // 8 cest le max y
		if (ray->mp < info->max_x * info->max_y && info->int_map[ray->mp] == 1)
			break ;
		else
		{
			ray->rx += ray->xo;
			ray->ry += ray->yo;
			ray->dof++;
		}
	}
	return (get_line_length_int(ray->player_posx, ray->player_posy, ray->rx,
			ray->ry));
}

void	draw_rays(t_player *player, t_ray *ray, t_parsing *info, int replace)
{
	int	horizontal_len;
	int	vertical_len;

	ray->angle = player->angle - DR * 30;
	if (ray->angle < 0)
	{
		ray->angle += 2 * PI;
	}
	if (ray->angle > 2 * PI)
	{
		ray->angle -= 2 * PI;
	}
	ray->r = 0;
	while (ray->r < 60)
	{
		// HORIZONTAL RAY-GRID INTERSECTION CODE
		horizontal_len = ray_horizon_plan_len(player, ray, info);
		// VERTICAL RAY-GRID INTERSECTION CODE
		vertical_len = ray_vertical_plan_len(player, ray, info);
		if ((horizontal_len != 0 && horizontal_len <= vertical_len)
			|| vertical_len <= 0)
			draw_mini_line(info, GREEN, replace, horizontal_len);
		else
			draw_mini_line(info, RED, replace, vertical_len);
		ray->r++;
		ray->angle += DR;
		if (ray->angle < 0)
		{
			ray->angle += 2 * PI;
		}
		if (ray->angle > 2 * PI)
		{
			ray->angle -= 2 * PI;
		}
	}
}
