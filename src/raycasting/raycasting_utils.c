/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:55:18 by phwang            #+#    #+#             */
/*   Updated: 2025/01/10 16:16:14 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img img, int y, int x, unsigned int color)
{
	char	*pixel;

	if (y < 0 || y >= SIZE_Y || x < 0 || x >= SIZE_X)
		return ;
	pixel = img.addr + y * img.line_len + x * (img.bpp / 8);
	*(unsigned int *)pixel = color;
}

unsigned int	get_backup_color(t_img img, int x, int y)
{
	return (*(unsigned int *)(img.addr + y * img.line_len + x * (img.bpp / 8)));
}

// total des hypothenus de chaque ligne
// get la longueur a dessiner
float	get_distance(float px, float py, float rx, float ry)
{
	return (sqrt((rx - px) * (rx - px) + (ry - py) * (ry - py)));
}

/*
 Assure que l'angle de ray reste toujours 
 dans les valeurs trigonometric dun cercle ( entre 0 et 2PI )
*/
float	protect_angle_trigo_value(float angle)
{
	if (angle < 0)
		angle += 2 * PI;
	else if (angle > 2 * PI)
		angle -= 2 * PI;
	return (angle);
}
