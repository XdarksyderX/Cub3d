/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_enclosed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:49:32 by migarci2          #+#    #+#             */
/*   Updated: 2024/03/04 21:34:09 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "misc.h"
#include "parsing.h"

static bool	is_position_valid(t_flood data)
{
	return (data.x >= 0 && data.x
		< data.width && data.y >= 0 && data.y < data.height);
}

static void	flood_fill(t_flood data)
{
	if (!is_position_valid(data) || data.map[data.y][data.x] != OPEN)
		return ;
	data.map[data.y][data.x] = FILLED;
	flood_fill((t_flood){data.map, data.x + 1, data.y,
		data.width, data.height});
	flood_fill((t_flood){data.map, data.x - 1, data.y,
		data.width, data.height});
	flood_fill((t_flood){data.map, data.x, data.y + 1,
		data.width, data.height});
	flood_fill((t_flood){data.map, data.x, data.y - 1,
		data.width, data.height});
}

static bool	check_map_borders(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		if (map[i][0] == OPEN || map[i][width - 1] == OPEN)
			return (false);
		i++;
	}
	j = 0;
	while (j < width)
	{
		if (map[0][j] == OPEN || map[height - 1][j] == OPEN)
			return (false);
		j++;
	}
	return (true);
}

static bool	is_player_on_edge(int *player_coords, int width, int height)
{
	if (player_coords[0] == 0
		|| player_coords[0] == height - 1
		|| player_coords[1] == 0 || player_coords[1] == width - 1)
		return (true);
	return (false);
}

bool	is_map_fully_enclosed(char **original_map, int width, int height)
{
	char	**map;
	int		*player_coords;
	t_flood	data;
	bool	is_valid;

	player_coords = ft_find_player_pos(original_map);
	if (player_coords[0] == -1 || player_coords[1] == -1
		|| is_player_on_edge(player_coords, width, height))
	{
		free(player_coords);
		return (false);
	}
	map = (char **)ft_matrix_dup((void **)original_map);
	data.map = map;
	data.x = player_coords[1];
	data.y = player_coords[0];
	data.width = width;
	data.height = height;
	flood_fill(data);
	is_valid = check_map_borders(map, width, height);
	ft_free_matrix((void **)map, height);
	free(player_coords);
	return (is_valid);
}
