/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 12:27:23 by phwang            #+#    #+#             */
/*   Updated: 2025/01/28 13:02:50 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

/*chaque tour dimage je reset ces valeurs pour retrouver les bonnes portes*/
void	reset_can_took_door(t_door *door)
{
	door->can_open_door = false;
	door->can_close_door = false;
	door->took_nearest_door_h = false;
	door->took_nearest_door_v = false;
}

/* chaque tour de boucle du raycaster je recalcule comme pour les rayons
sauf que je dois detecter egalement si ya une porte ouverte ou non */
void	reset_is_door(t_door *door)
{
	door->is_door_closed_h = IS_NOT_DOOR;
	door->is_door_closed_v = IS_NOT_DOOR;
	door->is_door_open_h = IS_NOT_DOOR;
	door->is_door_open_v = IS_NOT_DOOR;
}
