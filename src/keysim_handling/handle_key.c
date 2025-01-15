/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:44:33 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/15 16:21:03 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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

void	handle_key(t_parsing *info)
{
	if (info->keys.up)
		move_player_up(info);
	if (info->keys.down)
		move_player_down(info);
	if (info->keys.left)
		move_player_left(info);
	if (info->keys.right)
		move_player_right(info);
	if (info->keys.rotate_left)
		rotate_player_left(info);
	if (info->keys.rotate_right)
		rotate_player_right(info);
}

int	key_press(int keysym, t_parsing *info)
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
	return (0);
}

int	key_release(int keysym, t_parsing *info)
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
