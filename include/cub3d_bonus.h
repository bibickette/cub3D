/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:16:29 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/25 18:44:52 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3d.h"

// parsing
# define DOOR 'D'
# define DOOR_INT 5
# define DOOR_FILE "textures/door.xpm"
# define IS_DOOR 1 // for raycasting detection door
# define IS_NOT_DOOR 0

// collision
# define SECURITY_DISTANCE 2

bool	is_valid_map_bonus(t_parsing *info);
bool	is_everything_surrounded_bonus(char **map, int last_tab);
bool	init_map_bonus(t_parsing *info, int fd);
bool	is_valid_data_bonus(t_parsing *info, char *filename);
bool	initialization_all_bonus(t_parsing *info, int argc, char **argv);
int		*convert_to_int_tab_bonus(t_parsing *info, char **map);

bool	load_door(t_parsing *info);

int		display_bonus(t_parsing *info);
int		key_release_bonus(int keysym, t_parsing *info);
int		key_press_bonus(int keysym, t_parsing *info);
void	handle_key_bonus(t_parsing *info);

void	move_player_up_bonus(t_parsing *info);
void	move_player_down_bonus(t_parsing *info);
void	move_player_left_bonus(t_parsing *info);
void	move_player_right_bonus(t_parsing *info);

// collision
bool	is_possible_to_move(t_parsing *info, int x, int y);
bool	is_possible_to_move_in_a_way(char **map, int x, int y);
bool	is_north(float angle);
bool	is_south(float angle);
bool	is_east(float angle, float pi2, float pi3);
bool	is_west(float angle, float pi2, float pi3);

// minimap
void	draw_mini_map(t_parsing *info);
void	draw_circle_map(t_parsing *info, int radius, int color);
void	draw_player_arrow(t_parsing *info);
bool	is_on_minimap(int x, int y, int rayon);

// minimap
void	draw_line_on_map(t_parsing *info, t_img img);
void	draw_player_on_minimap(t_parsing *info, unsigned int color);

// raycasting
void	draw_3d_wall_bonus(t_ray *ray, t_parsing *info);
void	raycaster_bonus(t_player *player, t_ray *ray, t_parsing *info);
float	ray_vertical_plan_len_bonus(t_player *player, t_ray *ray, t_parsing *info);
float	ray_horizon_plan_len_bonus(t_player *player, t_ray *ray, t_parsing *info);
void	init_vertical_value_bonus(t_ray *ray, float ray_len);
void	init_horizontal_value_bonus(t_ray *ray, float ray_len);


#endif