/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_tab_in_space.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:08:31 by phwang            #+#    #+#             */
/*   Updated: 2024/12/18 15:30:46 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static bool	count_tab(char *line, int *nb_tab)
{
	int	i;

	i = -1;
	while (line[++i])
	{
		if (line[i] == '\t')
			(*nb_tab)++;
	}
	if (*nb_tab == 0)
		return (false);
	return (true);
}

static void	replace_tab_by_space(char **line, char **new_line)
{
	int	i;
	int	j;

	j = -1;
	i = -1;
	while ((*line)[++i])
	{
		if ((*line)[i] == '\t')
		{
			(*new_line)[++j] = ' ';
			(*new_line)[++j] = ' ';
			(*new_line)[++j] = ' ';
			(*new_line)[++j] = ' ';
		}
		else
			(*new_line)[++j] = (*line)[i];
	}
	free_n_set_null(line);
	*line = *new_line;
}

// convert les tabs en space pour eviter les pb de visuel a cause des melanges
// et eviter les problemes de deplacements
bool	convert_tab_in_space(char **line)
{
	int		nb_tab;
	char	*new_line;

	nb_tab = 0;
	if (!count_tab(*line, &nb_tab))
		return (true);
	new_line = ft_calloc(sizeof(char), ft_strlen(*line) + nb_tab * 3 + 1);
	if (!new_line)
		return (print_error(MALLOC_ERR, NULL), false);
	replace_tab_by_space(line, &new_line);
	return (true);
}
