/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:16:29 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/30 12:28:37 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3d.h"

# define CHAR_ERR_BONUS "Only 0, 1, N, S, E, W, D and space are accepted"

# define DOOR_FILE "textures/door.xpm"
# define DOOR_COLOR 0x91524F // need to be removed

# define DOOR_CLOSED 'D'
# define DOOR_OPEN 'O'
# define DOOR_CLOSED_INT 5
# define DOOR_OPEN_INT 6
# define DISTANCE_TO_OPEN_DOOR 20
# define DISTANCE_TO_CLOSE_DOOR 32 // (SCALE) for now

# define IS_DOOR_HORIZONTAL 1 // for raycasting detection door
# define IS_DOOR_VERTICAL 2
# define IS_NOT_DOOR 0

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
void	handle_open_close_door(t_parsing *info, t_door *door);

// collision
bool	is_possible_to_move(t_parsing *info, int x, int y);
bool	is_possible_to_move_in_a_way(char **map, int x, int y);

// minimap
void	draw_mini_map(t_parsing *info);
void	draw_circle_map(t_parsing *info, int radius, int color);
void	draw_player_arrow(t_parsing *info);
bool	is_on_minimap(int x, int y, int rayon);

// minimap
void	draw_line_on_map(t_parsing *info, t_img img);
void	draw_player_on_minimap(t_parsing *info, unsigned int color);

// raycasting
void	draw_3d_wall_bonus(t_parsing *info, t_ray *ray);
void	raycaster_bonus(t_player *player, t_ray *ray, t_parsing *info);
float	ray_vertical_plan_len_bonus(t_player *player, t_ray *ray,
			t_parsing *info);
float	ray_horizon_plan_len_bonus(t_player *player, t_ray *ray,
			t_parsing *info);
void	init_vertical_value_bonus(t_ray *ray, float ray_len);
void	init_horizontal_value_bonus(t_ray *ray, float ray_len);

// door handling
bool	is_door_closed_or_wall(t_parsing *info, t_ray *ray);
float	door_closed_handling_h(t_parsing *info, t_ray *ray);
float	door_closed_handling_v(t_parsing *info, t_ray *ray);
void	door_open_handling_h(t_parsing *info, t_ray *ray);
void	door_open_handling_v(t_parsing *info, t_ray *ray);
void	init_door_open_h(t_ray *ray);
void	init_door_open_v(t_ray *ray);
void	init_door_closed_h(t_ray *ray, float ray_len);
void	init_door_closed_v(t_ray *ray, float ray_len);
void	reset_is_door(t_door *door);
void	reset_can_took_door(t_door *door);

// sprite
bool	load_sprite(t_parsing *info);
void	draw_sprite(t_parsing *info, int gap_x);
void	draw_animated_heart(t_parsing *info, int nb_of_hearts);
#endif