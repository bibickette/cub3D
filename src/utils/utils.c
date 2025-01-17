/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 19:16:46 by fanfan            #+#    #+#             */
/*   Updated: 2025/01/17 18:02:13 by phwang           ###   ########.fr       */
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

int	start_of_texture(char *line)
{
	int	i;

	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	i += 2;
	while (line[i] && line[i] == ' ')
		i++;
	return (i);
}

int	len_of_texture(char *line)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	while (line[i] && line[i] == ' ')
		i++;
	while (line[i] && (line[i] != ' ' && line[i] != '\n'))
	{
		i++;
		len++;
	}
	return (len);
}
