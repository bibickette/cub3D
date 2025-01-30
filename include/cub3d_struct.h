/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 16:26:30 by phwang            #+#    #+#             */
/*   Updated: 2025/01/30 12:49:11 by fsalomon         ###   ########.fr       */
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

# define FRAME_TIME 16.67 // 60fps

# define NO 0
# define SO 1
# define EA 2
# define WE 3

# define NO_SIGN 42 // quand dans le tab int ya un vide

# define ERROR "Error\n"

// screen options
# define TITLE "The Legend of The Cherry Blossom House"
// la taille size X doit etre un multiple de FOV
// si on veut que ca couvre tout lecran
# define SIZE_X 1024
# define SIZE_Y 512

# define PI 3.1415926535
# define FOV 60.00000

# define MOVE_SPEED 2.5
# define ROTATE_SPEED 0.06

# define TEXTURE_SIZE 128.0000f
# define SCALE 32
// draw map handling
# define NO_REPLACE 0
# define REPLACE_BCKGRND 1
# define HORIZONTAL 0
# define VERTICAL 1

// for minimap
# define RESET_COLOR "\033[0m"
# define RED 0x420000
# define RED_ANSI "\033[38;2;66;0;0m"
# define PINK 0xE0A59F
# define PINK_ANSI "\033[38;2;224;165;159m"
# define OTHER_PINK 0xFF6987 // pour le faisceau de vision
# define NUDE 0xfce7cd
# define NUDE_ANSI "\033[38;2;252;231;205m"
# define WHITE 0xFFFFFF
// collision
# define SECURITY_DISTANCE 2
// sprite
# define BIG_HEART 32
# define SMALL_HEART 16
# define FIRST_PART 48
# define SECOND_PART 96
# define BIG_HEART_XPM "textures/bigheart.xpm"
# define SMALL_HEART_XPM "textures/heart.xpm"
# define HEART_GAP 16
# define NB_OF_HEARTS 10
// player
# define MINI_PLAYER_SIZE 4
// size of each square and have to be the size of texture
// plus les valeurs sont grandes plus on avance / tourne vite
# define MINI_MAP_SIZE 16
# define MINI_MAP_CENTER 74
# define MINI_MAP_RAY 64
# define MINI_MAP_BORDER 4
# define POS_X 1
# define POS_Y 0
# define PLAYER_SIZE_MINIMAP 4            // Longueur de la flèche
# define PLAYER_ANGLE_WIDTH 0.39269908169 // Largeur en radian PI/ 8

// error dinput
# define ARG_ERR "This program takes one argument, no more no less"
# define PERM_ERR "Permission denied to read file : "
# define END_MSG ".\n"

// error map
# define ID_ERR "Not enough or too many identifiers NO, SO, EA, WE, F or C"
# define FORMAT_ERR "Wrong file/texture format : must be "
# define FILE_NOT_EXIST "File doesn't exist : "
# define UNKNOWN_FILE_ERR "File access unknown error : "
# define IDPLC_ERR "Identifier must be before the map"

# define RGB_VALUE "RGB value must be between 0 and 255 \
and contains 3 values separate by space or coma"

# define MAP_ERR "Map is not valid : "
# define WALL_ERR "must be surrounded by walls"
# define MINIMAL_SIZE_MAP " must be at least 3 lines"
# define PLAYER_NB "must be one player"
# define EMPTY_LINE "Map can't contain empty line"
# define NO_MAP "No map found"
# define LETTER_ERR "Only digits are accepted in RGB"
# define COMA_ERR "Only 2 comas accepted"
# define NB_VALUE_RGB_ERR "Only 3 RGB values are accepted"
# define CHAR_ERR "Only 0, 1, N, S, E, W and space are accepted"

// mlx
# define MLX_INIT_ERR "mlx_init() failed"
# define MLX_NEW_WIN_ERR "mlx_new_window() failed"
# define MLX_IMG_ERR "mlx_new_image() failed"
# define MLX_GET_DATA_ADDR_ERR "mlx_get_data_addr() failed"
# define MLX_FILE_TO_IMG_ERR "mlx_xpm_file_to_image() failed : "
# define CROSS_MSG "Cross has been clicked !\n"
# define ESC_MSG "(ESC) key has been pressed ! bye\n"
# define SCREEN_SIZE_ERR "SIZE_X or SIZE_Y is bigger than screen size"
# define IMG_SIZE_ERR "Image size is not 64x64 :"

