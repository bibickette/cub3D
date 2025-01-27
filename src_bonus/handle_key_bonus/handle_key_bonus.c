/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:44:33 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/28 00:05:53 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

static void	rotate_player_right(t_parsing *info)
{
	info->player.angle += ROTATE_SPEED;
	info->player.angle = protect_angle_trigo_value(info->player.angle);
	info->player.d_x = cos(info->player.angle) * MOVE_SPEED;
	info->player.d_y = sin(info->player.angle) * MOVE_SPEED;
}

static void	rotate_player_left(t_parsing *info)
{
	info->player.angle -= ROTATE_SPEED;
	info->player.angle = protect_angle_trigo_value(info->player.angle);
	info->player.d_x = cos(info->player.angle) * MOVE_SPEED;
	info->player.d_y = sin(info->player.angle) * MOVE_SPEED;
}

void	handle_key_bonus(t_parsing *info)
{
	int	door_pos;

	if (info->keys.up)
		move_player_up_bonus(info);
	if (info->keys.down)
		move_player_down_bonus(info);
	if (info->keys.left)
		move_player_left_bonus(info);
	if (info->keys.right)
		move_player_right_bonus(info);
	if (info->keys.rotate_left)
		rotate_player_left(info);
	if (info->keys.rotate_right)
		rotate_player_right(info);
	if (info->keys.can_interact_w_door)
	{
		info->keys.can_interact_w_door = false;
		if (info->ray.door.can_open_door)
		{
			info->ray.door.can_open_door = false;
			if (info->map[info->ray.door.door_closed_y][info->ray.door.door_closed_x] == DOOR_CLOSED)
			{
				info->map[info->ray.door.door_closed_y][info->ray.door.door_closed_x] = DOOR_OPEN;
				door_pos = info->ray.door.door_closed_y * info->max_x
					+ info->ray.door.door_closed_x;
				info->int_map[door_pos] = DOOR_OPEN_INT;
			}
		}
		else if(info->ray.door.can_close_door && (((int)(info->ray.player_posy) / SCALE) != info->ray.door.door_open_y
			|| ((int)(info->ray.player_posx) / SCALE) != info->ray.door.door_open_x))
		{
			info->ray.door.can_close_door = false;
			if (info->map[info->ray.door.door_open_y][info->ray.door.door_open_x] == DOOR_OPEN)
			{
				info->map[info->ray.door.door_open_y][info->ray.door.door_open_x] = DOOR_CLOSED;
				door_pos = info->ray.door.door_open_y * info->max_x
					+ info->ray.door.door_open_x;
				info->int_map[door_pos] = DOOR_CLOSE_INT;
			}
		}
	}
}

int	key_press_bonus(int keysym, t_parsing *info)
{
	if (keysym == XK_Escape)
		escape_exit(info);
	if (keysym == XK_z || keysym == XK_w)
		info->keys.up = true;
	else if (keysym == XK_s)
		info->keys.down = true;
	else if (keysym == XK_Left)
		info->keys.rotate_left = true;
	else if (keysym == XK_Right)
		info->keys.rotate_right = true;
	else if (keysym == XK_q || keysym == XK_a)
		info->keys.left = true;
	else if (keysym == XK_d)
		info->keys.right = true;
	else if (keysym == XK_e)
		info->keys.can_interact_w_door = true;
	return (0);
}

int	key_release_bonus(int keysym, t_parsing *info)
{
	if (keysym == XK_z || keysym == XK_w)
		info->keys.up = false;
	else if (keysym == XK_s)
		info->keys.down = false;
	else if (keysym == XK_Left)
		info->keys.rotate_left = false;
	else if (keysym == XK_Right)
		info->keys.rotate_right = false;
	else if (keysym == XK_q || keysym == XK_a)
		info->keys.left = false;
	else if (keysym == XK_d)
		info->keys.right = false;
	return (0);
}
