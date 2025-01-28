/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:08:32 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/28 16:41:31 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "cub3d_struct.h"

// parsing
bool			initialization_all(t_parsing *info, int argc, char **argv);
bool			is_valid_arguments(int argc, char **argv);
bool			is_valid_data(t_parsing *info, char *filename);
bool			init_texture(t_parsing *info, char *line, int ID,
					int texture_len);
bool			is_valid_file_and_rgb(t_parsing *info);
bool			is_invalid_file_format(char *path, char *format);
bool			is_file_readable(char *file_name);
bool			is_valid_arguments(int argc, char **argv);
int				is_start_with_id(char *line);
int				len_of_texture(char *line);
int				start_of_texture(char *line);
unsigned int	rgb_to_uint(int rgb[3]);

bool			load_texture(t_parsing *info);
void			rgb_mix_colors(int *c_one, int *c_two, int *new_color);

// init_map_player_mlx
bool			init_map(t_parsing *info, int fd);
bool			is_valid_map(t_parsing *info);
bool			check_first_last_line(char **map, int *last_tab);
bool			is_everything_surrounded(char **map, int last_tab);
int				*convert_to_int_tab(t_parsing *info, char **map);

bool			init_player(char **map, t_player *player);
bool			is_player(char c);
bool			init_create_mlx(t_parsing *info);
void			display_intro(void);

// keysim_handling
int				cross_exit(t_parsing *info);
void			escape_exit(t_parsing *info);
void			handle_key(t_parsing *info);
int				key_press(int keysym, t_parsing *info);
int				key_release(int keysym, t_parsing *info);
void			move_player_up(t_parsing *info);
void			move_player_down(t_parsing *info);
void			move_player_left(t_parsing *info);
void			move_player_right(t_parsing *info);
bool			is_north(float angle);
bool			is_south(float angle);
bool			is_east(float angle, float pi2, float pi3);
bool			is_west(float angle, float pi2, float pi3);

// display
int				display(t_parsing *info);

// raycasting
void			raycaster(t_player *player, t_ray *ray, t_parsing *info);
float			ray_horizon_plan_len(t_player *player, t_ray *ray,
					t_parsing *info);
void			init_horizontal_value(t_ray *ray, float ray_len);
float			ray_vertical_plan_len(t_player *player, t_ray *ray,
					t_parsing *info);
void			init_vertical_value(t_ray *ray, float ray_len);
void			draw_3d_wall(t_ray *ray, t_parsing *info);
float			protect_angle_trigo_value(float angle);
float			get_distance(float px, float py, float rx, float ry);
unsigned int	get_backup_color(t_img img, int x, int y);
void			my_mlx_pixel_put(t_img img, int y, int x, unsigned int color);

// utils
void			destroy_mlx(t_mlx *mlx);
void			destroy_info(t_parsing *info);
void			free_n_set_null(char **to_free);
void			free_tab(char **tab);
bool			convert_tab_in_space(char **line);
void			print_error(char *msg, char *arg);

bool			is_white_space_line(char *line);
void			*ft_realloc_map(void *ptr, size_t new_size, size_t old_size);

void			print_player_info(t_player player);
void			print_texture(t_parsing *info);
void			print_map_int(int *map, int max_x, int max_y);
void			print_map(char **map);

#endif