/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:36:47 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/06 11:42:41 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


void print_error(char *msg, char *arg)
{
	ft_putstr_fd(msg, STDERR_FILENO);
	if(arg)
		ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(END_MSG, STDERR_FILENO);
}