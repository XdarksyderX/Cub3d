/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:34:05 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/26 10:55:45 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

static void	assign_player(int *pos, int i, int j, char **map)
{
	pos[0] = i;
	pos[1] = j;
	pos[2] = map[i][j];
}

int	*ft_find_player_pos(char **map)
{
	int	*pos;
	int	i;
	int	j;

	pos = (int *)malloc(sizeof(int) * 3);
	if (!pos)
		return (NULL);
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\0')
		{
			if (ft_strchr("NSWE", map[i][j]) != NULL)
			{
				assign_player(pos, i, j, map);
				return (pos);
			}
			j++;
		}
		i++;
	}
	free(pos);
	return (NULL);
}

int	ft_count_chars(char **map, char *chars)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
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
	char	**map;

	if (!ft_valid_color(config->floor_color)
		|| !ft_valid_color(config->ceiling_color))
	{
		ft_putstr_fd("Error\nConfiguration error\n", STDERR_FILENO);
		return (false);
	}
	if (ft_count_chars(config->map, "NSWE") != 1)
	{
		ft_putstr_fd("Error\nConfiguration error\n", STDERR_FILENO);
		return (false);
	}
	map = (char **) ft_matrix_dup((void **)config->map);
	if (!is_map_fully_enclosed(map, config->cols, config->rows))
	{
		ft_putstr_fd("Error\nConfiguration error\n", STDERR_FILENO);
		return (false);
	}
	free(map);
	return (true);
}
