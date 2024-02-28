/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 18:49:32 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/28 21:46:18 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "misc.h"
#include "parsing.h"

bool	is_position_valid(t_flood data)
{
	return (data.x >= 0 && data.x
		< data.width && data.y >= 0 && data.y < data.height);
}

void	flood_fill(t_flood data)
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

bool	is_map_fully_enclosed(char **map, int width, int height)
{
	int		*player_coords;
	t_flood	data;

	player_coords = ft_find_player_pos(map);
	if (player_coords[1] == -1 || player_coords[0] == -1)
	{
		free(player_coords);
		return (false);
	}
	data.map = map;
	data.x = player_coords[1];
	data.y = player_coords[0];
	data.width = width;
	data.height = height;
	flood_fill(data);
	free(player_coords);
	return (true);
}
