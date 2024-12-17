/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:08:32 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/17 14:57:29 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d_struct.h"

// DEBUG
// print debug
void			print_map(char **map);
void			print_texture(t_parsing *info);
void			print_player_info(t_player player);

// PARSING
// initialization
bool			initialization_all(t_parsing *info, int argc, char **argv);
bool			init_create_mlx(t_parsing *info);

// check_args
bool			is_valid_arguments(int argc, char **argv);
bool			is_file_readable(char *file_name);
bool			is_invalid_file_format(char *path, char *format);

// parse_file
bool			is_valid_data(t_parsing *info, char *filename);

// check_texture
int				is_start_with_id(char *line);
bool			is_valid_file_and_rgb(t_parsing *info);

// get_map
bool			get_map(t_parsing *info, int fd);
bool			convert_tab_in_space(char **line);

// is valid map
bool			is_valid_map(t_parsing *info);
bool			check_first_last_line(char **map, int *last_tab);
bool			is_everything_surrounded(char **map, int last_tab);
void			create_corner_walls(char **map, int last_tab);
bool			init_player(char **map, t_player *player);
bool			is_player(char c);

// init_texture
int				start_of_texture(char *line);
int				len_of_texture(char *line);
void			init_data(t_parsing *info, char *line, int ID, int texture_len);
void			init_floor_ceiling(t_parsing *info, char *line, int ID);

// error.c
void			print_error(char *msg, char *arg);

// free
void			destroy_info(t_parsing *info);
void			destroy_mlx(t_mlx *mlx);
void			free_n_set_null(char *to_free);
void			free_tab(char **tab);

// utils
void			*ft_realloc_map(void *ptr, size_t new_size, size_t old_size);
bool			is_white_space_line(char *line);

// MLX HANDLING
int				cross_exit(t_parsing *info);
int				handle_key(int keysym, t_parsing *info);
void			destroy_mlx(t_mlx *mlx);
int				display(t_parsing *info);

// draw map _n player
void			draw_player(t_parsing *info, unsigned int color, int replace);
void			draw_map(t_parsing *info);
void			my_mlx_pixel_put(t_img img, int y, int x, unsigned int color);
unsigned int	get_backup_color(t_img img, int x, int y);

// draw line
void			draw_line_on_map(t_parsing *info, t_img img);
void	draw_mini_line(t_parsing *info, unsigned int color,
		int replace);

// background
bool			create_background(t_mlx *mlx);
bool			create_backup(t_mlx *mlx);

#endif