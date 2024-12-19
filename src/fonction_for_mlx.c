/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_for_mlx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:00:08 by phwang            #+#    #+#             */
/*   Updated: 2024/12/19 14:39:57 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cross_exit(t_parsing *info)
{
	if (info)
	{
		printf("%s", CROSS_MSG);
		destroy_info(info);
		destroy_mlx(&info->mlx);
		exit(0);
	}
	return (0);
}

int	handle_key(int keysym, t_parsing *info)
{
	if (keysym == XK_Escape)
	{
		printf("%s", ESC_MSG);
		destroy_info(info);
		destroy_mlx(&info->mlx);
		exit(0);
	}
	info->player.last_pos_x = info->player.pos_x;
	info->player.last_pos_y = info->player.pos_y;
	draw_player(info, GREY, REPLACE_BCKGRND);
	if (keysym == XK_z || keysym == XK_Up || keysym == XK_w)
	{
		info->player.pos_x += info->player.d_x ;
		info->player.pos_y += info->player.d_y ;
	}
	else if (keysym == XK_s || keysym == XK_Down)
	{
		info->player.pos_x -= info->player.d_x ;
		info->player.pos_y -= info->player.d_y ;
	}
	else if (keysym == XK_q || keysym == XK_Left || keysym == XK_a)
	{
		info->player.angle -= 0.01;
		if (info->player.angle < 0)
			info->player.angle += 2 * PI;
		info->player.d_x = cos(info->player.angle) * 5;
		info->player.d_y = sin(info->player.angle)* 5 ;
	}
	else if (keysym == XK_d || keysym == XK_Right)
	{
		info->player.angle += 0.01;
		if (info->player.angle > 2 * PI)
			info->player.angle -= 2 * PI;
		info->player.d_x = cos(info->player.angle) * 5;
		info->player.d_y = sin(info->player.angle) * 5;
	}
	return (0);
}

int	display(t_parsing *info)
{
	draw_player(info, YELLOW, 0);
	mlx_put_image_to_window(info->mlx.mlx_ptr, info->mlx.win_ptr,
		info->mlx.background.mlx_img, 0, 0);
	return (0);
}
