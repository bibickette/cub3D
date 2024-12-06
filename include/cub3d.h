/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:08:32 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/06 13:32:45 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define ARG_ERR "This program takes one argument, no more no less"
#define PERM_ERR "Permission refusée pour lire le fichier : "
#define END_MSG ".\n"


# define ID_ERR "Not enough or too many identifiers NO, SO, EA, WE, F or C"

typedef enum e_direction
{
	NORTH = 1,
	WEST = 2,
	EAST = 4,
	SOUTH = 8,
	FLOOR = 16,
	CEILING = 32,
}					t_direction;

typedef struct s_texture
{
	int				id;
	char			*path_to_img;
}					t_texture;

typedef struct s_wall
{
	t_texture		north;
	t_texture		south;
	t_texture		east;
	t_texture		west;
}					t_wall;

typedef struct s_floor_ceiling
{
	int				floor_rgb[3];
	int				ceiling_rgb[3];
}					t_floor_ceiling;

typedef struct s_player
{
	int				x;
	int				y;
	t_direction		orientation;
}					t_player;

typedef struct s_parsing
{
	// t_wall walls[4];
	t_wall			walls;
	t_floor_ceiling	floor_ceiling;
	t_player		player;
	char			**map;

}					t_parsing;

// DEBUG

void				print_info(t_parsing *info);

// PARING

// check_args
bool				is_valid_arguments(int argc, char **argv);
bool				is_file_readable(char *file_name);
bool				is_invalid_file_format(char *path, char *format);

// parse_file
bool				is_valid_data(t_parsing *info, char *filename);
// check_texture
int					is_start_with_id(char *line);
bool				is_valid_file_and_rgb(t_parsing *info);

// init_texture
int					start_of_texture(char *line);
int					len_of_texture(char *line);
void				init_data(t_parsing *info, char *line, int ID,
						int texture_len);
void				init_floor_ceiling(t_parsing *info, char *line,
						int ID);

// error.c
void print_error(char *msg, char *arg);

#endif