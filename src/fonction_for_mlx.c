/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_for_mlx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:00:08 by phwang            #+#    #+#             */
/*   Updated: 2024/12/20 11:46:51 by fsalomon         ###   ########.fr       */
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

int	display(t_parsing *info)
{
	draw_player(info, YELLOW, 0);
	mlx_put_image_to_window(info->mlx.mlx_ptr, info->mlx.win_ptr,
		info->mlx.background.mlx_img, 0, 0);
	return (0);
}
