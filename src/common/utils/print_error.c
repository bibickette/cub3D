/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fanfan <fanfan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:36:47 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/07 17:27:32 by fanfan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	print_error(char *msg, char *arg)
{
	ft_putstr_fd(ERROR, STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	if (arg)
		ft_putstr_fd(arg, STDERR_FILENO);
	ft_putstr_fd(END_MSG, STDERR_FILENO);
}
