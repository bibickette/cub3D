/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_utils_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 0020/01/08 00:00:00 by 13:53 by ph       #+#    #+#             */
/*   Updated: 2025/01/25 18:20:05 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	move_player_up_bonus(t_parsing *info)
{
	int	futur_x;
	int	futur_y;
	int	add_player_size_x;
	int	add_player_size_y;

	add_player_size_x = 0;
	add_player_size_y = 0;
	if (is_north(info->player.angle))
		add_player_size_y = -(MINI_PLAYER_SIZE / 2) - SECURITY_DISTANCE;
	if (is_south(info->player.angle))
		add_player_size_y = (MINI_PLAYER_SIZE / 2) + SECURITY_DISTANCE;
	if (is_west(info->player.angle, info->ray.pi2, info->ray.pi3))
		add_player_size_x = -(MINI_PLAYER_SIZE / 2) - SECURITY_DISTANCE;
	if (is_east(info->player.angle, info->ray.pi2, info->ray.pi3))
		add_player_size_x = (MINI_PLAYER_SIZE / 2) + SECURITY_DISTANCE;
	futur_x = floorf((info->player.pos_x + add_player_size_x + info->player.d_x)
			/ SCALE);
	futur_y = floorf((info->player.pos_y + add_player_size_y + info->player.d_y)
			/ SCALE);
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
	int	add_player_size_x;
	int	add_player_size_y;

	add_player_size_x = 0;
	add_player_size_y = 0;
	if (is_north(info->player.angle))
		add_player_size_y = -(MINI_PLAYER_SIZE / 2) - SECURITY_DISTANCE;
	if (is_south(info->player.angle))
		add_player_size_y = (MINI_PLAYER_SIZE / 2) + SECURITY_DISTANCE;
	if (is_west(info->player.angle, info->ray.pi2, info->ray.pi3))
		add_player_size_x = -(MINI_PLAYER_SIZE / 2) - SECURITY_DISTANCE;
	if (is_east(info->player.angle, info->ray.pi2, info->ray.pi3))
		add_player_size_x = (MINI_PLAYER_SIZE / 2) + SECURITY_DISTANCE;
	futur_x = floorf((info->player.pos_x - add_player_size_x - info->player.d_x)
			/ SCALE);
	futur_y = floorf((info->player.pos_y - add_player_size_y - info->player.d_y)
			/ SCALE);
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
	int	add_player_size_x;
	int	add_player_size_y;

	add_player_size_x = 0;
	add_player_size_y = 0;
	if (is_north(info->player.angle))
		add_player_size_x = -(MINI_PLAYER_SIZE / 2) - SECURITY_DISTANCE;
	if (is_south(info->player.angle))
		add_player_size_x = (MINI_PLAYER_SIZE / 2) + SECURITY_DISTANCE;
	if (is_west(info->player.angle, info->ray.pi2, info->ray.pi3))
		add_player_size_y = (MINI_PLAYER_SIZE / 2) + SECURITY_DISTANCE;
	if (is_east(info->player.angle, info->ray.pi2, info->ray.pi3))
		add_player_size_y = -(MINI_PLAYER_SIZE / 2) - SECURITY_DISTANCE;
	futur_x = floorf(((info->player.pos_x + add_player_size_x)
				+ sin(info->player.angle) * MOVE_SPEED) / SCALE);
	futur_y = floorf(((info->player.pos_y + add_player_size_y)
				- cos(info->player.angle) * MOVE_SPEED) / SCALE);
	if (is_possible_to_move(info, futur_x, futur_y))
	{
		info->player.pos_x += sin(info->player.angle) * MOVE_SPEED;
		info->player.pos_y += -cos(info->player.angle) * MOVE_SPEED;
	}
}

void	move_player_right_bonus(t_parsing *info)
{
	int	futur_x;
	int	futur_y;
	int	add_player_size_x;
	int	add_player_size_y;

	add_player_size_x = 0;
	add_player_size_y = 0;
	if (is_north(info->player.angle))
		add_player_size_x = (MINI_PLAYER_SIZE / 2) + SECURITY_DISTANCE;
	if (is_south(info->player.angle))
		add_player_size_x = -(MINI_PLAYER_SIZE / 2) - SECURITY_DISTANCE;
	if (is_west(info->player.angle, info->ray.pi2, info->ray.pi3))
		add_player_size_y = -(MINI_PLAYER_SIZE / 2) - SECURITY_DISTANCE;
	if (is_east(info->player.angle, info->ray.pi2, info->ray.pi3))
		add_player_size_y = (MINI_PLAYER_SIZE / 2) + SECURITY_DISTANCE;
	futur_x = floorf(((info->player.pos_x + add_player_size_x)
				- sin(info->player.angle) * MOVE_SPEED) / SCALE);
	futur_y = floorf(((info->player.pos_y + add_player_size_y)
				+ cos(info->player.angle) * MOVE_SPEED) / SCALE);
	if (is_possible_to_move(info, futur_x, futur_y))
	{
		info->player.pos_x += -sin(info->player.angle) * MOVE_SPEED;
		info->player.pos_y += cos(info->player.angle) * MOVE_SPEED;
	}
}
