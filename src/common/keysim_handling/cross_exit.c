/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cross_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:41:10 by phwang            #+#    #+#             */
/*   Updated: 2025/01/28 16:40:43 by phwang           ###   ########.fr       */
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

void	escape_exit(t_parsing *info)
{
	printf("%s", ESC_MSG);
	destroy_info(info);
	destroy_mlx(&info->mlx);
	exit(0);
}
