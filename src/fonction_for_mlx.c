/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_for_mlx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:00:08 by phwang            #+#    #+#             */
/*   Updated: 2024/12/23 18:34:31 by phwang           ###   ########.fr       */
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
	draw_player(info, YELLOW, NO_REPLACE);
	mlx_put_image_to_window(info->mlx.mlx_ptr, info->mlx.win_ptr,
		info->mlx.background.mlx_img, 0, 0);
	return (0);
}
