/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0020/01/08 00:00:00 by 13:53 by ph       #+#    #+#             */
/*   Updated: 2025/01/15 13:24:44 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	escape_exit(t_parsing *info)
{
	printf("%s", ESC_MSG);
	destroy_info(info);
	destroy_mlx(&info->mlx);
	exit(0);
}

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
	info->player.pos_y += -cos(info->player.angle) * MOVE_SPEED;
	info->player.pos_x += sin(info->player.angle) * MOVE_SPEED;
}

void	move_player_right(t_parsing *info)
{
	info->player.pos_y += cos(info->player.angle) * MOVE_SPEED;
	info->player.pos_x += -sin(info->player.angle) * MOVE_SPEED;
}
