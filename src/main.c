/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:55:58 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/06 11:17:14 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_info(t_parsing_data *info)
{
	printf("%s\n", info->walls.north.path_to_img);
	printf("%s\n", info->walls.south.path_to_img);
	printf("%s\n", info->walls.east.path_to_img);
	printf("%s\n", info->walls.west.path_to_img);
}

int	main(int argc, char **argv)
{
	t_parsing_data	info_parsing;

	if (!is_valid_arguments(argc, argv))
		return (0);
	printf("This arg is valid, now let's check inside the file.cub \n");
	if (!is_valid_data(&info_parsing, argv[1]))
	{
		print_info(&info_parsing);
		printf("Error\n");
		return (0);
	}
	printf("Hello, World!\n");
	return (0);
}
