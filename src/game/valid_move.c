/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 16:07:02 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/27 16:18:23 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static bool	ft_in_limits(int map_x, int map_y, t_game *game)
{
	if (!game || !game->map)
		return (false);
	if (map_x < 0 || map_x >= game->map->width
		|| map_y < 0 || map_y >= game->map->height)
		return (false);
	return (true);
}

static bool	check_single_corner(int map_x, int map_y, t_game *game)
{
	if (!ft_in_limits(map_x, map_y, game)
		|| game->map->map[map_y][map_x] == '1')
		return (false);
	return (true);
}

static bool	check_corners(int corners[4][2], t_game *game)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!check_single_corner(corners[i][0], corners[i][1], game))
			return (false);
		i++;
	}
	return (true);
}

bool	ft_is_position_valid(t_game *game, double new_pos[2],
	double width, double height)
{
	int	corners[4][2];

	corners[0][0] = (int)(new_pos[0] / TILE_SIZE);
	corners[0][1] = (int)(new_pos[1] / TILE_SIZE);
	corners[1][0] = (int)((new_pos[0] + width) / TILE_SIZE);
	corners[1][1] = (int)(new_pos[1] / TILE_SIZE);
	corners[2][0] = (int)(new_pos[0] / TILE_SIZE);
	corners[2][1] = (int)((new_pos[1] + height) / TILE_SIZE);
	corners[3][0] = (int)((new_pos[0] + width) / TILE_SIZE);
	corners[3][1] = (int)((new_pos[1] + height) / TILE_SIZE);
	return (check_corners(corners, game));
}
