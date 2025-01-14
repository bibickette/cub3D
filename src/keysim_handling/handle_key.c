/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_key.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 11:44:33 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/14 10:05:20 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	escape_exit(t_parsing *info)
{
	printf("%s", ESC_MSG);
	destroy_info(info);
	destroy_mlx(&info->mlx);
	exit(0);
}

static void	rotate_player_right(t_parsing *info)
{
	info->player.angle += 0.1;
	info->player.angle = protect_angle_trigo_value(info->player.angle);
	info->player.d_x = cos(info->player.angle) * 5;
	info->player.d_y = sin(info->player.angle) * 5;
}

static void	rotate_player_left(t_parsing *info)
{
	info->player.angle -= 0.1;
	info->player.angle = protect_angle_trigo_value(info->player.angle);
	info->player.d_x = cos(info->player.angle) * 5;
	info->player.d_y = sin(info->player.angle) * 5;
}

int	handle_key(int keysym, t_parsing *info)
{
	if (keysym == XK_Escape)
		escape_exit(info);
	info->player.last_pos_x = info->player.pos_x;
	info->player.last_pos_y = info->player.pos_y;
	raycaster(&info->player, &info->ray, info, REPLACE_BCKGRND);
	if (keysym == XK_z || keysym == XK_Up || keysym == XK_w)
		move_player_up(info);
	else if (keysym == XK_s || keysym == XK_Down)
		move_player_down(info);
	else if (keysym == XK_Left)
		rotate_player_left(info);
	else if (keysym == XK_Right)
		rotate_player_right(info);
	else if (keysym == XK_q || keysym == XK_a)
		move_player_left(info);
	else if (keysym == XK_d)
		move_player_right(info);
	display(info);
	return (0);
}
