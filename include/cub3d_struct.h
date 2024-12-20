/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:26:30 by phwang            #+#    #+#             */
/*   Updated: 2024/12/20 16:51:44 by fsalomon         ###   ########.fr       */
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
# include <math.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define NO 0
# define SO 1
# define EA 2
# define WE 3

# define ERROR "Error\n"

// screen options
# define TITLE "The Legend of on cane moins quavant"
# define SIZE_X 1024
# define SIZE_Y 512

# define PI 3.1415926535
# define PI2 PI/2
# define PI3 3*PI/2
# define DR 0.0174533 // 1 degre en radiant 
# define FOV 60
// draw map handling
# define REPLACE_BCKGRND 1
# define HORIZONTAL 0
# define VERTICAL 1

# define GREY 0x808080
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF00
# define RED 0xFF0000
# define GREEN 0x00FF00
# define BLUE 0x0000FF
# define DARK_BLUE 0x000080

// player
# define MINI_PLAYER_SIZE 10

# define MINI_MAP_SIZE 64 // size of each square
# define MINI_MAP_LOC_X 0 // decalage en pixel position X et Y
# define MINI_MAP_LOC_Y 0

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
# define MLX_IMG_ERR "mlx_new_image() failed"
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

typedef struct s_ray
{
	float	arc_tan;
	float	tan;
	int			r;
	//permet de calculer de trouver quelle case du tableau de map on est
	int			mx;
	int			my;
	int			mp;
	// pour moi cest le mur sur lequel je suis
	int			dof;
	
	//donc cque jcomprends c que r_x r_y
	// cest les coordonnées finales du rayon
	float		rx;
	float		ry;
	
	float		xo;
	float		yo;
	
	float		angle;
	int player_posx;
	int player_posy;
}				t_ray;

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

	int			last_pos_x;
	int			last_pos_y;
	float		pos_x;
	float		pos_y;
	float		d_x;
	float		d_y;
	float angle; // il est set lors de linit du player

}				t_player;
typedef struct s_image
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		background;
	t_img		backup;
	t_img		player;

}				t_mlx;

typedef struct s_parsing
{
	t_mlx		mlx;
	t_texture	textures;
	t_player	player;
	t_ray		ray;
	char		**map;
	int			*int_map;
	int			max_x;
	int			max_y;

}				t_parsing;

#endif