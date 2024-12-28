/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 16:40:44 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/28 17:02:21 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_game(t_parsing *info)
{
	draw_player(info, YELLOW, NO_REPLACE);
	draw_rays(&info->player, &info->ray, info, NO_REPLACE);
}