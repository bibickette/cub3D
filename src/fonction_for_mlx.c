/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fonction_for_mlx.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:00:08 by phwang            #+#    #+#             */
/*   Updated: 2024/12/11 15:33:47 by phwang           ###   ########.fr       */
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
	return (0);
}
