/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:16:46 by fanfan            #+#    #+#             */
/*   Updated: 2024/12/10 14:05:04 by phwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_realloc_map(void *ptr, size_t new_size, size_t old_size)
{
	void	*new_ptr;

	new_size += sizeof(char *);
	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}
	if (ptr == NULL)
		return (malloc(new_size));
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (print_error(MALLOC_ERR, NULL), NULL);
	ft_memcpy(new_ptr, ptr, old_size);
	free(ptr);
	return (new_ptr);
}

bool	is_white_space_line(char *line)
{
	int	i;

	i = 0;
	while (line && line[i])
	{
		if (!ft_is_white_space(line[i]))
			return (false);
		i++;
	}
	return (true);
}
