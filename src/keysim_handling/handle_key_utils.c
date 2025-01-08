/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 16:13:53 by phwang            #+#    #+#             */
/*   Updated: 2025/01/08 16:14:00 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_player_up(t_parsing *info)
{
	info->player.pos_x += info->player.d_x;
	info->player.pos_y += info->player.d_y;
}

void	move_player_down(t_parsing *info)
{
	info->player.pos_x -= info->player.d_x;
	info->player.pos_y -= info->player.d_y;
}

void	move_player_left(t_parsing *info)
{
	info->player.pos_y += -cos(info->player.angle) * 5;
	info->player.pos_x += sin(info->player.angle) * 5;
}

void	move_player_right(t_parsing *info)
{
	info->player.pos_y += cos(info->player.angle) * 5;
	info->player.pos_x += -sin(info->player.angle) * 5;
}
