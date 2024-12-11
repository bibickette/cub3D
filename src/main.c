/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:55:58 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/11 15:30:20 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	destroy_mlx(t_mlx *mlx)
{
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if (mlx->mlx_ptr)
		mlx_destroy_display(mlx->mlx_ptr);
	if (mlx->mlx_ptr)
		free(mlx->mlx_ptr);
}

int	main(int argc, char **argv)
{
	t_parsing	info_parsing;

	if (!initialization_all(&info_parsing, argc, argv))
		return (1);
	if (!init_mlx(&info_parsing.mlx))
		return (1);
	mlx_key_hook(info_parsing.mlx.win_ptr, &handle_key, &info_parsing);
	mlx_hook(info_parsing.mlx.win_ptr, 17, 0, &cross_exit, &info_parsing);
	mlx_loop(info_parsing.mlx.mlx_ptr);
	return (0);
}
