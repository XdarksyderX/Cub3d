/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: migarci2 <migarci2@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 12:45:52 by migarci2          #+#    #+#             */
/*   Updated: 2024/02/26 12:46:32 by migarci2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static bool	ft_is_wall(double x, double y, t_map *map)
{
	int	map_x;
	int	map_y;

	map_x = (int)(x / TILE_SIZE);
	map_y = (int)(y / TILE_SIZE);
	if (map_x < 0 || map_x >= map->width || map_y < 0 || map_y >= map->height)
		return (true);
	if (map->map[map_y][map_x] == '1')
		return (true);
	return (false);
}

//TRUE: HIT HORIZONTAL | FALSE: HIT VERTICAL
bool	ft_get_hit_point(double *x, double *y, double angle, t_map *map)
{
	double	x_step;
	double	y_step;
	double	x_prev;
	double	y_prev;

	x_prev = *x;
	y_prev = *y;
	x_step = cos(angle) * STEP_SIZE;
	y_step = sin(angle) * STEP_SIZE;
	while (!ft_is_wall(*x, *y, map))
	{
		x_prev = *x;
		y_prev = *y;
		*x += x_step;
		*y += y_step;
	}
	if (fabs(*y - y_prev) < fabs(*x - x_prev))
		return (true);
	else
		return (false);
}
