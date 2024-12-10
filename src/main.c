/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:55:58 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/10 14:05:30 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_info(t_parsing *info)
{
	ft_memset(info, 0, sizeof(t_parsing));
	ft_memset(info->textures.floor_rgb, -1, sizeof(int) * 3);
	ft_memset(info->textures.ceiling_rgb, -1, sizeof(int) * 3);
}

int	main(int argc, char **argv)
{
	t_parsing	info_parsing;

	init_info(&info_parsing);
	if (!is_valid_arguments(argc, argv))
		return (1);
	if (!is_valid_data(&info_parsing, argv[1]))
		return (apocalypse_parsing(&info_parsing), 1);
	printf("Hello, World!\n");
	apocalypse_parsing(&info_parsing);
	return (0);
}