typedef enum e_direction
{
	NORTH = 1,
	WEST = 2,
	EAST = 4,
	SOUTH = 8,
	FLOOR = 16,
	CEILING = 32,
	COMPLETE = 63,
}					t_direction;

/*
mx et my sont les coordonnées de la case de la map dans laquelle on est.
mp est lindex pour notre map int calculer grace a mx et my.
dof = degree of freedom,
	combien de pas peut on faire avant les limites de la map.
rx et ry sont les coordonnées finales du rayon.
xo et yo sont les valeurs d'incrementation pour avancer
jusqua la prochaine case de la map.
arc_tan est la tangente de l'angle du rayon.
angle est l'angle du rayon.	int width;
	int height;yon a dabord frappe
un mur horizontaement ou verticalement.
 */

typedef struct s_player_arrow
{
	int				delta_x;
	int				delta_y;
	int				step_x;
	int				step_y;
}					t_player_arrow;

typedef struct s_door
{
	bool			can_open_door;
	int				is_door_closed_h;
	int				is_door_closed_v;
	int				h_door_closed_x;
	int				h_door_closed_y;
	int				v_door_closed_x;
	int				v_door_closed_y;
	int				door_closed_x;
	int				door_closed_y;

	bool			can_close_door;
	bool			took_nearest_door_h;
	bool			took_nearest_door_v;
	float			distance_to_open_h;
	float			distance_to_open_v;
	int				is_door_open_h;
	int				is_door_open_v;
	int				h_door_open_x;
	int				h_door_open_y;
	int				v_door_open_x;
	int				v_door_open_y;
	int				door_open_x;
	int				door_open_y;

	unsigned int	door_closed_color;
	unsigned int	door_open_color;
}					t_door;
typedef struct s_ray
{
	double			angle;
	double			rad_value;
	double			pi2;
	double			pi3;
	float			arc_tan;
	float			tan;
	float			hy;
	float			hx;
	float			vy;
	float			vx;
	float			xo;
	float			yo;
	float			player_posx;
	float			player_posy;
	float			distance;
	float			height_l;
	float			base_l;
	float			cos_angle;
	float			wall_hit;
	int				id;
	int				start_x;
	int				start_y;
	int				dist_to_wall;
	int				r;
	int				map_x;
	int				map_y;
	int				map_pos;
	t_door			door;
}					t_ray;

typedef struct s_image
{
	void			*mlx_img;
	char			*addr;
	int				*int_addr;
	int				bpp;
	int				line_len;
	int				endian;
}					t_img;

typedef struct s_wall
{
	int				id;
	char			*path_to_img;
	t_img			img;
}					t_wall;

typedef struct s_texture
{
	t_wall			walls[4];
	int				floor_rgb[3];
	int				ceiling_rgb[3];
	unsigned int	floor_color;
	unsigned int	ceiling_color;
}					t_texture;

// player[y][x] orientation
typedef struct s_player
{
	float			pos_x;
	float			pos_y;
	float			d_x;
	float			d_y;
	float			angle;
}					t_player;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			background;
	t_img			background2;
	t_img			*current_background;
	t_img			player;

}					t_mlx;

typedef struct keys
{
	bool			up;
	bool			down;
	bool			left;
	bool			right;
	bool			rotate_left;
	bool			rotate_right;
	bool			want_interact_w_door;
}					t_keys;

typedef struct s_parsing
{
	t_mlx			mlx;
	t_texture		textures;
	t_player		player;
	t_ray			ray;
	char			**map;
	int				*int_map;
	int				max_x;
	int				max_y;
	int				nb_frame;
	t_keys			keys;

	t_img			door;
	t_img			hearts[96];
	int				hearts_frame;
	int				heart_size;
	t_player_arrow	arrow;
}					t_parsing;

#endif