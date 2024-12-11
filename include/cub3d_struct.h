/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:26:30 by phwang            #+#    #+#             */
/*   Updated: 2024/12/11 15:34:21 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCT_H
# define CUB3D_STRUCT_H

# include "../minilibx-linux/mlx.h"
# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define NO 0
# define SO 1
# define EA 2
# define WE 3

# define ERROR "Error\n"

// error dinput
# define ARG_ERR "This program takes one argument, no more no less"
# define PERM_ERR "Permission denied to read file : "
# define END_MSG ".\n"

// error map
# define ID_ERR "Not enough or too many identifiers NO, SO, EA, WE, F or C"
# define FORMAT_ERR "Wrong file/texture format : must be "
# define FILE_NOT_EXIST "File doesn't exist : "
# define UNKNOWN_FILE_ERR "File access unknown error : "

# define RGB_VALUE "RGB value must be between 0 and 255 and contains 3 values separate by space or coma"

# define MAP_ERR "Map is not valid : "
# define WALL_ERR "must be surrounded by walls"
# define MINIMAL_SIZE_MAP " must be at least 3 lines"
# define PLAYER_NB "must be one player"

// mlx
# define MLX_INIT_ERR "mlx_init() failed"
# define MLX_NEW_WIN_ERR "mlx_new_window() failed"
# define CROSS_MSG "Cross has been clicked !\n"
# define ESC_MSG "(ESC) key has been pressed ! bye\n"

typedef enum e_direction
{
	NORTH = 1,
	WEST = 2,
	EAST = 4,
	SOUTH = 8,
	FLOOR = 16,
	CEILING = 32,
	COMPLETE = 63,
}				t_direction;

typedef struct s_wall
{
	int			id;
	char		*path_to_img;

}				t_wall;

typedef struct s_texture
{
	t_wall		walls[4];
	int			floor_rgb[3];
	int			ceiling_rgb[3];
}				t_texture;

// player[x][y] orientation
typedef struct s_player
{
	int			x;
	int			y;
	char		direction;
	// dsl jsp comment utiliser le enum pour mon code
	t_direction	orientation;
}				t_player;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

typedef struct s_parsing
{
	t_mlx		mlx;
	t_texture	textures;
	t_player	player;
	char		**map;

}				t_parsing;

#endif