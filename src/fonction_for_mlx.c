/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_for_mlx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:00:08 by phwang            #+#    #+#             */
/*   Updated: 2024/12/13 15:13:30 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cross_exit(t_parsing *info)
{
	if (info)
	{
		printf("%s", CROSS_MSG);
		apocalypse_parsing(info);
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
		apocalypse_parsing(info);
		destroy_mlx(&info->mlx);
		exit(0);
	}
	draw_player(&info->mlx, &info->player, GREY, REPLACE_BCKGRND);
	if (keysym == XK_z || keysym == XK_Up || keysym == XK_w)
		info->player.pix_y -= 5;
	else if (keysym == XK_s || keysym == XK_Down)
		info->player.pix_y += 5;
	else if (keysym == XK_q || keysym == XK_Left || keysym == XK_a)
		info->player.pix_x -= 5;
	else if (keysym == XK_d || keysym == XK_Right)
		info->player.pix_x += 5;
	return (0);
}

int	display(t_parsing *info)
{
	draw_player(&info->mlx, &info->player, YELLOW, 0);
	mlx_put_image_to_window(info->mlx.mlx_ptr, info->mlx.win_ptr,
		info->mlx.background.mlx_img, 0, 0);
	return (0);
}
