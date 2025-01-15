/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0020/01/08 00:00:00 by 13:53 by ph       #+#    #+#             */
/*   Updated: 2025/01/15 16:17:17 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	move_player_up_bonus(t_parsing *info)
{
	int	futur_x;
	int	futur_y;

	futur_x = floorf((info->player.pos_x + info->player.d_x) / SCALE);
	futur_y = floorf((info->player.pos_y + info->player.d_y) / SCALE);
	if (is_possible_to_move(info, futur_x, futur_y))
	{
		info->player.pos_x += info->player.d_x;
		info->player.pos_y += info->player.d_y;
	}
}

void	move_player_down_bonus(t_parsing *info)
{
	int	futur_x;
	int	futur_y;

	futur_x = floorf((info->player.pos_x - info->player.d_x) / SCALE);
	futur_y = floorf((info->player.pos_y - info->player.d_y) / SCALE);
	if (is_possible_to_move(info, futur_x, futur_y))
	{
		info->player.pos_x -= info->player.d_x;
		info->player.pos_y -= info->player.d_y;
	}
}

void	move_player_left_bonus(t_parsing *info)
{
	int	futur_x;
	int	futur_y;

	futur_x = floorf((info->player.pos_x + sin(info->player.angle) * MOVE_SPEED)
			/ SCALE);
	futur_y = floorf((info->player.pos_y - cos(info->player.angle) * MOVE_SPEED)
			/ SCALE);
	if (is_possible_to_move(info, futur_x, futur_y))
	{
		info->player.pos_y += -cos(info->player.angle) * MOVE_SPEED;
		info->player.pos_x += sin(info->player.angle) * MOVE_SPEED;
	}
}

void	move_player_right_bonus(t_parsing *info)
{
	int	futur_x;
	int	futur_y;

	futur_x = floorf((info->player.pos_x - sin(info->player.angle) * MOVE_SPEED)
			/ SCALE);
	futur_y = floorf((info->player.pos_y + cos(info->player.angle) * MOVE_SPEED)
			/ SCALE);
	if (is_possible_to_move(info, futur_x, futur_y))
	{
		info->player.pos_y += cos(info->player.angle) * MOVE_SPEED;
		info->player.pos_x += -sin(info->player.angle) * MOVE_SPEED;
	}
}
