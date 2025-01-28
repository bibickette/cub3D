/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   boussole.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 17:02:31 by phwang            #+#    #+#             */
/*   Updated: 2025/01/28 16:43:27 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_north(float angle)
{
	return (angle > PI && angle < 2 * PI);
}

bool	is_south(float angle)
{
	return (angle < PI && angle > 0);
}

bool	is_east(float angle, float pi2, float pi3)
{
	return (angle > pi3 || angle < pi2);
}

bool	is_west(float angle, float pi2, float pi3)
{
	return (angle > pi2 && angle < pi3);
}
