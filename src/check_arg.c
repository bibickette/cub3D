/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsalomon <fsalomon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:56:11 by fsalomon          #+#    #+#             */
/*   Updated: 2024/12/06 12:08:21 by fsalomon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	is_invalid_file_format(char *path, char *format)
{
	int	len;
	int	i;

	len = ft_strlen(path);
	i = 0;
	while (path[i] != '.')
		i++;
	if (ft_strncmp(format, &path[len - 4], 4))
	{
		printf("Wrong file format, file format must be %s \n", format);
		return (true);
	}
	return (false);
}

bool	is_file_readable(char *file_name)
{
	if (access(file_name, R_OK) == 0)
		return (true);
	if (errno == EACCES)
		print_error(PERM_ERR, file_name);
	// printf("Permission refusée pour lire le fichier '%s'.\n", file_name);
	else if (errno == ENOENT)
		printf("Le fichier '%s' n'existe pas.\n", file_name);
	else
		printf("Erreur inconnue lors de l'accès au fichier '%s'.\n", file_name);
	return (false);
}

bool	is_valid_arguments(int argc, char **argv)
{
	if (argc != 2)
		return (print_error(ARG_ERR, NULL), false);
	if (is_invalid_file_format(argv[1], ".cub"))
		return (false);
	return (is_file_readable((argv[1])));
}
