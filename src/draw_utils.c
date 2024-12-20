/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 18:55:18 by phwang            #+#    #+#             */
/*   Updated: 2024/12/20 11:49:54 by fsalomon         ###   ########.fr       */
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

// total des hypothenus de chaque ligne
// get la longueur a dessiner
int	get_line_length_int(float px, float py, float rx, float ry)
{
	return ((int)round(sqrt((rx - px) * (rx - px) + (ry - py) * (ry - py))));
}
