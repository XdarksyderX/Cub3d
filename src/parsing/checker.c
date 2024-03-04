/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:34:05 by migarci2          #+#    #+#             */
/*   Updated: 2024/03/04 21:13:08 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static bool	ft_check_textures_files(t_config *config)
{
	if (!ft_file_exists(config->north_texture_path))
	{
		ft_putstr_fd("Error\nNorth texture file not found\n", STDERR_FILENO);
		return (false);
	}
	if (!ft_file_exists(config->south_texture_path))
	{
		ft_putstr_fd("Error\nSouth texture file not found\n", STDERR_FILENO);
		return (false);
	}
	if (!ft_file_exists(config->east_texture_path))
	{
		ft_putstr_fd("Error\nEast texture file not found\n", STDERR_FILENO);
		return (false);
	}
	if (!ft_file_exists(config->west_texture_path))
	{
		ft_putstr_fd("Error\nWest texture file not found\n", STDERR_FILENO);
		return (false);
	}
	return (true);
}

static bool	ft_check_fully_enclosed(t_config *config)
{
	char	**map;

	if (!config || !config->map)
		return (false);
	map = (char **)ft_matrix_dup((void **)config->map);
	if (!map)
		return (false);
	if (!is_map_fully_enclosed(map, config->cols, config->rows))
	{
		ft_free_matrix((void **)map, config->rows);
		return (false);
	}
	ft_free_matrix((void **)map, config->rows);
	return (true);
}

int	ft_count_chars(char **map, char *chars)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	if (!map)
		return (0);
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_strchr(chars, map[i][j]) != NULL)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

bool	ft_check_config(t_config *config)
{
	if (!ft_valid_color(config->floor_color)
		|| !ft_valid_color(config->ceiling_color))
	{
		ft_putstr_fd("Error\nInvalid color error\n", STDERR_FILENO);
		return (false);
	}
	if (!config->map)
	{
		ft_putstr_fd("Error\nMap error\n", STDERR_FILENO);
		return (false);
	}
	if (ft_count_chars(config->map, "NSWE") != 1)
	{
		ft_putstr_fd("Error\nInvalid player error\n", STDERR_FILENO);
		return (false);
	}
	if (!ft_check_fully_enclosed(config))
	{
		ft_putstr_fd("Error\nConfiguration error\n", STDERR_FILENO);
		return (false);
	}
	return (ft_check_textures_files(config));
}
