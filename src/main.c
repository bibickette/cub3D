/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:55:58 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/11 14:18:29 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void destroy_mlx(t_mlx *mlx)
{
	if(mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	if(mlx->mlx_ptr)
		mlx_destroy_display(mlx->mlx_ptr);
	if(mlx->mlx_ptr)
		free(mlx->mlx_ptr);
}

bool init_mlx(t_mlx *mlx)
{
	// mlx->mlx_ptr = 0;
	// mlx->win_ptr = 0;
	// mlx->mlx_ptr = mlx_init();
	// if(!mlx->mlx_ptr)
	// 	return (print_error(MLX_INIT_ERR, NULL), false);
	// mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, 500, 500, "The Legend of pour linstant jvais caner");
	// if(!mlx->win_ptr)
	// 	return (print_error(MLX_NEW_WIN_ERR, NULL), false);
	// return (true);

	
	void *mlx_ptr;
	void *win_ptr;

	mlx_ptr = 0;
	win_ptr = 0;
	mlx_ptr = mlx_init();
	if(!mlx_ptr)
		return (print_error(MLX_INIT_ERR, NULL), false);
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "The Legend of pour linstant jvais caner");
	if(!win_ptr)
		return (print_error(MLX_NEW_WIN_ERR, NULL), false);
	return (true);
}

int	main(int argc, char **argv)
{
	t_parsing	info_parsing;
	// t_mlx mlx_strct;
	void *mlx_ptr;
	void *win_ptr;
	
	if (!initialization_all(&info_parsing, argc, argv))
		return (1); 
	mlx_ptr = 0;
	win_ptr = 0;
	mlx_ptr = mlx_init();
	if(!mlx_ptr)
		return (print_error(MLX_INIT_ERR, NULL), false);
	win_ptr = mlx_new_window(mlx_ptr, 500, 500, "The Legend of pour linstant jvais caner");
	if(!win_ptr)
		return (print_error(MLX_NEW_WIN_ERR, NULL), false);
	// return (true);
	// init_mlx(&mlx_strct);
	printf("Hello, World!\n");
	mlx_hook(win_ptr, 17, 0, &cross_exit, &info_parsing);
	mlx_loop(mlx_ptr);
	apocalypse_parsing(&info_parsing);
	mlx_destroy_window(mlx_ptr, win_ptr);
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
	// destroy_mlx(&mlx_strct);
	return (0);
}
