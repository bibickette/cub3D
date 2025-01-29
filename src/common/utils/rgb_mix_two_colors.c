/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_mix_two_colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 13:53:47 by phwang            #+#    #+#             */
/*   Updated: 2025/01/28 14:19:49 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/* deux tableaux existant avec un new tab sur la stack (no alloc) */
void	rgb_mix_colors(int *c_one, int *c_two, int *new_color)
{
	new_color[0] = (c_one[0] + c_two[0]) / 2;
	new_color[1] = (c_one[1] + c_two[1]) / 2;
	new_color[2] = (c_one[2] + c_two[2]) / 2;
}
