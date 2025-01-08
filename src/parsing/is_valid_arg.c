/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: phwang <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 13:56:11 by fsalomon          #+#    #+#             */
/*   Updated: 2025/01/08 15:31:08 by phwang           ###   ########.fr       */
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
		return (print_error(FORMAT_ERR, format), true);
	return (false);
}

bool	is_file_readable(char *file_name)
{
	if (access(file_name, R_OK) == 0)
		return (true);
	if (errno == EACCES)
		print_error(PERM_ERR, file_name);
	else if (errno == ENOENT)
		print_error(FILE_NOT_EXIST, file_name);
	else
		print_error(UNKNOWN_FILE_ERR, file_name);
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
