/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 13:16:29 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/17 17:06:09 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include "cub3d.h"

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

#endif